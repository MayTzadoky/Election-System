#include <iostream>
#include <fstream>

using namespace std;

#include <algorithm>

#include "Elections.h"
#include "Part1Functions.h"
#include "Candidate.h"
#include "MilitaryCoronaBB.h"
#include "Party.h"

#define SIZE_HCB 4 // hard code of BB
#define SIZE__HCP 3 // hard code of Party

//c'tor
Elections::Elections(Date& date) :
	date(date)
{
}

//move c'tor
Elections::Elections(Elections&& elections) :
	date(elections.date)
{
	citizens = elections.citizens;
	ballotBoxes = elections.ballotBoxes;
	parties = elections.parties;
}

//d'tor
Elections::~Elections()
{
	for (int i = 0; i < citizens.size(); i++)
		delete citizens[i];
	for (int i = 0; i < ballotBoxes.size(); i++)
		delete ballotBoxes[i];
	for (int i = 0; i < parties.size(); i++)
		delete parties[i];
}

//Adds a new ballot box to ballotBoxes array
void Elections::addBallotBox(const string& city, const string& street, int num, int type)
{

	if (ballotBoxes.size() == ballotBoxes.capacity())
		ballotBoxes.reserve(ballotBoxes.size() * 2);

	switch (type)
	{
	case 1: // regular BB
	{
		BallotBox* ballotBox = new BallotBox(parties.capacity(), parties.size(), city, street, num);
		ballotBoxes.push_back(ballotBox);
	}
	break;
	case 2: // Corona BB
	{
		CoronaBB* temp = new CoronaBB(BallotBox(parties.capacity(), parties.size(), city, street, num));
		ballotBoxes.push_back(temp);
	}
	break;
	case 3: // Military BB
	{
		MilitaryBB* temp = new MilitaryBB(BallotBox(parties.capacity(), parties.size(), city, street, num));
		ballotBoxes.push_back(temp);
	}
	break;
	case 4: //Military-Corona bb
	{
		MilitaryCoronaBB* temp = new MilitaryCoronaBB(BallotBox(parties.capacity(), parties.size(), city, street, num));
		ballotBoxes.push_back(temp);
	}
	break;
	}
	if (ballotBoxes.size() > SIZE_HCB)
		cout << endl << "The ballot box added successfully!" << endl;
}

//adds a citizen to array
void Elections::addCitizen(Citizen& temp)
{
	Citizen* citizen = new Citizen(temp);

	*this += citizen;
	ballotBoxes[0]->updateCitizenArr(citizen);
}

//Adds a new citizen to citizens array
void Elections::addCitizen(const string& fName, const string& lName, int cId, int cYear, int sn, bool isQuarantined) throw(const char*)
{
	Citizen temp(fName, lName, cId, cYear, ballotBoxes[sn], isQuarantined);
	int flag = SearchId(cId);
	if (flag >= 0)
	{
		throw "This ID number already exists in the system.\nPlease enter ID again: ";
	}

	Citizen* citizen = new Citizen(temp);
	*this += citizen;
	ballotBoxes[sn]->updateCitizenArr(citizen);
}

//Checks if birth year is valid
void Elections::checkCitizenBirthYear(int cYear)
{
	if (cYear > 2002)
		throw "Birth Year should be smaller than 2002. \nPlease enter birth year again: ";
}

//Adds new citizen to the citizens array
const Elections& Elections::operator+=(Citizen* citizen)
{
	if (citizens.size() == citizens.capacity())
		citizens.reserve(citizens.size() * 2);

	citizens.push_back(citizen);
	return *this;
}

//Checks if the name of the party already exists
int Elections::searchParty(const string& name) const
{
	for (int i = 0; i < parties.size(); i++)
	{
		if (name == parties[i]->getPartyName())
		{
			return i;
		}
	}
	return -1;
}

//Adds a new party to parties array
void Elections::addParty(const string& name, eFaction faction, int year, int month) throw(const char*)
{
	if (parties.size() == parties.capacity())
		parties.reserve(parties.size() * 2);

	int flag = searchParty(name);
	if (flag >= 0)
	{
		throw "Party name already exist, please try again. \n";
	}
	Party* party = new Party(name, faction, year, month);

	for (int i = 0; i < ballotBoxes.size(); i++)
		ballotBoxes[i]->setResults();

	parties.push_back(party);

	if (parties.size() > SIZE__HCP)
		cout << endl << "The Party was successfully added!" << endl;
}

//Adds a new candidate to candidates array
void Elections::addCandidate(Candidate& candidate)
{
	int i = searchParty(candidate.getParty()->getPartyName());

	Candidate* newCandidate = new Candidate(candidate);

	if (citizens.size() == citizens.capacity())
		citizens.reserve(citizens.size() * 2);

	citizens.push_back(newCandidate);
	*parties[i] += newCandidate;
}

//Adds a new candidate to candidates array
void Elections::addCitizenFromParty(const string& partyName, int index) throw(const char*)
{
	int i = searchParty(partyName);

	if (i == -1)
	{
		throw "This party doesn't exist in the system.";
	}

	Candidate* newCandidate = new Candidate(*citizens[index], parties[i]);
	Citizen* citizen = citizens[index];
	citizens[index] = dynamic_cast<Candidate*>(newCandidate);
	delete citizen;
	*parties[i] += newCandidate;
}

//Updates elections date 
bool Elections::setDate(int year, int month)
{
	if (date.setEYear(year) && date.setMonth(month))
		return true;
	else
		return false;
}

//returns the citizen's location in the array if it exists. If not, return -1
int Elections::SearchId(int id) const
{
	int end = citizens.size();
	for (int i = 0; i < end; i++)
	{
		if (citizens[i]->getId() == id)
			return i;
	}

	return -1;
}

//Prints all the ballot boxes
void Elections::showBallotBox()	const
{
	for (int i = 0; i < ballotBoxes.size(); i++)
	{
		cout << (*ballotBoxes[i]);
	}
}

//Prints all the citizens
void Elections::showCitizen() const
{
	for (int i = 0; i < citizens.size(); i++)
		cout << (*citizens[i]);
}

//Prints all the parties
void Elections::showParty() const
{
	for (int i = 0; i < parties.size(); i++)
		cout << (*parties[i]);
}

//Votes to specific party
void Elections::chooseParty(const string& selectedParty, int i) throw(const char*)
{
	int index = searchParty(selectedParty);

	if (index == -1)
	{
		throw "This party doesn't exist in the system.";
	}

	(citizens[i]->getBallotBox())->updateSelectionInBB(index);
	(citizens[i]->getBallotBox())->updatePercentOfVoters();
	updateIsVoted(i);
	cout << "Your choice has been successfully accepted!" << endl;
}

//Prints the elections results
void Elections::showElectionsResult() const
{
	vector<int> sumResults;
	sumResults.reserve(parties.size());

	for (int k = 0; k < parties.size(); k++)
		sumResults.push_back(0);

	for (int i = 0; i < ballotBoxes.size(); i++)
	{
		if (i > 0)
			cout << "------" << endl;
		if (typeid(*ballotBoxes[i]) == typeid(MilitaryCoronaBB))
			cout << "In militray-corona ballot box no. " << ballotBoxes[i]->getSn() << " the voting percentage is " << ballotBoxes[i]->getPercentOfVoters() << "%." << endl;
		else if (typeid(*ballotBoxes[i]) == typeid(CoronaBB))
			cout << "In corona ballot box no. " << ballotBoxes[i]->getSn() << " the voting percentage is " << ballotBoxes[i]->getPercentOfVoters() << "%." << endl;
		else if (typeid(*ballotBoxes[i]) == typeid(MilitaryBB))
			cout << "In military ballot box no. " << ballotBoxes[i]->getSn() << " the voting percentage is " << ballotBoxes[i]->getPercentOfVoters() << "%." << endl;
		else if (typeid(*ballotBoxes[i]) == typeid(BallotBox))
			cout << "In regular ballot box no. " << ballotBoxes[i]->getSn() << " the voting percentage is " << ballotBoxes[i]->getPercentOfVoters() << "%." << endl;

		for (int j = 0; j < parties.size(); j++)
		{
			cout << "The " << parties[j]->getPartyName() << " party recieved: " << ballotBoxes[i]->getElectionResults(j) << " votes." << endl;
			sumResults[j] += ballotBoxes[i]->getElectionResults(j);
		}
	}
	cout << "------\nTotal:" << endl;
	for (int i = 0; i < parties.size(); i++)
		cout << "The " << parties[i]->getPartyName() << " party recieved " << sumResults[i] << " votes." << endl;
}

//Prints a date
void Elections::showElectionsDate() const
{
	cout << date;
}

//Updates if the citizen already voted 
void Elections::updateIsVoted(int i)
{
	citizens[i]->setIsVoted(true);
}

//Gets the parties array
vector <Party*> Elections::getParties() const
{
	return parties;
}

//Gets the citizens array
vector <Citizen*> Elections::getCitizens() const
{
	return citizens;
}

//Gets the ballotBoxes array
vector <BallotBox*> Elections::getBallotBox() const
{
	return ballotBoxes;
}

//Checks is the citizen voted already 
bool Elections::IsVoted(Citizen* citizen) const
{
	return citizen->getIsVoted();
}

//Checks is the citizen is a soldier
bool Elections::IsSoldier(Citizen* citizen) const
{
	return citizen->getIsSoldier();
}

bool Elections::checkIsSoldier(int year) const
{
	if (year >= 2000 && year <= 2002)
		return true;
	else
		return false;
}

//Checks if a citizen is a candidate
bool Elections::IsCandidate(int i) const
{
	return ((typeid(*citizens[i])) == typeid(Candidate));
}

//Get date of the elections
Date Elections::getDate()	const
{
	return date;
}

//Check if the Serial Number of the ballot box is valid 
bool Elections::checkSn(int tmpSn)
{
	if (tmpSn >= 0 && tmpSn <= ballotBoxes.size() - 1)
		return true;

	else
	{
		cout << "Sn have to be a number between 0 - " << ballotBoxes.size()-1 << " . Value is unchanged. \n" << endl;
		return false;
	}
}


////Updates the citizens array
bool Elections::setCitizens(vector<Citizen*>& citizenArr)
{
	citizens = citizenArr;
	return true;
}

//Updates the parties array
bool Elections::setParties(vector<Party*> partyArr)
{
	parties = partyArr;
	return true;
}

//Updates the ballot box array
bool Elections::setBallotBox(vector<BallotBox*> ballotBoxArr)
{
	ballotBoxes = ballotBoxArr;
	return true;
}