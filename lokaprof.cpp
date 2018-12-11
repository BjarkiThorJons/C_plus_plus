// lokaprof.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

int tryggjaOddatolu(int i){
	string binary = bitset<8>(i).to_string();
	int t = stoi(binary);
	t = t % 10;
	i = i + 1;
	i = i - t;
	cout << i << endl;
	return i;
}

class Leikmadur{
public:
	int id;
	string nafn;
	Leikmadur(){
		id = 0;
		nafn = "";
	}
	Leikmadur(int i, string n){
		id = i;
		nafn = n;
	}
};

class Stada{
public:
	string stada;
	string nafn;
	Stada(){
		stada = "";
		nafn = "";
	}
	Stada(string i, string n){
		stada = i;
		nafn = n;
	}
};

class VistarLeikmadur : public Leikmadur{
public: 
	int stig;
	friend ostream & operator << (ostream &out, const VistarLeikmadur &c);
	//Stada stad;
	VistarLeikmadur(int id, string nafn ,int s) : Leikmadur(id, nafn){
		stig = s;
		//stad = sa;
	}
	void Stig(int i){
		stig = i;
	}
	bool operator<(VistarLeikmadur b){
		if (stig < b.stig){
			return true;
		}
		else{
			return false;
		}
	}
	

	VistarLeikmadur operator<<(VistarLeikmadur b){
		cout << "hæ";
	}

};
ostream & operator << (ostream &out, const VistarLeikmadur &c)
{
	out << "id: "<<c.id<<" Nafn: "<<c.nafn<<" Stada: eh "<<" Stig "<<c.stig;
	return out;
}
int main()
{
	/*
	for (int i = 0; i < 100; i++) {
	tryggjaOddatolu(i);
	}
	*/
	//Stada austur('A',"Austur");
	//Stada vestur('V', "Vestur");

	VistarLeikmadur geir(101, "Geir", 0);
	VistarLeikmadur gauti(102, "Gauti", 0);
	geir.Stig(10);
	gauti.Stig(3);
	cout << geir << endl;
	cout << gauti << endl;
	if (geir < gauti) cout << gauti.nafn << " vann!\n";
	else cout << geir.nafn << " vann!\n";
	return 0;
}

