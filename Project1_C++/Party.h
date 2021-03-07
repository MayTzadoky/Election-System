#pragma warning (disable: 4996)

#ifndef __Party_H
#define __Party_H
#include <string>
#include <vector>

#include "Date.h"
#include "Citizen.h"
#include "Candidate.h"

enum eFaction { RIGHT, CENTER, LEFT };

class Party
{
public:

	Party(const string& name, eFaction faction, int year, int month);
	eFaction faction;

	Date& getDate();
	const string& getPartyName()			const;
	vector<Candidate*> getCandidateArr()	const;
	eFaction getFaction()					const;
	const Party& operator+=(Citizen* candidate);
	bool operator>(const Party& other)		const;

	bool setPartyName(const string& name);
	bool setDate(int year, int month);
	bool setCandidateArr(vector<Candidate*> citizenArr);
	bool setFaction(eFaction tFaction);
	bool setCandidateToParty(Citizen* candidate);
	friend ostream& operator<<(ostream& os, const Party& party);

private:
	static int counter;
	int	sn;
	string partyName;
	Date date;
	vector<Candidate*> candidateArr;
};

#endif // __Party_H