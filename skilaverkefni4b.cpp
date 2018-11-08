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
	FlightBooking  *listi;
	int next;
	int staerd;
public:
	FlightList() {
		this->staerd = 2;
		listi = new FlightBooking[staerd];
		next = 0;
	}
	void setja(FlightBooking stak) {
		if (next <= staerd - 1)
			listi[next++] = stak;
		else {
			FlightBooking *temp = new FlightBooking[staerd * 2];
			for (int i = 0; i < staerd; i++)
				temp[i] = listi[i];

			delete[]listi;
			listi = temp;
			staerd *= 2;
			listi[next++] = stak;
		}
	}
	int saekja() {
		for (int i = 0; i < sizeof(listi); i++){
			listi[i].Booking();
		}
		
		return 0;
	}
	int id(int b){
		for (int i = 0; i < sizeof(listi); i++)
		{
			//cout << endl << booking[i].returnId() <<" " << id << endl;
			if (listi[i].returnId() == b) {
				return i;
			}
		}
	}
	void syna() {
		for (int i = 0; i < next; i++)
			listi[i].Booking();
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
	FlightList boooking = FlightList();
	boooking.setja(FlightBooking(1, 200, 0));
	boooking.setja(FlightBooking(2, 400, 0));
	boooking.setja(FlightBooking(3, 600, 0));
	boooking.setja(FlightBooking(4, 800, 0));
	cout << "asd: " << boooking.saekja();
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
		/*
		for (int i = 0; i < sizeof(booking); i++)
		{
			//cout << endl << booking[i].returnId() <<" " << id << endl;
			if (booking[i].returnId() == id) {
				s = i;
				cout << s;
			}
		}
		*/
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
