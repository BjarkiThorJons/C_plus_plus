// lab5310(1).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool canceReservations(int number_ob_seats);
private:
	int id;
	int capacity;
	int reserved;
	string command;
};
void FlightBooking::printStatus()
{
	this->id = id;
	this->capacity = capacity;
	this->reserved = reserved;
}
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	if (reserved < 0){
		reserved = 0;
	}
	int percentage = ((double)reserved / capacity) * 100;
	if (percentage >= 105){
		cout << "To many bookings";
	}
	else{
		std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " " << percentage << "% seats reserved";
	}
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
	// try to add reservations and return 'true' on success
	// keep the limits in mind
	return false;
}
bool FlightBooking::canceReservations(int number_ob_seats)
{
	// try to cancel reservations and return 'true' on success
	// keep the limits in mind
	return false;
}

int main() {
	int reserved = 0,
		capacity = 0;
	string command = "";
	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	FlightBooking booking(1, capacity, reserved);
	string command = "";
	int id;
	int n;
	while (command != "quit")
	{
	
		cout << "What would you like to do?: ";
		getline(cin, command);

		stringstream ss;
		ss << command;

		ss >> command >> id >> n;
		// handle the command
	}
	cout << endl;
	return 0;
}