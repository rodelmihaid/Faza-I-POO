#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Zona.h"
using namespace std;


ceZona Zona::zona = ceZona::A;

Zona::Zona()
{
	bilet = Bilet::Bilet();
}

Zona::Zona(string zona, Bilet bilet)
{
	this->bilet = bilet;
}


ceZona Zona::getZona()
{
	return zona;
}

void Zona::setZona(ceZona zonanoua)
{
	zona = zonanoua;
}


Bilet Zona::getBilet()
{
	return this->bilet;
}

void Zona::setBilet(Bilet biletnou)
{
	this->bilet = biletnou;
}



ostream& operator<<(ostream& out, const Zona& z)
{
	out << z.bilet;
	return out;
}

istream& operator>>(istream& in, Zona& z)
{
	in >> z.bilet;
	return in;
}

bool Zona::operator!=(Zona& z)
{
	if (this->zona != z.zona)
		return true;
	else return false;
}

void Zona::operator>(Zona& z)
{
	if (this->zona > z.zona)
		cout << "Prima zona este la inceput de stadion";
	else if (this->zona == z.zona)
		cout << "Sunt in aceeasi zona";
	else cout << "A doua zona este la sfarsitul stadionului";

}

