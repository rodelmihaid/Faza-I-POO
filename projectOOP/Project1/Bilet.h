#include <iostream>
#include <string>
using namespace std;

class Bilet
{
private:
	string tipBilet;
	char* numeMeci;
	int* bileteDisponibile;
	int nrBilete;
	static string mesaj;
	const int id_unic;

public:
	Bilet();
	Bilet(string tipBilet, int* bileteDisponibile, int nrBilete, int id_unic, const char* numeMeci);
	Bilet(const Bilet& s);
	~Bilet();

	string getTipBilete();
	char* getNumeMeci();
	int* getBileteDisponibile();
	int getNrBilete();
	int getId_Unic();    //

	void setTipBilete(string tip);
	void setNumeMeci(char* nume);
	void setBileteDisponibile(int* bilete,int numar);
	void setNrBilete(int numar);

	
	bool BiletVip(Bilet b);
	bool joacaBarca(Bilet b);


	Bilet& operator=(const Bilet& b);
	int& operator[](int index);



	friend istream& operator>>(istream& in, Bilet& e);
	friend ostream& operator<<(ostream& out, const Bilet& e);
};