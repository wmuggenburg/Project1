//
//Driver.cpp
//Blood Sugar Project Driver file
//Wilhelm Muggenburg
//COSC2030, Fall 2018



#include "info.h"
#include<iostream>
#include <stdlib.h>
#include <algorithm>
//#include <sstream> didnt end up needing, originally was going to convert string input to an int for selecting the day and week wanted for data summaries, instead I just created a new variable
using std::cin;
using std::cout;
using std::endl;

int main()
{
	//Day and Week Counters
	int dayInc = 0;
	int	weekInc = 0;

	info Days[14];
	info Weeks[2];

	string input;
	int intput;
	bool exit = false;

	// 
	cout << "Please Select an option from the list Provided:"
		<< "\nEnter a non Negative blood sugar reading to Start recording data"
		<< "\nEnter D/Day to get the summary of readings for the day (so far)"
		<< "\nEnter W/Week to get the summary of readings for the week (so far)"
		<< "\nEnter 'N'/'Next' to go to the next day."
		<< "\nor Enter 'Q'/'Quit' to exit the program."
		<< "\n" << endl;

	// This while loop continues until quit is selected
	while (exit == false)
	{

		cin >> input;
			std::transform(input.begin(), input.end(), input.begin(), ::tolower); //https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case

		if (input == "day" || input == "d")
		{
			//report daily summaries
			cout << "Which Day would you like to view the summaries for? (Please enter a value from 1-14)";
			cin >> intput;

			cout << "\nDaily Summaries for Day " << intput << " are as follows:" 
				<< "\nThe max of all blood sugar readings recorded today is " << Days[intput-1].retMax() 
				<< "\nThe min of all blood sugar readings recorded today is " << Days[intput-1].retMin() 
				<< "\nThe total number of valid blood sugar readings recorded today is " << Days[intput-1].retCount() 
				<< "\nThe sum of all blood sugar readings for today is " << Days[intput-1].retSum() 
				<< "\nThe average of all blood sugar readings for today is " << Days[intput-1].retAv() << endl;
		}

		if (input == "week" || input == "w")
		{
			cout << "Which Week would you like to view the summaries for? (Please enter Either 1 or 2)";
			cin >> intput;
			cout << "\nWeekly summaries, so far, for week " << intput << " are as follows:"
				<< "\nThe max of the blood sugar readings recorded for this week is " << Weeks[intput-1].retMax()
				<< "\nThe min of the blood sugar readings recorded for this week is " << Weeks[intput-1].retMin()
				<< "\nThe total number of valid blood sugar readings recorded for this week is " << Weeks[intput-1].retCount()
				<< "\nThe sum of all blood sugar readings for this week is " << Weeks[intput-1].retSum() 
				<< "\nThe average of all blood sugar readings for today is " << Weeks[intput-1].retAv()<< endl;
			
			
		}
	
		if (input == "quit" || input == "q")
		{
			exit = true;
		}
		
		if (input == "next" || input == "n")
		{
			if (dayInc <= 13)
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
			cout << "\nWeekly summary for week two are as follows:"//since counter started at 0, add 1 for outputs
				<< "\nThe max of the blood sugar readings recorded for this week is " << Weeks[1].retMax()
				<< "\nThe min of the blood sugar readings recorded for this week is " << Weeks[1].retMin()
				<< "\nThe total number of valid blood sugar readings recorded for this week is " << Weeks[1].retCount()
				<< "\nThe sum of all blood sugar readings for this week is " << Weeks[1].retSum() 
				<< "\nThe average of all blood sugar readings for today is " << Weeks[1].retAv()<< endl;
				exit = true;
 /**
 ___________			
|           |
|    THE    | 
| GIRAFFE   |  
|  DOESN'T  |
| KNOW WHAT | 
|  IS GOING |
|    ON     |
|___________| 
(\_/) || 
(.ㅅ.) || 
/ 　 づ			**/
			}
		}

		else
		{
			/* Any other input will be taken as a data reading or ingnored if it is not a positive value
			 then this stores the input as a number in the num float */
			float num = std::atof(input.c_str());
			/**tried stof but kept getting unhandled exceptions, switched to atof 
			after reading this 
			https://stackoverflow.com/questions/17619097/c-converting-string-to-double-using-atof
			It stopped throwing errors afterwards**/
			Days[dayInc].inputNum(num);
			Weeks[weekInc].inputNum(num);
		}
	}
	
	system("pause");
	return 0;
}