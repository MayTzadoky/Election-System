#ifndef __Candidate_H
#define __Candidate_H

#include "Citizen.h"
#include <iostream>
using namespace std;

class Party;

class Candidate : public Citizen
{
private:
	Party* party;

public:
	Candidate(const Citizen& citizen, Party* party);
	Candidate(fstream& in, BallotBox* bb, Party* party);
	Party* getParty()				const;
	void setParty(Party* party);
	virtual void toOs(ostream& os)	const override;
};

#endif // __Candidate_H