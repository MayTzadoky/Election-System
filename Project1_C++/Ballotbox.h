#ifndef __BallotBox_H
#define __BallotBox_H

#include <iostream>
using namespace std;
#include <vector>
#include <string>

#include "Citizen.h"
#include "Address.h"
#include "Party.h"
#include "Array.h"

class BallotBox
{
protected:
	static int counter;
	int	sn;
	Address address;
	vector<Citizen*> citizenArr;
	float percentOfVoters;
	Array<int> results;

public:
	BallotBox(int physicalPartySize, int logicalPartySize, const string& city, const string& street, int num);
	virtual ~BallotBox();
	int getSn()						const;
	Address getAddress()			const;
	float getPercentOfVoters()		const;
	Array<int> getResults()			const;
	int getLogicalSizeCitizen()		const;
	int getPhysicalSizeCitizen()	const;
	int getLogicalSizeResults()		const;
	int getPhysicalSizeResults()	const;

	bool setAddress(const string& city, const string& street, int num);
	void setResults();
	int getElectionResults(int i)	const;
	void updateSelectionInBB(int indexParty);
	void updatePercentOfVoters();
	void updateCitizenArr(Citizen *citizen);
	friend ostream& operator<<(ostream& os, const BallotBox& bb);
	virtual void toOs(ostream& os) const;
};

#endif // __BallotBox_H