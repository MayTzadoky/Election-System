#ifndef __Elections_H
#define __Elections_H

#include "Date.h"
#include "Citizen.h"
#include "Party.h"
#include "Ballotbox.h"
#include "Candidate.h"
#include <vector>
#include <string>

class Elections
{
private:
	Date date;
	vector <Citizen*> citizens;
	vector <Party*> parties;
	vector <BallotBox*> ballotBoxes;

public:
	Elections(Date& date);
	Elections(Elections&& elections);
	~Elections();
	Date getDate()							const;
	vector <Citizen*> getCitizens()			const;
	vector <Party*> getParties()			const;
	vector <BallotBox*> getBallotBox()		const;

	bool setDate(int year, int month);
	bool setCitizens(vector <Citizen*>& citizenArr);
	bool setParties(vector<Party*> partyArr);
	bool setBallotBox(vector<BallotBox*> ballotBoxArr);

	void addBallotBox(const string& city, const string& street, int num, int type);
	void addCitizen(const string& fName, const string& lName, int cId, int cYear, int sn, bool isQuarantined);
	void addParty(const string& name, eFaction faction, int year, int month);
	void addCitizenFromParty(const string& partyName, int index);

	bool checkSn(int tmpSn);
	void chooseParty(const string& selectedParty, int i);
	void showBallotBox()						const;
	void showCitizen()							const;
	void showParty()							const;
	void showElectionsResult()					const;
	void showElectionsDate()					const;
	int searchParty(const string&)				const;
	bool IsVoted(Citizen* citizen)				const;
	void updateIsVoted(int i);
	bool IsCandidate(int i)						const;
	bool IsSoldier(Citizen* citizen)			const;
	bool checkIsSoldier(int year)				const;
	const Elections& operator+=(Citizen* citizen);
	int SearchId(int id)	const;
	void checkCitizenBirthYear(int cYear) throw(const char*);
	void addCitizen(Citizen& citizen);
	void addCandidate(Candidate& candidate);
};

#endif // __Elections_H