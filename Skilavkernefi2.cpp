// Skilavkernefi2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int ip_dec(int *ip_tala){
	return (ip_tala[0] << 24 | ip_tala[1] << 16 | ip_tala[2] << 8 | ip_tala[3]);
}

void dec_ip(int *ip_tala, int ipheiltala){
	ip_tala[0] = ipheiltala >> 24 & 0xff;
	ip_tala[1] = ipheiltala >> 16 & 0xff;
	ip_tala[2] = ipheiltala >> 8 & 0xff;
	ip_tala[3] = ipheiltala & 0xff;
}
void synaIpTolu(const char*texti, int *ipTolur) {
	for (int i = 0; i < 4; i++) {
		if (i != 3) {
			cout << ipTolur[i] << ".";
		}
		else {
			cout << ipTolur[i] << "       ";
		}
	}
}

void synaIpTolu(const char*texti, int ipTala) {
	int ip[4];
	dec_ip(ip, ipTala);
	synaIpTolu(texti, ip);
}
void subnetting(int ipNet, int netBitar, int bitaFjoldi) {
	cout << "IP net        Fyrsta nothaefa      Sidasta nothaefa         Broadcast       Maski" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	int magic = pow(2, (32 - (netBitar + bitaFjoldi))); //magic number
	for (int i = 0; i < pow(2, bitaFjoldi); i++) {
		int tempnet = ipNet + (magic*i);
		synaIpTolu("", tempnet); //network
		synaIpTolu("\t", tempnet + 1); //fyrsta nothaefa
		synaIpTolu("\t", tempnet + magic - 2); //seinasta nothaefa
		synaIpTolu("\t", tempnet + magic - 1); //broadcast
		tempnet = 0xffffffff << (32 - (netBitar + bitaFjoldi)); //subnet maskinn 1
		synaIpTolu("\t", tempnet); //subnet maskinn 2
		cout << endl;
	}

}

int main(){
	int val = 1;
	while (val){
		//láta notanda skrifa ip tölu og láta hana í lista
		int *ip_tala = new int[4];
		int morg_net, margir_bitar, subnet_bitar;
		cout << "Sladu inn ip tolu ";
		for (int i = 0; i < 4; i++){
			cin >> ip_tala[i];
		}
		//breyta Ip tölu í heiltölu
		//unsigned int ipheiltala = ip_tala[0] << 24 | ip_tala[1] << 16 | ip_tala[2] << 8 | ip_tala[3];
		//breyta Ip tölu til baka
		//ip_tala[0] = ipheiltala >> 24 & 0xff;
		//ip_tala[1] = ipheiltala >> 16 & 0xff;
		cout << "Hversu morg net? ";
		cin >> morg_net;
		cout << "Hversu margir bitar ";
		cin >> margir_bitar;
		int ip2Dec = ip_dec(ip_tala);
		subnet_bitar = ceil(log2(morg_net));
		subnetting(ip2Dec, margir_bitar, subnet_bitar);

	}
	return 0;
}