#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Bilet.h"
using namespace std;

string Bilet::mesaj = "Vizionare placuta!";

Bilet::Bilet() :id_unic(0)
{
	numeMeci = nullptr;
	tipBilet = "";
	bileteDisponibile = nullptr;
	nrBilete = 0;
}

Bilet::Bilet(string tipBilet, int* bileteDisponibile, int nrBilete, int id_unic, const char* numeMeci) :id_unic(id_unic)
{
	this->tipBilet = tipBilet;
	if (numeMeci != nullptr)
	{
		this->numeMeci = new char[strlen(numeMeci) + 1];
		strcpy_s(this->numeMeci, strlen(numeMeci) + 1, numeMeci);
	}
	if (bileteDisponibile != nullptr && nrBilete > 0)
	{
		this->bileteDisponibile = new int[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			this->bileteDisponibile[i] = bileteDisponibile[i];
		}
		this->nrBilete = nrBilete;
	}
	else
	{
		this->bileteDisponibile = nullptr;
		this->nrBilete = 0;
	}

}

Bilet::Bilet(const Bilet& s) : id_unic(s.id_unic)
{
	this->tipBilet = s.tipBilet;
	if (s.numeMeci != nullptr)
	{
		this->numeMeci = new char[strlen(s.numeMeci) + 1];
		strcpy_s(this->numeMeci, strlen(s.numeMeci) + 1, s.numeMeci);
	}
	if (s.bileteDisponibile != nullptr && s.nrBilete > 0)
	{
		this->bileteDisponibile = new int[s.nrBilete];
		for (int i = 0; i < s.nrBilete; i++)
		{
			this->bileteDisponibile[i] = s.bileteDisponibile[i];
		}
		this->nrBilete = s.nrBilete;
	}
	else
	{
		this->bileteDisponibile = nullptr;
		this->nrBilete = 0;
	}
}

Bilet::~Bilet()
{
	if (this->numeMeci != nullptr)
	{
		delete[]this->numeMeci;
	}

	if (this->bileteDisponibile != nullptr)
	{
		delete[] this->bileteDisponibile;
	}
}

Bilet& Bilet::operator=(const Bilet& b)
{
	if (this != &b)
	{
		if (b.bileteDisponibile != nullptr && b.nrBilete > 0)
		{
			this->bileteDisponibile = new int[b.nrBilete];
			for (int i = 0; i < b.nrBilete; i++)
			{
				this->bileteDisponibile[i] = b.bileteDisponibile[i];
			}
			this->nrBilete = b.nrBilete;
		}
		else
		{
			this->bileteDisponibile = nullptr;
			this->nrBilete = 0;
		}

		if (b.numeMeci != nullptr)
		{
			if(numeMeci!=nullptr)
			delete[]numeMeci;

			this->numeMeci = new char[strlen(b.numeMeci) + 1];
			strcpy_s(this->numeMeci, strlen(b.numeMeci) + 1, b.numeMeci);
		}

		this->tipBilet = b.tipBilet;

	}
	return *this;
}


int& Bilet::operator[](int index)
{
	if (index >= 0 && index < nrBilete)
	{
		return bileteDisponibile[index];
	}
	else
		throw exception("Index incorect");

}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "Tip Bilet: ";
	in >> ws;
	getline(in, b.tipBilet);

	if (b.numeMeci != nullptr)
	{
		delete[]b.numeMeci;
	}
	cout << "Nume Meci: ";
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	b.numeMeci = new char[strlen(buffer) + 1];
	strcpy_s(b.numeMeci, strlen(buffer) + 1, buffer);

	cout << "Nr Bilete: ";
	in >> b.nrBilete;

	if (b.bileteDisponibile != nullptr)
	{
		delete[] b.bileteDisponibile;
		b.bileteDisponibile= nullptr;
	}

	b.bileteDisponibile = new int[b.nrBilete];
	cout << "Bilete Disponibile: ";
	for (int i = 0; i < b.nrBilete; i++)
	{
		in >> b.bileteDisponibile[i];
	}

	return in;
}


ostream& operator<<(ostream& out, const Bilet& b)
{

	out << "Tip Bilet: " <<b.tipBilet << endl;
	if (b.numeMeci != nullptr)
	{
		out << "Nume Meci: " << b.numeMeci << endl;
	}
	out << "Nr bilete: " <<b.nrBilete << endl;
	out << "Bilete disponibile: ";
	for (int i = 0; i <b.nrBilete; i++)
	{
		out << b.bileteDisponibile[i] << " ";
	}
	out << endl;

	return out;

}


string Bilet::getTipBilete() 
{
	return this->tipBilet;
}

char* Bilet::getNumeMeci()
{
	if (numeMeci != nullptr)
	{
		char* copie = new char[strlen(numeMeci) + 1];
		strcpy_s(copie, strlen(numeMeci) + 1, numeMeci);
		return copie;
	}
	else
		return nullptr;
}

int* Bilet::getBileteDisponibile()
{
	if (bileteDisponibile != nullptr && nrBilete > 0)
	{
		int* copie = new int[nrBilete];
		for (int i = 0; i < nrBilete; i++)
			copie[i] = bileteDisponibile[i];
		return copie;
	}
	else
		return nullptr;
}

int Bilet::getNrBilete()
{
	return nrBilete;
}

int Bilet::getId_Unic()
{
	return id_unic;
}


void Bilet::setTipBilete(string tip)
{
	tipBilet = tip;
}

void Bilet::setNumeMeci(char* nume)
{
	if (nume != nullptr)
	{
		if (numeMeci != nullptr)
			delete[] numeMeci;
		numeMeci = new char[strlen(nume) + 1];
		strcpy_s(numeMeci, strlen(nume) + 1, nume);
	}
}
void Bilet::setBileteDisponibile(int* bilete, int numar)
{
	if (bilete != nullptr && numar > 0)
	{
		nrBilete = numar;
		if (bileteDisponibile != nullptr)
			delete[] bileteDisponibile;
		bileteDisponibile = new int[nrBilete];
		for (int i = 0; i < nrBilete; i++)
			bileteDisponibile[i] = bilete[i];
	}
}
void Bilet::setNrBilete(int numar)
{
	nrBilete = numar;
}


bool Bilet:: BiletVip(Bilet b)
{
	if (b.tipBilet == "Vip")
	{
		return true;
	}
	else return false;
}

bool Bilet::joacaBarca(Bilet b)
{
	if (strstr(b.numeMeci, "FCB") != 0)
		return true;
}
