#pragma warning (disable: 4996)

#include <iostream>
#include <fstream>
using namespace std;

#include <string>

#include "Part1Functions.h"
#include "Elections.h"
#include "MilitaryCoronaBB.h"

//Inserts a hard coded valuse to the system
void addFirstValues(Elections& elections)
{
	fstream inFile("Elections.txt");

	elections.setDate(2020, 7);

	elections.addParty("Likud", RIGHT, 1973, 9);
	elections.addParty("Haavoda", LEFT, 1968, 1);
	elections.addParty("Kahol-Lavan", CENTER, 2019, 1);

	elections.addBallotBox("Jaffa", "Gaza", 1, 1);
	elections.addBallotBox("Tel-Aviv", "Ahad Ha'am", 90, 2);
	elections.addBallotBox("Tel-Aviv", "Herzl", 90, 4);
	elections.addBallotBox("Tel-Aviv", "Herzl", 100, 3);

	if (inFile.is_open())
	{
		int size;
		inFile >> size;
		for (int i = 0; i < size; i++)
		{
			string str;
			inFile >> str;
			if (str == (typeid(Citizen).name() + 6))
				elections.addCitizen(Citizen(inFile, (elections.getBallotBox())[0]));
			else if (str == (typeid(Candidate).name() + 6))
				elections.addCandidate(Candidate(inFile, elections.getBallotBox()[0], elections.getParties()[0]));
		}
		inFile.close();
	}

	else
	{
		elections.addCitizen("May", "Tzadoky", 123456789, 1995, 0, false);
		elections.addCitizen("Noam", "Levi", 111111111, 1971, 0, false);
		elections.addCitizen("Noy", "Cohen", 222222222, 1989, 1, false);
		elections.addCitizen("Chen", "Shitrit", 333333333, 1996, 1, false);
		elections.addCitizen("Hadar", "zeri", 444444444, 1954, 2, false);
		elections.addCitizen("Eliram", "Ben", 555555555, 1982, 2, false);

		elections.addCitizenFromParty("Likud", 0);
		elections.addCitizenFromParty("Likud", 1);
		elections.addCitizenFromParty("Haavoda", 3);
		elections.addCitizenFromParty("Haavoda", 4);
		elections.addCitizenFromParty("Kahol-Lavan", 2);
		elections.addCitizenFromParty("Kahol-Lavan", 5);
	}
}

//Gets input for case 1 from the user
void input1(Elections& e)
{
	string city, street;
	int num, type;

	cin >> city >> street >> num >> type;
	while (num <= 0)
	{
		cout << "Apartment number have to be from 0 onwards. Please enter again: ";
		cin >> num;
	}

	while (type > 4 || type < 1)
	{
		cout << "Type does not exist. Enter a number between 1 and 4: ";
		cin >> type;
	}

	e.addBallotBox(city, street, num, type);
}

//Check which ballot box is it
bool input2ValidityCheck(Elections& e, bool flag, int cSn, bool isQuarantined, int cYear)
{
	flag = e.checkSn(cSn); //if the sn exist
	if (flag)
	{
		if (!isQuarantined && !(typeid(*(e.getBallotBox())[cSn]) == typeid(MilitaryBB)) && (e.checkIsSoldier(cYear)))
		{
			cout << "you must choose Military ballot box.\n\n";
			e.showBallotBox();
			flag = false;
		}
		else if (isQuarantined && !(typeid(*(e.getBallotBox())[cSn]) == typeid(MilitaryCoronaBB)) && (e.checkIsSoldier(cYear)))
		{
			cout << "you must choose Military-Corona ballot box.\n\n";
			e.showBallotBox();
			flag = false;
		}
		else if (isQuarantined && !(typeid(*(e.getBallotBox())[cSn]) == typeid(CoronaBB)) && !(e.checkIsSoldier(cYear)))
		{
			cout << "you must choose Corona ballot box.\n\n";
			e.showBallotBox();
			flag = false;
		}
		else if (!isQuarantined && !(typeid(*(e.getBallotBox())[cSn]) == typeid(BallotBox)) && !(e.checkIsSoldier(cYear)))
		{
			cout << "you must choose regular ballot box.\n\n";
			e.showBallotBox();
			flag = false;
		}
		else
			flag = true;
	}
	return flag;
}

//Gets input for case 2 from the user
void input2(Elections& e)
{
	int id, cYear, cSn;
	string fName, lName;
	char answer;
	bool isQuarantined, flag = false, valid = false;

	cin >> fName >> lName;
	while (!valid)
	{
		try
		{
			cin >> cYear;;
			e.checkCitizenBirthYear(cYear);
			valid = true;

		}
		catch (const char* msg)
		{
			cout << msg;
		}
	}
	cin >> answer;
	answer == 'y' ? isQuarantined = true : isQuarantined = false;

	valid = false;
	while (!flag) //Validity check
	{
		cin >> cSn;
		flag = input2ValidityCheck(e, flag, cSn, isQuarantined, cYear);
	}

	while (!valid)
	{
		try
		{
			cin >> id;
			e.addCitizen(fName, lName, id, cYear, cSn, isQuarantined);
			valid = true;
		}
		catch (const char* msg)
		{
			cout << msg;
		}
	}

	cout << endl << "The Citizen was successfully added!" << endl;
}

//Gets input for case 3 from the user
void input3(Elections& e)
{
	int fnum, year, month;
	eFaction faction;
	bool valid = false;

	cin >> fnum;
	while (fnum > 2 || fnum < 0)
	{
		cout << "The faction is invalid, please enter facion between 0-2: \n";
		cin >> fnum;
	}
	cin >> year;
	while (year > 2020)
	{
		cout << "The year is invalid, please try again \n";
		cin >> year;
	}
	cin >> month;
	while (month < 1 || month > 12)
	{
		cout << "The month is invalid, please enter month between 1-12 \n";
		cin >> month;
	}
	faction = (eFaction)fnum;
	string name;

	while (!valid)
	{
		try
		{
			cin >> name;
			e.addParty(name, faction, year, month);
			valid = true;
		}
		catch (const char* msg)
		{
			cout << msg;
		}
	}
}

//Gets input for case 4 from the user
void input4(Elections& e)
{
	string partyName;
	bool valid = false;
	int cId;
	cin >> cId;

	int flag = e.SearchId(cId);
	if (flag == -1) // citizen doesn't exist
		cout << "the ID: " << cId << " doesn't exist in the system." << endl;

	else
	{
		if (e.IsCandidate(flag))
			cout << "This citizen is already a candidate." << endl;
		else
		{
			while (!valid)
			{
				try
				{
					cout << "Please enter the party's name: ";
					cin >> partyName;
					e.addCitizenFromParty(partyName, flag);
					valid = true;
				}

				catch (const char* msg)
				{
					cout << "A party name must be selected from the following list:" << endl;
					e.showParty();
				}
			}
		}
		cout << endl << "The process is complete!" << endl;
	}
	for (int j = 0; j < 3; j++)
	{
		cout << *e.getParties()[j] << endl;
		for (int i = 0; i < e.getParties()[j]->getCandidateArr().size(); i++)
		{
			cout << (typeid(*(e.getParties()[j]->getCandidateArr()[i])).name() + 6) << " "; 
			cout << *(e.getParties()[j]->getCandidateArr()[i]) << endl;
		}
	}
}

//Gets input for case 8 from the user
void input8(Elections& e)
{
	char answer = '0';
	string selectedParty;
	bool valid = false;

	for (int i = 0; i < (e.getCitizens().size()); i++)
	{
		if (!e.IsVoted(e.getCitizens()[i]))
		{
			cout << (e.getCitizens()[i])->getId() << ": Do you want to vote? (y/n) ";
			cin >> answer;

			if (answer == 'y')
			{
				while (!valid)
				{
					try
					{
						cout << "Please select a party: ";
						cin >> selectedParty;
						e.chooseParty(selectedParty, i);
						valid = true;
					}
					catch (const char*)
					{
						cout << "A party name must be selected from the following list:" << endl;
						e.showParty();
					}
				}
				valid = false;
			}
		}
	}
	cout << "The election's finished." << endl;
}

void input10(Elections& e)
{
	ofstream outFile("Elections.txt");
	int size = e.getCitizens().size();
	outFile << size << " ";
	for (int i = 0; i < size; i++)
	{
		outFile << typeid(*e.getCitizens()[i]).name() + 6 << " " << *e.getCitizens()[i] << " ";
	}
	outFile.close();
}

