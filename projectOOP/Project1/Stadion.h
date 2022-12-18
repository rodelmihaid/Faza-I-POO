#include <iostream>
#include <string>
#include "Zona.h"
using namespace std;

class Stadion :Zona
{

	Zona zona;
public:
	Stadion();
	Stadion(Zona zona);


	Zona getZona();
	void setZona(Zona zonaNoua);


	friend ostream& operator<<(ostream& out, const Stadion& stadion);
	friend istream& operator>>(istream& in, Stadion& stadion);



};