//
//Info.h
//Info.h file for the Data class
//Wilhelm Muggenburg
//COSC2030, Fall 2018

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

	info() : sum(0),  min(345600000000), max(0), count(0), average(0)  {}
	
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

#endif