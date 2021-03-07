#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "MilitaryCoronaBB.h"

//c'tor
MilitaryCoronaBB::MilitaryCoronaBB(const BallotBox& bb) :
	CoronaBB(bb), MilitaryBB(bb), BallotBox(bb)
{
}

//d'tor
MilitaryCoronaBB::~MilitaryCoronaBB()
{
}

//Prints the military corona ballot box
void MilitaryCoronaBB::toOs(ostream& os) const
{
	os << "*Military-Corona  BB* ";
}