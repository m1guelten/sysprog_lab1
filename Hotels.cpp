#include <iostream>
#include <string>
#include "Hotels.h"

using namespace std;
namespace Records {
	Hotels::Hotels()
	{
		mHotelName = "";
		mHotelCountry = "";
		mHotelCity = "";
		mHotelAddress = "";
		mHotelNumber = 1;
		mContactPerson = "";
		fAdd = false;
	}

	Hotels::Hotels(
		string mHotelName,
		string mHotelCountry,
		string mHotelCity,
		string mHotelAddress,
		NumberStars hotelStars,
		string mContactPerson,
		int mHotelCode)
	{
		this->mHotelName = mHotelName;
		this->mHotelCountry = mHotelCountry;
		this->mHotelCity = mHotelCity;
		this->mHotelAddress = mHotelAddress;
		this->hotelStars = hotelStars;
		this->mContactPerson = mContactPerson;
		this->fAdd = true;
	}

	void Hotels::addHotel()
	{
		fAdd = true;
	}
	void Hotels::delHotel()
	{
		fAdd = false;
	}
	void Hotels::display()
	{
		cout << "Hotels Information" << endl;
		cout << "-------------------" << endl;
		cout << "Hotel name: " << mHotelName << endl;
		cout << "Hotel in country: " << mHotelCountry << endl;
		cout << "Hotel in city: " << mHotelCity << endl;
		cout << "Address of hotel: " << mHotelAddress << endl;
		
		cout << "Position: ";
		switch (hotelStars) {
		case NumberStars::Hostel:
			cout << "Status hotel - 1 STAR" << endl;
			break;
		case NumberStars::Two:
			cout << "Status hotel - 2 STAR" << endl;
		break;
		case NumberStars::Three:
			cout << "Status hotel - 3 STAR" << endl;
			break;
		case NumberStars::Four:
			cout << "Status hotel - 4 STAR" << endl;
			break;
		case NumberStars::Five:
			cout << "Status hotel - 5 STAR" << endl;
			break;
		default:
			cout << "Status hotel - Unknown" << endl;
			break;
		}

		cout << "Contact person: " << mContactPerson << endl;
		cout << " " << endl;
	}
	// Accessors and setters
	void Hotels::setHotelName(string inHotelName)
	{
		mHotelName = inHotelName;
	}
	string Hotels::getHotelName()
	{
		return mHotelName;
	}

	void Hotels::setHotelCountry(string inHotelCountry)
	{
		mHotelCountry = inHotelCountry;
	}
	string Hotels::getHotelCountry()
	{
		return mHotelCountry;
	}
	

	void Hotels::setHotelCity(string inHotelCity)
	{
		mHotelCity = inHotelCity;
	}
	string Hotels::getHotelCity()
	{
		return mHotelCity;
	}

	void Hotels::setHotelAddress(string inHotelAddress)
	{
		mHotelAddress = inHotelAddress;
	}
	string Hotels::getHotelAddress()
	{
		return mHotelAddress;
	}

	void Hotels::setHotelNumber(int inHotelNumber)
	{
		mHotelNumber = inHotelNumber;
	}
	int Hotels::getHotelNumber()
	{
		return mHotelNumber;
	}

	void Hotels::setHotelCode(int code)
	{
		mHotelCode = code;
	}
	int Hotels::getHotelCode()
	{
		return mHotelCode;
	}

	void Hotels::setHotelStars(NumberStars wHotelStars)
	{
		hotelStars = wHotelStars;
	}
		NumberStars Hotels::getHotelStars()
	{
		return hotelStars;
	}
	
	void Hotels::setContactPerson(string inContactPerson)
	{
		mContactPerson = inContactPerson;
	}
	string Hotels::getContactPerson()
	{
		return mContactPerson;
	}

	bool Hotels::getIsAdd()
	{
		return fAdd;
	}
}