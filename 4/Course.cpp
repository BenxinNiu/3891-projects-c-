
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
	bool sameStu=false;
	for (int i=0;(i<students.size())&&(sameStu==false);i++){
		if (s==students[i])
			sameStu=true;
	}
	if(sameStu==false){
	if (overrideLimits==true){
		cout<<"override successful"<<endl;
		registered=1;
		remaining--;
		numOfStudent++;
		students.push_back(s);
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
						students.push_back(s);
						string n=s.name();
						stu.push_back(n);
	}
	}
	else{
		cout<<"The student is already registered!!/n";
		registered=0;
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

Course& Course::operator << (Student s){
	bool registered=0;
		bool sameStu=false;
		for (int i=0;(i<students.size())&&(sameStu==false);i++){
			if (s==students[i])
				sameStu=true;
		}
		if(sameStu==false){

	 if(remaining<=0){
		 throw string("course is full");
		}
		else{
			cout<<"student is registered"<<endl;
					        numOfStudent++;
							remaining--;
							registered=1;
							students.push_back(s);
							string n=s.name();
							stu.push_back(n);
		}
		}
		else{
			throw string("this student is already registered!!");
		}
		return *this;
}
