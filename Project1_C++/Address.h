#pragma warning (disable: 4996)

#ifndef __Address_H
#define __Address_H

#include <iostream>
using namespace std;
#include <string>

class Address
{
private:
	string city;
	string street;
	int num;

public:
	Address(const string& city,const string& street, int num);
	const string& getCity()		const;
	const string& getStreet()	const;
	int getNum()				const;

	bool setCity(const string& city);
	bool setStreet(const string& street);
	bool setNum(int num);
	friend ostream& operator<<(ostream& os, const Address& address);
};
#endif // __Address_H