//
//  driver.cpp
//  Program2Platypus
//  COMPE 260 Spring 18
//
//  Created by Nicholas Sullivan on 2/22/18.
//  Copyright © 2018 Nicholas Sullivan. All rights reserved.
//

#include <iostream>
#include "Platypus.h"
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

// Global variables and function prototypes
int rand();
int monthCounter = 0,
mealCounter;
char platypus1, platypus2;

void ageAll(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e);
void eatAll(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e);
void listAlive(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e);
bool allDead(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e);
bool oneLeft(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e);
void continueSim();
void finalResults(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e, int time);

int main(int argc, const char * argv[]) {

	// Declare variables.
	char cont = '\0',
		simChoice = '\0';
	bool contSim = false,
		isValid = false,
		isValidAmount = false;
	int ageCounter = 0,
		eatCounter = 0;

	srand((unsigned int)time(NULL));

	// Output instructions
	cout <<
		"************************************************\n"
		"*                                              *\n"
		"*                                              *\n"
		"*      Welcome to the Platypus Simulator.      *\n"
		"*      Four platypuses will be simulated,      *\n"
		"*      they will be 50% male and 50% female.   *\n"
		"*      This simulation will show us how        *\n"
		"*      they behave and how they are being      *\n"
		"*      affected by the radioactive goo         *\n"
		"*      leaking from the power plant.           *\n"
		"*                                              *\n"
		"*      Simulation will run until all           *\n"
		"*      platypuses are dead.                    *\n"
		"*                                              *\n"
		"*                                              *\n"
		"*                                              *\n"
		"*          Begin Simulation? (Y/N)             *\n"
		"*                                              *\n"
		"*                                              *\n"
		"************************************************\n"
		<< endl;

	while (!contSim)
	{
		cin >> cont;
		cin.clear();
		cin.ignore(999, '\n');

		if (cont == 'Y' || cont == 'y')
		{
			contSim = true;
		}
		else if (cont == 'N' || cont == 'n')
		{
			cout << "*** Simulation Terminated. ***" << endl;
			return 0;
		}
		else
			cout << "Please input  Y/N" << endl;
	}

	/*
	-Creates the four platypus objects with random values (except for name and gender).
	-Weight is randomly set between 1 lbs and 10 lbs.
	-Age is randomly set between 1 month and 12 months.
	-Gender will be equal parts male and female (two each).
	-Parameters are weight, age, name, and gender. Alive defaults to true, and mutant defaults to false.
	 */

	Platypus P0(rand() % 10 + 1, rand() % 12 + 1, 'A', 'M');
	Platypus P1(rand() % 10 + 1, rand() % 12 + 1, 'B', 'M');
	Platypus P2(rand() % 10 + 1, rand() % 12 + 1, 'C', 'F');
	Platypus P3(rand() % 10 + 1, rand() % 12 + 1, 'D', 'F');

	// Create a 5th for the hatch function.
	Platypus PNB;

	cout << endl << "*** These are the first four platypuses in the simulation: ***" << endl << endl;
	cout << P0 << P1 << P2 << P3 << endl;
	cout << "*** Please scroll up to see the first four platypuses in the simulation. ***" << endl << endl;

	continueSim();

	// Hatches the new platypus so it can be used for the rest of the simulation.
	PNB.hatch();
	cout << endl << PNB;

	// Continue simulation.
	// Checks until there's one platypus left.
	while (!oneLeft(P0, P1, P2, P3, PNB) && !allDead(P0, P1, P2, P3, PNB))
	{
		continueSim();

		cout << endl <<
			"***********************************************************\n"
			"*                                                         *\n"
			"*           What would you like to simulate?              *\n"
			"*                                                         *\n"
			"*                                                         *\n"
			"*       Eat?     Age?      Fight?      Output stats       *\n"
			"*       (E)      (A)        (F)            (O)            *\n"
			"*                                                         *\n"
			"***********************************************************\n";

		isValid = false;
		simChoice = '\0';

		// User can pick to simulate eat, age, fight, or to output stats.
		while (!isValid)
		{
			simChoice = '\0';
			cin >> simChoice;
			cin.clear();
			cin.ignore(999, '\n');

			// If user chooses to simulate eating.
			if (simChoice == 'E' || simChoice == 'e')
			{
				isValid = true;
				isValidAmount = false;

				// Can choose how man iterations of eating to help speed up simulation.
				cout << "How many times should they eat? (1-10)" << endl;

				eatCounter = 0;

				while (!isValidAmount)
				{
					cin >> eatCounter;
					cin.clear();
					cin.ignore(999, '\n');

					if (eatCounter >= 1 && eatCounter <= 10)
					{
						isValidAmount = true;
						cout << endl;
						for (int i = 0; i < eatCounter; i++)
						{
							mealCounter++;
							cout << endl << "*** After " << mealCounter << " meal(s): ***" << endl;
							eatAll(P0, P1, P2, P3, PNB);
						}
					}
					else
						cout << "*** Invalid input. Please choose again. ***" << endl;
				}

			}
			// If user chooses to simulate aging.
			else if (simChoice == 'A' || simChoice == 'a')
			{
				isValid = true;
				isValidAmount = false;

				// Can choose how man iterations of aging to help speed up simulation.
				cout << "How many months should they age? (1-12)" << endl;

				ageCounter = 0;

				while (!isValidAmount)
				{
					cin >> ageCounter;
					cin.clear();
					cin.ignore(999, '\n');

					if (ageCounter >= 1 && ageCounter <= 12)
					{
						isValidAmount = true;
						cout << endl;
						for (int i = 0; i < ageCounter; i++)
						{
							monthCounter++;
							cout << endl << "*** After " << monthCounter << " month(s): ***" << endl;
							ageAll(P0, P1, P2, P3, PNB);
						}
					}
					else
						cout << "*** Invalid input. Please choose again. ***" << endl;
				}
			}
			// If user chooses to output the current stats of all platypuses.
			else if (simChoice == 'O' || simChoice == 'o')
			{
				isValid = true;
				cout << endl << "*** These are the current stats of each Platypus: ***" << endl << endl;
				cout << P0 << P1 << P2 << P3 << PNB;
			}
			// If user chooses to simulate fighting
			else if (simChoice == 'F' || simChoice == 'f')
			{
				isValid = true;
				isValidAmount = false;

				cout << endl << "*** Which two platypuses should fight? ***" << endl;

				while (!isValidAmount)
				{
					platypus1 = 0;
					platypus2 = 0;

					cout << "Please enter the name of the first platypus:" << endl;

					cin >> platypus1;
					cin.clear();
					cin.ignore(999, '\n');

					cout << "Please enter the name of the second platypus:" << endl;

					cin >> platypus2;
					cin.clear();
					cin.ignore(999, '\n');

					// Checks to make sure input platypuses exist, are alive, and aren't duplicates.
					if ((platypus1 == P0.getName() || platypus1 == P1.getName() || platypus1 == P2.getName() || platypus1 == P3.getName() || platypus1 == PNB.getName()) && (platypus2 == P0.getName() || platypus2 == P1.getName() || platypus2 == P2.getName() || platypus2 == P3.getName() || platypus2 == PNB.getName()) && (platypus2 != platypus1))
					{
						// if's to assign Platypus objects based on user's input.

						if (platypus1 == P0.getName() && platypus2 == P1.getName() && P0.getAlive() && P1.getAlive())
						{
							isValidAmount = true;
							P0.fight(P1);
						}
						else if (platypus1 == P0.getName() && platypus2 == P2.getName() && P0.getAlive() && P2.getAlive())
						{
							isValidAmount = true;
							P0.fight(P2);
						}
						else if (platypus1 == P0.getName() && platypus2 == P3.getName() && P0.getAlive() && P3.getAlive())
						{
							isValidAmount = true;
							P0.fight(P3);
						}
						else if (platypus1 == P0.getName() && platypus2 == PNB.getName() && P0.getAlive() && PNB.getAlive())
						{
							isValidAmount = true;
							P0.fight(PNB);
						}
						else if (platypus1 == P1.getName() && platypus2 == P2.getName() && P1.getAlive() && P2.getAlive())
						{
							isValidAmount = true;
							P1.fight(P2);
						}
						else if (platypus1 == P1.getName() && platypus2 == P3.getName() && P1.getAlive() && P3.getAlive())
						{
							isValidAmount = true;
							P1.fight(P3);
						}
						else if (platypus1 == P1.getName() && platypus2 == PNB.getName() && P1.getAlive() && PNB.getAlive())
						{
							isValidAmount = true;
							P1.fight(PNB);
						}
						else if (platypus1 == P2.getName() && platypus2 == P3.getName() && P2.getAlive() && P3.getAlive())
						{
							isValidAmount = true;
							P2.fight(P3);
						}
						else if (platypus1 == P2.getName() && platypus2 == PNB.getName() && P2.getAlive() && PNB.getAlive())
						{
							isValidAmount = true;
							P2.fight(PNB);
						}
						else if (platypus1 == P3.getName() && platypus2 == PNB.getName() && P3.getAlive() && PNB.getAlive())
						{
							isValidAmount = true;
							P3.fight(PNB);
						}
						else if (platypus1 == P1.getName() && platypus2 == P0.getName() && P0.getAlive() && P1.getAlive())
						{
							isValidAmount = true;
							P1.fight(P0);
						}
						else if (platypus1 == P2.getName() && platypus2 == P0.getName() && P0.getAlive() && P2.getAlive())
						{
							isValidAmount = true;
							P2.fight(P0);
						}
						else if (platypus1 == P3.getName() && platypus2 == P0.getName() && P0.getAlive() && P3.getAlive())
						{
							isValidAmount = true;
							P3.fight(P0);
						}
						else if (platypus1 == PNB.getName() && platypus2 == P0.getName() && P0.getAlive() && PNB.getAlive())
						{
							isValidAmount = true;
							PNB.fight(P0);
						}
						else if (platypus1 == P2.getName() && platypus2 == P1.getName() && P1.getAlive() && P2.getAlive())
						{
							isValidAmount = true;
							P2.fight(P1);
						}
						else if (platypus1 == P3.getName() && platypus2 == P1.getName() && P1.getAlive() && P3.getAlive())
						{
							isValidAmount = true;
							P3.fight(P1);
						}
						else if (platypus1 == PNB.getName() && platypus2 == P1.getName() && P1.getAlive() && PNB.getAlive())
						{
							isValidAmount = true;
							PNB.fight(P1);
						}
						else if (platypus1 == P3.getName() && platypus2 == P2.getName() && P2.getAlive() && P3.getAlive())
						{
							isValidAmount = true;
							P3.fight(P2);
						}
						else if (platypus1 == PNB.getName() && platypus2 == P2.getName() && P2.getAlive() && PNB.getAlive())
						{
							isValidAmount = true;
							PNB.fight(P2);
						}
						else if (platypus1 == PNB.getName() && platypus2 == P3.getName() && P3.getAlive() && PNB.getAlive())
						{
							isValidAmount = true;
							PNB.fight(P3);
						}

					}
					else
					{
						cout << endl << "*** Invalid input.***" << endl;
						cout << "Platypus might not exist, might be a duplicate, or might already be dead." << endl;
						cout << "*** Please choose again. ***" << endl << endl;
						cout << "These are the remaining alive platypuses:" << endl;
						listAlive(P0, P1, P2, P3, PNB);
						cout << endl;
					}
				}
			}
			else
			{
				cout << "*** Invalid input. Please choose again. ***" << endl;
			}
		}
	} // end oneLeft && allDead

	cout << endl << "*** All platypuses are dead. Please continue to see final results of simulation. ***" << endl;
	continueSim();

	// Outputs the final amount of months the simulation ran for and how many platypuses became mutants.
	finalResults(P0, P1, P2, P3, PNB, monthCounter);
	return 0;
} // end main

/*** Utility Functions -- Definitions ***/

// Calls the ageMe function for all platypuses at once.
void ageAll(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e)
{
	a.ageMe();
	b.ageMe();
	c.ageMe();
	d.ageMe();
	e.ageMe();
}

// Calls the eat function for all platypuses at once.
void eatAll(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e)
{
	a.eat();
	b.eat();
	c.eat();
	d.eat();
	e.eat();
}

// Lists all the platypuses that are still alive.
void listAlive(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e)
{
	if (a.getAlive())
		cout << "Platypus: '" << char(a.getName()) << "'" << endl;
	if (b.getAlive())
		cout << "Platypus: '" << char(b.getName()) << "'" << endl;
	if (c.getAlive())
		cout << "Platypus: '" << char(c.getName()) << "'" << endl;
	if (d.getAlive())
		cout << "Platypus: '" << char(d.getName()) << "'" << endl;
	if (e.getAlive())
		cout << "Platypus: '" << char(e.getName()) << "'" << endl;
}

// Pauses the simulation and prompts the user to continue.
void continueSim()
{
	cout << endl << "Continue? Y/N" << endl;
	char cont = '\0';
	bool contSim = false;

	while (!contSim)
	{
		cin >> cont;
		cin.clear();
		cin.ignore(999, '\n');

		if (cont == 'Y' || cont == 'y')
		{
			contSim = true;
		}
		else
		{
			cout << "Please input Y when ready." << endl;
		}
	}
}

// Checks to see if all of the platypuses are dead to end the simulation.
bool allDead(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e)
{
	if (a.getAlive() == true || b.getAlive() == true || c.getAlive() == true || d.getAlive() == true || e.getAlive() == true)
	{
		return false;
	}
	else
		return true;
}

// Checks to see if only one platypus is left alive. If so it runs the rest of the simulation automatically.
bool oneLeft(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e)
{
	int platypusAlive = 0;
	if (a.getAlive() == true)
		platypusAlive++;
	if (b.getAlive() == true)
		platypusAlive++;
	if (c.getAlive() == true)
		platypusAlive++;
	if (d.getAlive() == true)
		platypusAlive++;
	if (e.getAlive() == true)
		platypusAlive++;
	if (platypusAlive == 1)
	{
		cout << endl <<
			"******************************************************\n"
			"*                                                    *\n"
			"*          Only one platypus is still alive.         *\n"
			"*    The simulation will now finish automatically.   *\n"
			"*                                                    *\n"
			"******************************************************\n"
			<< endl;

		continueSim();
		while (!allDead(a, b, c, d, e))
		{
			mealCounter++;
			cout << endl << "*** After " << mealCounter << " meal(s): ***" << endl;
			eatAll(a, b, c, d, e);
			cout << endl << endl;

			monthCounter++;
			cout << endl << "*** After " << monthCounter << " month(s): ***" << endl;
			ageAll(a, b, c, d, e);
			cout << endl << endl;
		}
		return true;
	}
	else
		return false;
}

// Outputs the final amount of months the simulation ran for, and how many platypuses became mutants.
void finalResults(Platypus & a, Platypus & b, Platypus & c, Platypus & d, Platypus & e, int time)
{

	int mutantCounter = 0;
	if (a.getMutant())
		mutantCounter++;
	if (b.getMutant())
		mutantCounter++;
	if (c.getMutant())
		mutantCounter++;
	if (d.getMutant())
		mutantCounter++;
	if (e.getMutant())
		mutantCounter++;

	char val = 0;
	char val2 = 0;

	if (time >= 100)
		val = '\0';
	else if (time >= 10 && time < 100)
		val = ' ';
	else
	{
		val = ' ';
		val2 = ' ';
	}

	cout << endl << endl <<
		"************************************************\n"
		"*                                              *\n"
		"*           All platypuses are dead!           *\n"
		"*                                              *\n"
		"*         These are the final results:         *\n"
		"*                                              *\n"
		"*       Length of simulation: " << time << " month(s)." << val << val2 << "    *\n"
		"*        " << mutantCounter << "/5 platypuses became mutants.        *\n"
		"*                                              *\n"
		"*                                              *\n"
		"*                                              *\n"
		"*        *** Simulator Terminating ***         *\n"
		"*                                              *\n"
		"************************************************\n"
		<< endl << endl;
}
