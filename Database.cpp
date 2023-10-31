#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
using namespace std;
namespace Records {
	Database::Database()
	{
		amount = 1;
		mNextHotelNumber = kFirstHotelsNumber;
	}
	Database::~Database()
	{
	}
	Hotels& Database::addHotel(
		string hotelName,
		string hotelCountry,
		string hotelCity,
		string hotelAddress,
		NumberStars hotelStars,
		string contactPerson) {

		if (amount >= kMaxHotels) {
			cerr << "There is no more room to add the new hotel!" << endl;
			throw exception();
		}

		Hotels& theHotels = mHotels[amount++];
		theHotels.setHotelName(hotelName);
		theHotels.setHotelCountry(hotelCountry);
		theHotels.setHotelCity(hotelCity);
		theHotels.setHotelAddress(hotelAddress);
		theHotels.setHotelStars(hotelStars);
		theHotels.setContactPerson(contactPerson);
		theHotels.setHotelNumber(amount);
		theHotels.addHotel();
		return theHotels;
	}

	Hotels& Database::getHotel(int inHotelNumber)
	{
		for (int i = 0; i < amount; i++) {
			if (mHotels[i].getHotelNumber() == inHotelNumber) {
				return mHotels[i];
			}
		}
		cerr << "No employee with employee number " << inHotelNumber << endl;
		throw exception();
	}

	void Database::displayAll()
	{
		for (int i = 0; i < amount; i++) 
		{
			if (mHotels[i].getIsAdd())
				mHotels[i].display();
		}
	}

	void Database::displayStars(int stars)
	{
		for (int i = 0; i < amount; i++)
		{
			if (mHotels[i].getIsAdd() && mHotels[i].getHotelStars() == stars)
				mHotels[i].display();
		}
	}

	void Database::displayCountry(string country)
	{
		for (int i = 0; i < amount; i++)
		{
			if (mHotels[i].getIsAdd() && mHotels[i].getHotelCountry() == country)
				mHotels[i].display();
		}
	}
}