#pragma once
#pragma once
#include <iostream>
#include "Hotels.h"
#include <string>

using namespace std;

namespace Records {
	const int kMaxHotels = 100;
	const int kFirstHotelsNumber = 1000;
	class Database
	{
	public:
		Database();
		~Database();
		Hotels& addHotel(
			string hotelName,
			string hotelCountry,
			string hotelCity,
			string hotelAddress,
			NumberStars hotelStars,
			string contactPerson);
		Hotels& getHotel(int inHotelNumber);
		void displayAll();
		void displayStars(int stars);
		void displayCountry(string country);
	protected:
		Hotels mHotels[kMaxHotels];
		int amount;
		int mNextHotelNumber;
	};
}
