#include <iostream>
using namespace std;

#include "Date.h"

//c'tor
Date::Date(int year, int month)
{
	this->month = month;
	this->year = year;
}

//Updates month in the date 
bool Date::setMonth(int tmpMonth)
{
	if ((tmpMonth >= 1) && (tmpMonth <= 12))
	{
		month = tmpMonth;
		return true;
	}
	else
		return false;
}

//Updates birth year
bool Date::setBYear(int tmpYear)
{
	if (tmpYear <= 2002)
	{
		year = tmpYear;
		return true;
	}
	else
		return false;
}

//Updates party establishment date
bool Date::setPYear(int tmpYear)
{
	if (tmpYear <= 2020)
	{
		year = tmpYear;
		return true;
	}
	else
		return false;
}

//Updates elections date 
bool Date::setEYear(int tmpYear)
{
	if (tmpYear >= 2020)
	{
		year = tmpYear;
		return true;
	}
	else
		return false;
}

//Gets month
int Date::getMonth()	const
{
	return month;
}

//Gets year
int Date::getYear()		const
{
	return year;
}

//Prints date 
ostream& operator<<(ostream& os, const Date& date)
{
	os << (date.month < 10 ? "0" : "") << date.month << "." << date.year;
	return os;
}

