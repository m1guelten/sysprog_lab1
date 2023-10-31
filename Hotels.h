#pragma once
#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace Records
{
	enum NumberStars
	{
		Hostel = 1,
		Two, 
		Three,
		Four,
		Five
	};

	class Hotels
	{
	public:
		Hotels();
		Hotels(
			string hotelName,
			string hotelCountry,
			string hotelCity,
			string hotelAddress,
			NumberStars hotelStars,
			string contactPerson,
			int mHotelCode);
		void addHotel();
		void delHotel();
		void display(); // outputs employee info to the console
		// Accessors and setters
		void setHotelName(std::string inHotelName);
		std::string getHotelName();

		void setHotelCountry(std::string inHotelCountry);
		std::string getHotelCountry();
		
		void setHotelCity(std::string inHotelCity);
		std::string getHotelCity();
		
		void setHotelAddress(std::string inHotelAddress);
		std::string getHotelAddress();
		
		void setContactPerson(std::string inContactPerson);
		std::string getContactPerson();
		
		void setHotelNumber(int inHotelNumber);
		int getHotelNumber();
		
		int getHotelCode();
		void setHotelCode(int code);
		
		NumberStars getHotelStars();
		void setHotelStars(NumberStars wHotelStars);
		 
		bool getIsAdd();


	private:
		std::string mHotelName;
		std::string mHotelCountry;
		std::string mHotelCity;
		std::string mHotelAddress;
		int mHotelCode;
		NumberStars hotelStars;
		std::string mContactPerson;
		int mHotelNumber;
		bool fAdd;
	};
}