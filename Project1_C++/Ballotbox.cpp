#include <iostream>
using namespace std;

#include "BallotBox.h"
#include "Array.h"
int BallotBox::counter = 0;

//c'tor
BallotBox::BallotBox(int physicalPartySize, int logicalPartySize, const string& city, const string& street, int num) :
	address(city, street, num), results(physicalPartySize)
{
	sn = counter++;
	percentOfVoters = 0;
	if (results.getPhysicalSize() > 0)
	{
		for (int i = 0; i < logicalPartySize; i++)
			results += 0;
	}
}

//d'tor
BallotBox::~BallotBox()
{
}

//Updates the citizens array
void BallotBox::updateCitizenArr(Citizen* citizen)
{
	if (citizenArr.size() == citizenArr.capacity())
		citizenArr.reserve(citizenArr.size() * 2);

	citizenArr.push_back(citizen);
}

//Update the elections results per ballot box
void BallotBox::setResults()
{
	if (results.getLogicalSize() == results.getPhysicalSize())
	{
		results.enlargeArray();
	}
	results += 0;
}

//Updates the address of the ballot box
bool BallotBox::setAddress(const string& city, const string& street, int num)
{
	if ((address.setCity(city)) && (address.setStreet(street)) && (address.setNum(num)))
		return true;
	else
		return false;
}

//Gets the elections results
int BallotBox::getElectionResults(int i) const
{
	return results[i];
}

//Gets the precent of voters 
float BallotBox::getPercentOfVoters() const
{
	return percentOfVoters;
}

//Updates the votes in the ballot box
void BallotBox::updateSelectionInBB(int indexParty)
{
	++results[indexParty];
}

//Updates the precent of voters
void BallotBox::updatePercentOfVoters()
{
	percentOfVoters += 100 / citizenArr.size();
}

//Prints the ballot boxes 
ostream& operator<<(ostream& os, const BallotBox& bb)
{
	bb.toOs(os);
	if (typeid(bb) == typeid(BallotBox))
		os << "*Regular  Ballot-Box* ";
	os << "serial number: " << bb.sn << bb.address;
	return os;
}

//Gets the serial number
int BallotBox::getSn()	const
{
	return sn;
}

//Gets address of the ballot box
Address BallotBox::getAddress()	const
{
	return address;
}

//Gets restuls of the ballot box
Array<int> BallotBox::getResults()	const
{
	return results;
}

//Gets logical size of results array
int BallotBox::getLogicalSizeResults()		const
{
	return results.getLogicalSize();
}

//Gets physical size of results array
int BallotBox::getPhysicalSizeResults()		const
{
	return results.getPhysicalSize();
}

void BallotBox::toOs(ostream& os) const
{
}

//Gets logical size of citizen array
int BallotBox::getLogicalSizeCitizen()		const
{
	return citizenArr.size();
}

//Gets physical size of citizen array
int BallotBox::getPhysicalSizeCitizen()		const
{
	return citizenArr.capacity();
}
