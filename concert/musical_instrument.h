#include <iomanip>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <MMSystem.h>
#pragma comment (lib, "winmm")
using namespace std;

void SetColor(int text, int background);
void GotoXY(int X, int Y);

class musical_instrument
{
protected:
	int a, b, c;
public:
	virtual void Play() = 0;	
	void grafik();
};

class stringed_instruments : public musical_instrument
{
public:
	void Play_in(string instr);
};

class harp : public stringed_instruments
{
public:
	void Play();
};

class bass_guitar : public stringed_instruments
{
public:
	void Play();
};

class violin : public stringed_instruments
{
public:
	void Play();
};

class wind_instruments : public musical_instrument
{
public:
	void Play_wi(string instr);
};

class trumpet : public wind_instruments
{
public:
	void Play();
};

class trombone : public wind_instruments
{
public:
	void Play();
};

class horn : public wind_instruments
{
public:
	void Play();
};

class orchestra : public harp, public bass_guitar, 
	public violin, public trumpet, public trombone, 
	public horn
{
	musical_instrument** m_i = new musical_instrument * [6];
	const int size = 10;
public:
	orchestra()
	{
		m_i[0] = new harp;
		m_i[1] = new bass_guitar;
		m_i[2] = new violin;
		m_i[3] = new trumpet;
		m_i[4] = new trombone;
		m_i[5] = new horn;
	}
	void Play_all()
	{
		for (int i = 0; i < size; i++)
		{
			int j = rand() % 5;
			m_i[j]->grafik();
			m_i[j]->Play();			
		}
		delete[] m_i;
		PlaySound(TEXT("aplodisment-5-sec.wav"), NULL, SND_ASYNC | SND_LOOP);
		Sleep(5000);
		system("cls");
		cout << "\n\n\n\t\t\tPrice thise concert 1 000 000 $" << endl;
	}

};
