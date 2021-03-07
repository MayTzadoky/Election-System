#include <iostream>
#include <fstream>
using namespace std;



#include "Part1Functions.h"

void main()
{
	Date date(2020, 7);
	Elections elections(date);
	int num;

	addFirstValues(elections);
	cout << "Welcome to the elections round!\n\t- ";
	elections.showElectionsDate();
	cout << " -" << endl;
	while (true)
	{
		cout << "\nPlease choose a number (1-10):\n 1- to add a ballot box\n 2- to add a citizen\n 3- to add a party\n";
		cout << " 4- to add a candidate to party\n 5- to display the ballot boxes\n 6- to display the citizens\n";
		cout << " 7- to display the parties\n 8- to vote\n 9- to see the results\n 10- to close the menu\n";
		cin >> num;
		switch (num)
		{
		case 1:
		{
			cout << "\nPlease enter:\n 1) the city of the ballot-box: \n 2) the street of the ballot-box: \n";
			cout << " 3) the apartment number: \n 4) type:(regular-1, corona-2, military-3, corona-military-4) \n";
			input1(elections);
		}
		break;
		case 2:
		{
			cout << "Please enter:\n 1) first name: \n 2) last name: \n 3) year of birth: \n";
			cout << " 4) Are you in quarantine? (y/n): \n 5) SN of your ballot box: \n 6) ID: \n";
			input2(elections);
		}
		break;
		case 3:
		{
			cout << "please enter:\n 1) faction:(RIGHT-0, CENTER-1, LEFT-2) \n";
			cout << " 2) year of party establishment: \n 3) month: \n 4) the name of the party: \n";
			input3(elections);
		}
		break;
		case 4:
		{
			cout << "Please enter the candidate's ID: ";
			input4(elections);
		}
		break;
		case 5:
			elections.showBallotBox();
			break;
		case 6:
			elections.showCitizen();
			break;
		case 7:
			elections.showParty();
			break;
		case 8:
			input8(elections);
			break;
		case 9:
			elections.showElectionsResult();
			break;
		case 10:
			cout << "Menu closed" << endl;
			input10(elections);
			system("pause");
			return;
		}
	}
}