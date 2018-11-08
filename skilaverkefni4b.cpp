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
		else if (id <0){
			
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
	int id(int b){
		for (int i = 0; i < next; i++)
		{
			if (listi[i].returnId() == b) {
				return i;
			}
		}
	}
	void syna() {
		for (int i = 0; i < next; i++)
			listi[i].Booking();
	}
	void add(int b, int reserved){
		listi[b].reserveSeats(reserved);
	}
	void cancel(int b, int reserved){
		listi[b].cancelReservations(reserved);
	}
	void del(int b){
		listi[b] = FlightBooking(-1, 0, 0);
	}
	~FlightList() {
		delete[]listi;
	}
};


int main() {
	FlightList booking = FlightList();
	booking.setja(FlightBooking(2, 200, 0));
	booking.setja(FlightBooking(1, 400, 0));
	booking.setja(FlightBooking(3, 600, 0));
	booking.setja(FlightBooking(4, 800, 0));
	int asd = booking.id(2);
	booking.syna();
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
		int s = booking.id(id);
		if (command == "add") {
			booking.add(s, n);
		}
		else if (command == "cancel") {
			booking.cancel(s, n);
		}
		else if (command == "create") {
			booking.setja(FlightBooking(id, n, 0));
		}
		else if (command == "delete"){
			booking.del(s);
		}
		booking.syna();
	}
	cout << endl;
	return 0;
}
