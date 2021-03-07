#include <iostream>
using namespace std;

#include "Party.h"
#include <string>
#include <vector>

const char* eStr[] = { "RIGHT", "CENTER" , "LEFT" };

int Party::counter = 0;

//c'tor
Party::Party(const string& name, eFaction faction, int year, int month) :
	date(year, month)
{
	sn = counter++;
	setPartyName(name);
	setFaction(faction);
}

//Updates party's name
bool Party::setPartyName(const string& name)
{
	this->partyName = name;
	return true;
}

//Gets party's name from party class
const string& Party::getPartyName()		const
{
	return partyName;
}

//Updates political faction
bool Party::setFaction(eFaction tFaction)
{
	faction = tFaction;
	return true;
}

//Updates party's establishment date 
bool Party::setDate(int year, int month)
{
	if ((date.setPYear(year)) && (date.setMonth(month)))
		return true;
	else
		return false;
}

//Prints party's details
ostream& operator<<(ostream& os, const Party& party)
{
	os << "serial number: " << party.sn << ", establishment date: " << party.date << ", faction: " << eStr[party.faction] << ", party name: " << party.partyName << endl;
	return os;
}

//Gets date of the party establishment
Date& Party::getDate()
{
	return date;
}

//Gets candidate array of the party
vector<Candidate*> Party::getCandidateArr()	const
{
	return candidateArr;
}

//Gets the faction of the party
eFaction Party::getFaction()			const
{
	return faction;
}

//Adds new candidate to party
const Party& Party::operator+=(Citizen* candidate)
{
	if (candidateArr.size() == candidateArr.capacity())
	{
		candidateArr.reserve(candidateArr.size() * 2);
	}
	candidateArr.push_back((Candidate*)candidate);

	return *this;
}

//Compare the candidates' number of 2 parties
bool Party::operator>(const Party& other) const
{
	return candidateArr.size() > other.candidateArr.size();
}

//Updates the candidates of the party
bool Party::setCandidateToParty(Citizen* candidate)
{
	*this += candidate;
	return true;
}

//sets the candidate array
bool Party::setCandidateArr(vector<Candidate*> citizenArr)
{
	candidateArr = citizenArr;
	return true;
}
