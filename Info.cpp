//
//Info.cpp
//Info class function definitions file
//Wilhelm Muggenburg
//COSC2030, Fall 2018


#include "info.h"

void info::inputNum(float input)
{
	//Input must be higher than 0, otherwise they are ignored. Any positive value above 0 is accepted

	if(input > 0)
	{
		addSum(input);
		maxCk(input);
		minCk(input);
		calcAv(input);
	}
}


// minCk sees if the new value is smaller than the current Min value
void info::minCk(float input)
{
	if (input < min)
	{
		min = input;
	}
}
// maxCk sees if the new value is larger than the current Max value
void info::maxCk(float input)
{
	if (input > max)
	{
		max = input;
	}
}

void info::addSum(float input)
{
		sum = sum + input;
		count++;	
}

void info::calcAv(float input)
{
average =  sum / count;
}


//outputs
string info::retSum()
{
	string stringSum;
	
	stringSum = to_string(sum);
		
	return stringSum;

}

string info::retAv()
{
	string stringAverage;
	
	stringAverage = to_string(average);
		
	return stringAverage;

}
float info::retCount()
{
	return count;
}
float info::retMax()
{
	return max;
}

float info::retMin()
{
	return min;
}

