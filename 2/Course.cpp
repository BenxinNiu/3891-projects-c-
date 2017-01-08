#include "Course.h"
#include <iostream>
using namespace std;

Course::Course(unsigned int number, Level level, unsigned int capacity){
		capacity = 100;
		courseLevel=level;
		c=capacity;
		remaining=capacity;
		numOfStudent=0;
		courseNum=number;
	}


bool Course::registerStudent(bool overrideLimits){
	bool registered;
	if (overrideLimits){
		cout<<"override successful"<<endl;
		registered=1;
	}
	else if (remaining==0){
		cout<<"course if full"<<endl;
		registered=0;
	}
	else if(remaining>=0){
		cout<<"student is registered"<<endl;
				remaining--;
				registered=1;
	}
	return registered;	
}
unsigned int Course::capacity() const{
	return c;
}
unsigned int Course::enrolment() const{
	return numOfStudent;
}
int Course::seatsRemaining() const{
	return remaining;
}
