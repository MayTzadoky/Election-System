#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "CoronaBB.h"

//c'tor
CoronaBB::CoronaBB(const BallotBox& bb) :BallotBox(bb)
{
	ifProtectiveSuit = false;
}

//set if wearing a protective suit
bool CoronaBB::setIfProtectiveSuit(bool tmpIfProtectiveSuit)
{
	ifProtectiveSuit = tmpIfProtectiveSuit;
	return true;
}

//d'tor
CoronaBB::~CoronaBB()
{
}

//returns if wearing a protective suit
bool CoronaBB::getIfProtectiveSuit() const
{
	return ifProtectiveSuit;
}

void CoronaBB::toOs(ostream& os) const
{
	os << "*Corona   Ballot-Box* ";
}