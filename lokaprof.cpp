// lokaprof.cpp : Defines the entry point for the console application.
//Bjarki Þór Jónsson 
//11.12.2018

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
	string Nafn(){
		return nafn;
	}
};

class Stada{
public:
	char stada;
	string nafn;
	Stada(){
		nafn = "";
	}
	Stada(char i, string n){
		stada = i;
		nafn = n;
	}
};

class VistarLeikmadur : public Leikmadur{
public: 
	int stig;
	Stada stad;
	friend ostream & operator << (ostream &out, const VistarLeikmadur &c);
	VistarLeikmadur(int id, string nafn ,int s , Stada sa) : Leikmadur(id, nafn){
		stig = s;
		stad = sa;
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
};
ostream & operator << (ostream &out, const VistarLeikmadur &c)
{
	out << "id: "<<c.id<<", Nafn: "<<c.nafn<<", Stada: "<<c.stad.nafn<<", Stig "<<c.stig;
	return out;
}
int main()
{
	/*
	for (int i = 0; i < 100; i++) {
	tryggjaOddatolu(i);
	}
	*/
	Stada austur('A',"Austur");
	Stada vestur('V', "Vestur");

	VistarLeikmadur geir(101, "Geir", 0, austur);
	VistarLeikmadur gauti(102, "Gauti", 0, vestur);
	geir.Stig(10);
	gauti.Stig(3);
	cout << geir << endl;
	cout << gauti << endl;
	if (geir < gauti) cout << gauti.Nafn() << " vann!\n";
	else cout << geir.Nafn() << " vann!\n";
	return 0;
}

