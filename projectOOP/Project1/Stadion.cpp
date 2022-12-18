#include <iostream>
#include <string>
#include "Stadion.h"

using namespace std;


Stadion::Stadion()
{
	zona = Zona::Zona();
}
Stadion::Stadion(Zona zona)
{
	this->zona = zona;
}


Zona Stadion::getZona()
{
	return zona;
}

void Stadion::setZona(Zona zonaNoua)
{
	zona = zonaNoua;
}

ostream& operator<<(ostream& out, const Stadion& stadion)
{
	out << stadion.zona;
	return out;

}


istream& operator>>(istream& in, Stadion& stadion)
{
	in >> stadion.zona;
	return in;
}