#include <iostream>
#include <string>
#include "Bilet.h"
using namespace std;



enum class ceZona
{
	A,
	B,
	C
};


class Zona :Bilet
{

	static ceZona zona;
	Bilet bilet;

public:
	Zona();
	Zona(string zona, Bilet bilet);

	ceZona getZona();
	void setZona(ceZona zonanoua);

	Bilet getBilet();
	void setBilet(Bilet biletnou);

	friend ostream& operator<<(ostream& out, const Zona& z);
	friend istream& operator>>(istream& in, Zona& z);


	bool operator!=(Zona& z);
	void operator>(Zona& z);
};