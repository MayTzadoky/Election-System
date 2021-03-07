#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "MilitaryBB.h"

//c'tor
MilitaryBB::MilitaryBB(const BallotBox& bb) :BallotBox(bb)
{
	ifSoldier = false;
}

//d'tor
MilitaryBB::~MilitaryBB()
{
}

//Prints the military ballot box
void MilitaryBB::toOs(ostream& os) const
{
	os << "*Military Ballot-Box* ";
}