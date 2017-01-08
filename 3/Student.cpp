#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(unsigned int id, std::string name, Level level){
	studentLevel=level;
	studentId=id;
	studentName=name;
}

string Student::name() const{
	return studentName;
}

unsigned int Student::id() const{
	return studentId;
}

Student::Level Student::level() const{
	return studentLevel;
}

