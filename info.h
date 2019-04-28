
//Info.h
//Info.h file for the Info class
//Wilhelm Muggenburg
//COSC2030, Fall 2018

//Used https://docs.microsoft.com/en-us/cpp/cpp/header-files-cpp?view=vs-2019 and assistance from Jordan P to create this file
#pragma once

#ifndef _Info_H_
#define _Info_H_


#include<string>
using std::string;
using std::to_string;

// This is used to store the informtion given for the weekly and daily data
class info
{
private:
	float sum;
	float max;
	float min;
	int	  count;
	float average;

public:

	info() : sum(0),  min(345600000000), max(0), count(0), average(0)  {} //initialized min to the max value of a float so all variables would be less

	
	string retSum(void);
	float retMax(void);
	float retMin(void);
	float retCount(void);
	string retAv(void);

	void calcAv(float input);
	void addSum(float input);
	void maxCk(float input);
	void minCk(float input);
	void inputNum(float input);
};
/**
/)ii/) 
(o " ) 
  | | 
  |o| 
  | |________|| 
  | o | 
  | o______o | 
  || || || || 
  || || || ||
**/
#endif