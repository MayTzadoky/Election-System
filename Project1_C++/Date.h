#ifndef __Date_H
#define __Date_H

#include <iostream>
using namespace std;

class Date
{
private:
	int month, year;

public:

	Date(int year = 0, int month = 0);
	int getMonth()	const;
	int getYear()	const;

	bool setBYear(int tmpYear);
	bool setPYear(int tmpYear);
	bool setEYear(int tmpYear);
	bool setMonth(int m);
	friend ostream& operator<<(ostream& os, const Date& date);
};

#endif // __Date_H