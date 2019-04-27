//
//Driver.cpp
//Blood Sugar Project Driver file
//Wilhelm Muggenburg
//COSC2030, Fall 2018

#include "info.h"
#include<iostream>
#include <stdlib.h>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	//Day and Week Counters
	int dayInc = 0;
	int	weekInc = 0;

	//This creates the needed arrays for days and weeks and sets length
	info Days[14];
	info Weeks[2];

	string input;

	// 
	cout << "Please Select an option from the list Provided:"
		<< "\nEnter D/Day to get the summary of readings for the day (so far)"
		<< "\nEnter W/Week to get the summary of readings for the week (so far)"
		<< "\nEnter 'N'/'Next' to go to the next day."
		<< "\nEnter 'Q'/'Quit' to exit the program."
		<< "\nOr Enter a non Negative blood sugar reading to Start recording data"
		<< "\n" << endl;

	// This while loop continues until day 14 or the program is terminated
	while (weekInc <= 1 && dayInc < 13)
	{

		cin >> input;

		if (input == "Day" || input == "D" || input == "d")
		{
			//report daily summaries
			cout << "\nDaily Summaries for Day " << dayInc + 1 << " are as follows:" //since counter started at 0, add 1 for outputs
				<< "\nThe max of all blood sugar readings recorded today is " << Days[dayInc].retMax() 
				<< "\nThe min of all blood sugar readings recorded today is " << Days[dayInc].retMin() 
				<< "\nThe total number of valid blood sugar readings recorded today is " << Days[dayInc].retCount() 
				<< "\nThe sum of all blood sugar readings for today is " << Days[dayInc].retSum() 
				<< "\nThe average of all blood sugar readings for today is " << Days[dayInc].retAv() << endl;
		}

		if (input == "Week" || input == "week" || input == "W" || input == "w")
		{

			cout << "\nWeekly summaries, so far, for week " << weekInc + 1 << " are as follows:"//since counter started at 0, add 1 for outputs
				<< "\nThe max of the blood sugar readings recorded for this week is " << Weeks[weekInc].retMax()
				<< "\nThe min of the blood sugar readings recorded for this week is " << Weeks[weekInc].retMin()
				<< "\nThe total number of valid blood sugar readings recorded for this week is " << Weeks[weekInc].retCount()
				<< "\nThe sum of all blood sugar readings for this week is " << Weeks[weekInc].retSum() 
				<< "\n The average of all blood sugar readings for today is " << Weeks[weekInc].retAv()<< endl;
			
			
		}
	
				if (input == "Quit" || input == "quit"|| input == "q" || input == "Q")
		{
			break;
		}
		
		if (input == "Next" || input == "next" || input == "N" || input == "n")
		{
			if (dayInc < 13)
			{
				// Increment the day if the number of days is less than 13
				dayInc++;
				if (dayInc == 7)
				{
					weekInc++;
				}
			}
			else
			{
				/* This Outputs the Week 2 Data after the 14th day has been completed and the user attempts to Continue to the 
				next day*/
				
				cout << "\nThis is now the end of 2 Weeks, now printing week 2 summaries:" << endl;
			cout << "\nWeekly summary for week " << weekInc + 1 << " are as follows:"//since counter started at 0, add 1 for outputs
				<< "\nThe max of the blood sugar readings recorded for this week is " << Weeks[weekInc].retMax()
				<< "\nThe min of the blood sugar readings recorded for this week is " << Weeks[weekInc].retMin()
				<< "\nThe total number of valid blood sugar readings recorded for this week is " << Weeks[weekInc].retCount()
				<< "\nThe sum of all blood sugar readings for this week is " << Weeks[weekInc].retSum() 
				<< "\n The average of all blood sugar readings for today is " << Weeks[weekInc].retAv()<< endl;
				dayInc++, weekInc++;
			}
		}

		else
		{
			/* Any other input will be taken as a data reading or ingnored if it is not a positive value or numerical value
			 then this stores the input as a number in a float */
			float num = ::atof(input.c_str());
			Days[dayInc].inputNum(num);
			Weeks[weekInc].inputNum(num);
		}
	}
	
	system("pause");
	return 0;
}