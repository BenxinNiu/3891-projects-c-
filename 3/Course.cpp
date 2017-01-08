
#include "Course.h"
#include <iostream>
#include<vector>
using namespace std;

Course::Course(unsigned int number, Level level, unsigned int capacity){

	capa=capacity;
	courseLevel=level;
	courseNum=number;
	remaining=capa;
	numOfStudent=0;
}
unsigned int Course::number() const{
	return courseNum;
}

Course::Level Course::level() const{
	return courseLevel;
}

bool Course::registerStudent(Student s, bool overrideLimits){
	bool registered=0;
	if (overrideLimits==true){
		cout<<"override successful"<<endl;
		registered=1;
		remaining--;
		numOfStudent++;
		string n=s.name();
		stu.push_back(n);
	}
	else if(overrideLimits==false && remaining<=0){
		cout<<"course is full"<<endl;
	}
	else{
		cout<<"student is registered"<<endl;
				        numOfStudent++;
						remaining--;
						registered=1;
						string n=s.name();
						stu.push_back(n);
	}
	return registered;	
}

vector<std::string> Course::classList() const{
return stu;
}

unsigned int Course::capacity() const{
	return capa;
}
unsigned int Course::enrolment() const{
	return numOfStudent;
}
int Course::seatsRemaining() const{
	return remaining;
}
