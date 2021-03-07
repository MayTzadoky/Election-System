#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
using namespace std;

#include "BallotBox.h"

//'ctor
Citizen::Citizen(fstream& in, BallotBox* bb)
{
	in >> firstN >> lastN >> id >> birthYear >> isQuarantined;
	setSoldier(birthYear);
	ballotBox = bb;
	isVoted = false;
}

//c'tor
Citizen::Citizen(const string& fName, const string& lName, int cId, int cYear, BallotBox* bb, bool isQuarantined) throw(const char*)
{
	if (!setId(cId))
	{
		throw "ID have to be a 9-digit number. \nPlease enter ID again: ";
	}
	setFirstN(fName);
	setLastN(lName);
	birthYear = cYear;
	isVoted = false;
	this->isQuarantined = false;
	ballotBox = bb;
	setSoldier(cYear);
}

bool Citizen::setSoldier(int year)
{
	(year >= 2000 && year <= 2002) ? isSoldier = true : isSoldier = false;
	return isSoldier;
}

//Updates the ID of the citizen
bool Citizen::setId(int num)
{
	int counter = 0, tmp = num;

	while (tmp > 0)
	{
		tmp /= 10;
		counter++;
	}
	if (counter == 9)
	{
		id = num;
		return true;
	}
	return false;
}

//Updates the first name of the citizen
bool Citizen::setFirstN(const string& fname)
{
	firstN = fname;
	return true;
}

//Updates the last name of the citizen
bool Citizen::setLastN(const string& lname)
{
	lastN = lname;
	return true;
}

//Updates if the citizen voted 
bool Citizen::setIsVoted(bool tmpIsVoted)
{
	isVoted = tmpIsVoted;
	return true;
}

//Updates the birth year of the citizen
bool Citizen::setBYear(int tmpYear)
{
	birthYear = tmpYear;
	return true;
}

//Gets the first name of the citizen
const string& Citizen::getFirstN()
{
	return firstN;
}

//Gets the last name of the citizen
const string& Citizen::getLastN()
{
	return lastN;
}

//Gets the ID of the citizen
int Citizen::getId() const
{
	return id;
}

//Gets the ballot box of the citizen
BallotBox* Citizen::getBallotBox() const
{
	return ballotBox;
}

//Gets if the citizen voted
bool Citizen::getIsVoted() const
{
	return isVoted;
}

bool Citizen::getIsQuarantined() const
{
	return isQuarantined;
}

bool Citizen::setIsQuarantined(bool isQuarantined)
{
	this->isQuarantined = isQuarantined;
	return true;
}

//Gets the birth year of the citizen
int Citizen::getBirthYear()	 const
{
	return birthYear;
}

//Updates the ballot box of the citizen
bool Citizen::setBallotBox(BallotBox* bb)
{
	ballotBox = bb;
	return true;
}

//Prints citizen details
ostream& operator<<(ostream& out, const Citizen& citizen)
{
	if (typeid(out) == typeid(ofstream))
		out << citizen.firstN << " " << citizen.lastN << " " << citizen.id << " " << citizen.birthYear << " " << citizen.isQuarantined;
	else
	{
		cout << "ID: " << citizen.id << ", year of birth: " << citizen.birthYear << ", First name: " << citizen.firstN << ", last name: " << citizen.lastN << " ";
		citizen.toOs(out);
		cout << endl;
	}
	return out;
}

void Citizen::toOs(ostream& os) const
{
}

//return if is soldier
bool Citizen::getIsSoldier() const
{
	return isSoldier;
}