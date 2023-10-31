#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"

using namespace std;
using namespace Records;
int displayMenu();
void doAddHotel(Database& inDB);
void doDelHotel(Database& inDB);
void doStarHotel(Database& inDB);
void doCountryHotel(Database& inDB);

int main(int argc, char** argv)
{
	Database hotelsDB;

	Hotels hotelOnStack("Hedef Resort", "Turkey", "Alanya", "Calhanoglu, 20", NumberStars::Four, "admin +4240-113-43-33", 1);

	hotelOnStack.display();

	Hotels* hotelOnHeap = new Hotels("Blu Perucci", "Italy", "Milano", "Zaniolo, 8", NumberStars::Five, "admin +9241-481-76-32", 2);

	hotelOnHeap->display();

	delete hotelOnHeap;

	bool done = false;
	while (!done) {
		int selection = displayMenu();
		switch (selection) {
		case 1:
			doAddHotel(hotelsDB);
			break;
		case 2:
			doDelHotel(hotelsDB);
			break;
		case 3:
			hotelsDB.displayAll();
			break;
		case 4:
			doStarHotel(hotelsDB);
			break;
		case 5:
			doCountryHotel(hotelsDB);
			break;
		case 0:
			done = true;
			break;
		default:
			cerr << "Unknown command." << endl;
		}
	}
}

int displayMenu()
{
	int selection;
	cout << endl;
	cout << "Hotels Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Add a new hotel" << endl;
	cout << "2) Delete the hotel from the DB" << endl;
	cout << "3) List all hotels" << endl;
	cout << "4) List all hotels by stars" << endl;
	cout << "5) List all hotels by country" << endl;
	cout << "0) Quit" << endl;
	cout << endl;

	cout << "---> ";
	cin >> selection;
	return selection;
}

void doAddHotel(Database& inDB) {
	string hotelName;
	string hotelCountry;
	string hotelCity;
	string hotelAddress;
	int starsInt;
	NumberStars hotelStars;
	string contactPerson;
	
	cout << "Hotel name? ";
	cin >> hotelName;
	cout << "In which country? ";
	cin >> hotelCountry;
	cout << "In which city? ";
	cin >> hotelCity;
	cout << "Hotel Address: ";
	cin >> hotelAddress;
	
	cout << "Number of stars (1 for Hostel, 2 for Two, 3 for Three, 4 for Four, 5 for Five)? ";
	cin >> starsInt;
	hotelStars = (starsInt == 1) ? NumberStars::Hostel : 
		(starsInt == 2) ? NumberStars::Two : 
		(starsInt == 3) ? NumberStars::Three : 
		(starsInt == 4) ? NumberStars::Four : NumberStars::Five;
	cout << "Contact person?";
	cin >> contactPerson;

	try {
		inDB.addHotel(hotelName, hotelCountry, hotelCity, hotelAddress, hotelStars, contactPerson);
	}
	catch (exception& ex) {
		cerr << "Unable to add new hotes!" << endl;
	}
}

void doDelHotel(Database& inDB)
{
	int hotelNumber;
	cout << "Hotel number? ";
	cin >> hotelNumber;
	try {
		Hotels& emp = inDB.getHotel(hotelNumber);
		emp.delHotel();
		cout << "Hotel " << hotelNumber << " has been deleted." << endl;
	}
	catch (std::exception ex) {
		cerr << "Unable to delete hotel!" << endl;
	}
}

void doStarHotel(Database& inDB)
{
	int stars;
	cout << "How many stars hotel? ";
	cin >> stars;
	inDB.displayStars(stars);
}

void doCountryHotel(Database& inDB)
{
	string country;
	cout << "Which country of hotels? ";
	cin >> country;
	inDB.displayCountry(country);
}
