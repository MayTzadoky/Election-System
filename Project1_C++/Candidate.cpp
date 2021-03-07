#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
using namespace std;

#include "Candidate.h"
#include "Party.h"

//c'tor
Candidate::Candidate(fstream& in, BallotBox* bb,Party* party) :Citizen(in,bb)
{
	this->party = party;
}

//c'tor
Candidate::Candidate(const Citizen& citizen, Party* party) : Citizen(citizen)
{
	this->party = party;
}

//return the party
Party* Candidate::getParty()	const
{
	return party;
}

//set a party
void Candidate::setParty(Party* party)
{
	this->party = party;
}

void Candidate::toOs(ostream& os) const
{
	os << "party: " << party->getPartyName();
}