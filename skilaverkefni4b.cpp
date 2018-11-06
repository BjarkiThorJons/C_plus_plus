#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;

class FlightBooking {
private:
	int id;
	int capacity;
	int reserved;
public:
	FlightBooking(int i, int cab, int res)
	{
		id = i;
		capacity = cab;
		reserved = res;
	}
	FlightBooking()
	{
		id = 0;
		capacity = 0;
		reserved = 0;
	}
	void Booking()
	{
		if (reserved < 0) {
			reserved = 0;
		}
		int percentage = ((double)reserved / capacity) * 100;
		if (percentage > 105) {
			cout << "To many bookings";
		}
		else {
			std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " " << percentage << "% seats reserved" << endl;
		}
	}
	void reserveSeats(int number_ob_seats)
	{
		if (number_ob_seats < 0) {
			cout << "Cannot perform this operation" << endl;
		}
		else if ((((double)reserved + number_ob_seats / capacity) * 100) <= 105) {
			reserved += number_ob_seats;
		}
		else {
			cout << "Cannot perform this operation" << endl;
		}
	}
	void cancelReservations(int number_ob_seats)
	{
		if (number_ob_seats < 0) {
			cout << "Cannot perform this operation" << endl;
		}
		else if ((((double)reserved - number_ob_seats / capacity) * 100) >= 0) {
			reserved -= number_ob_seats;
		}
		else {
			cout << "Cannot perform this operation" << endl;
		}
	}
	int returnId() {
		return id;
	}
};

class FlightList {
private:
	int *listi;
	int staflaBendill;
	int staerd;
public:
	FlightList() {
		staerd = 2;
		listi = new int[staerd];
		staflaBendill = 0;
	}
	void setjaStak(int stak) {
		if (staflaBendill <= staerd - 1)
			listi[staflaBendill++] = stak;
		else {
			int *temp = new int[staerd * 2];
			for (int i = 0; i < staerd; i++)
				temp[i] = listi[i];

			delete[]listi;
			listi = temp;
			staerd *= 2;
			listi[staflaBendill++] = stak;
		}
	}
	int saekjaStak() {
		return listi[--staflaBendill];
	}
	void synaStafla() {
		for (int i = 0; i < staflaBendill; i++)
			cout << listi[i] << " ";
		cout << endl << endl;
	}
	~FlightList() {
		delete[]listi;
	}
};


int main() {
	/*
	int reserved,
	capacity;
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;
	FlightBooking s = FlightBooking(1, capacity, reserved);
	s.Booking();
	*/
	FlightBooking booking[10];
	string command = "";
	int n;
	int id;
	int teljari = 0;
	int s = 0;
	while (command != "quit")
	{

		cout << "What would you like to do?: ";

		getline(cin, command);

		stringstream ss;
		ss << command;
		cout << endl;
		ss >> command >> id >> n;
		for (int i = 0; i < 10; i++)
		{
			//cout << endl << booking[i].returnId() <<" " << id << endl;
			if (booking[i].returnId() == id) {
				s = i;
			}
		}
		if (command == "add") {
			booking[s].reserveSeats(n);
		}
		else if (command == "cancel") {
			booking[s].cancelReservations(n);
		}
		else if (command == "create") {
			int q = teljari;
			for (int i = 0; i < 10; i++)
			{
				//cout << endl << booking[i].returnId() <<" " << id << endl;
				if (booking[i].returnId() == -1) {
					q = i;
				}
			}
			booking[q] = FlightBooking(id, n, 0);
			teljari += 1;
		}
		else if (command == "delete") {
			booking[s] = FlightBooking(-1, 0, 0);
			teljari += 1;
		}
		for (int i = 0; i < 10; i++)
		{
			if (booking[i].returnId() > 0) {
				booking[i].Booking();
			}
		}
		// handle the command
	}
	cout << endl;
	return 0;
}