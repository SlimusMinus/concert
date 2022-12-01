#include "musical_instrument.h"

void musical_instrument::grafik()
{
	a = rand() % 30 + 1;
	b = rand() % 30 + 1;
	c = rand() % 15 + 1;
	GotoXY(a, b);
	SetColor(c, 0);
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}


void stringed_instruments::Play_in(string instr)
{
	cout << "Playing stringed instruments " << instr << endl;
}

void harp::Play()
{
	Play_in("harp");
	PlaySound(TEXT("arfa 2 sec.wav"), NULL, SND_ASYNC | SND_LOOP);
	Sleep(2000);
}

void bass_guitar::Play()
{
	Play_in("bass_guitar");
	PlaySound(TEXT("bas-gitara-3 sec.wav"), NULL, SND_ASYNC | SND_LOOP);
	Sleep(3000);
}

void violin::Play()
{
	Play_in("violin");
	PlaySound(TEXT("violonchel 3 sec.wav"), NULL, SND_ASYNC | SND_LOOP);
	Sleep(3000);
}

void wind_instruments::Play_wi(string instr)
{
	cout << "Playing wind instrument " << instr << endl;
}

void trumpet::Play()
{
	Play_wi("trumpet");
	PlaySound(TEXT("trumpet 2 sec.wav"), NULL, SND_ASYNC | SND_LOOP);
	Sleep(2000);
}

void trombone::Play()
{
	Play_wi("trombone");
	PlaySound(TEXT("trombon_3_sec.wav"), NULL, SND_ASYNC | SND_LOOP);
	Sleep(3000);
}

void horn::Play()
{
	Play_wi("horn");
	PlaySound(TEXT("gorn 5 sec.wav"), NULL, SND_ASYNC | SND_LOOP);
	Sleep(5000);
}
