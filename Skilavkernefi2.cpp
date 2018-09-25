// Skilavkernefi2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int ip_dec(int ip_tala[4]){
	return (ip_tala[0] << 24 | ip_tala[1] << 16 | ip_tala[2] << 8 | ip_tala[3]);
}

void dec_ip(int ip_tala[4], int ipheiltala){
	ip_tala[0] = ipheiltala >> 24 & 0xff;
	ip_tala[1] = ipheiltala >> 16 & 0xff;
	ip_tala[2] = ipheiltala >> 8 & 0xff;
	ip_tala[3] = ipheiltala & 0xff;
}


int main(){
	int val = 1;
	while (val){
		//láta notanda skrifa ip tölu og láta hana í lista
		int ip_tala[4];
		int morg_net;
		int margir_bitar;
		cout << "Sladu inn ip tolu ";
		for (int i = 0; i < 4; i++){
			cin >> ip_tala[i];
		}
		//breyta Ip tölu í heiltölu
		//unsigned int ipheiltala = ip_tala[0] << 24 | ip_tala[1] << 16 | ip_tala[2] << 8 | ip_tala[3];
		unsigned int ipheiltala = ip_dec(ip_tala);
		cout << ipheiltala;
		//breyta Ip tölu til baka
		//ip_tala[0] = ipheiltala >> 24 & 0xff;
		//ip_tala[1] = ipheiltala >> 16 & 0xff;
		cout << "Hversu morg net? ";
		cin >> morg_net;
		cout << "Hversu margir bitar ";
		cin >> margir_bitar;
		int subnet_bitar = ceil(log2(morg_net));
		int tala = 32-margir_bitar+subnet_bitar; 
		int magic = pow(2,tala);
		for (int i = 0; i <= morg_net; i++){
			cout << ip_tala[0];

		}
		//int subnet0 = ipheiltala;
		//int subnet1 = subnet0 + magic;
		//int subnet2 = subnet1 + magic;
		cout << subnet_bitar;
	}
	return 0;
}