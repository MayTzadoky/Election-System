#ifndef __Citizen_H
#define __Citizen_H
#include <iostream>
#include <string>
using namespace std;

class BallotBox;

class Citizen
{
protected:
	string firstN;
	string lastN;
	int id;
	int birthYear;
	bool isVoted;
	bool isQuarantined;
	bool isSoldier;
	BallotBox* ballotBox;

public:
	Citizen(const string& fName, const string& lName, int cId, int cYear, BallotBox* bb, bool isQuarantined) throw(const char*);
	Citizen(fstream& in, BallotBox* bb);
	const string& getFirstN();
	const string& getLastN();
	int getId()					const;
	int getBirthYear()			const;
	bool getIsVoted()			const;
	bool getIsSoldier()			const;
	bool getIsQuarantined()		const;
	BallotBox* getBallotBox()	const;

	bool setFirstN(const string& fname);
	bool setLastN(const string& lname);
	bool setId(int num);
	bool setBYear(int year);
	bool setIsVoted(bool isVoted);
	bool setSoldier(int year);
	bool setIsQuarantined(bool isQuarantined);
	bool setBallotBox(BallotBox* bb);

	virtual void toOs(ostream& os) const;
	friend ostream& operator<<(ostream& out, const Citizen& citizen);
};
#endif // __Citizen_H