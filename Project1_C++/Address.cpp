
#include <iostream>
using namespace std;

#include "Address.h"

//c'tor
Address::Address(const string& city, const string& street, int num)
{
	setCity(city);
	setStreet(street);
	setNum(num);
}

//Gets city for the address
const string& Address::getCity()	const
{
	return city;
}

//Gets street for the address
const string& Address::getStreet()	const
{
	return street;
}

//Gets apartment number for the address
int Address::getNum()		const
{
	return num;
}

//Updates the city
bool Address::setCity(const string& city)
{
	this->city = city;
	return true;
}

//Updates the street
bool Address::setStreet(const string& street)
{
	this->street =street;
	return true;
}

//Updates the apratment number
bool Address::setNum(int tmpNum)
{
	if (tmpNum > 0)
	{
		num = tmpNum;
		return true;
	}
	else
		return false;
}

//Print the address
ostream& operator<<(ostream& os, const Address& address)
{
	os << ", city: " << address.city << ", street: " << address.street << ", number: " << address.num << endl;
	return os;
}