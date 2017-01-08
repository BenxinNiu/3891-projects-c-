#include "Student.h"
#include <iostream>
using namespace std;


Student::Student(ID id, std::string name, Level level):
	studentId({id.year, id.serial})
		{
	studentLevel=level;
	studentName=name;
}

string Student::name() const{
	return studentName;
}

Student::ID Student::id() const{
	return studentId;
}

Student::Level Student::level() const{
	return studentLevel;
}

bool Student::operator == (const Student& b) const{
	ID id2=b.id();
		return (((studentId.year)==id2.year)&&((studentId.serial)==id2.serial));

}
bool Student::operator != (const Student& b) const{
	ID id2=b.id();
	return(!(((studentId.year)==id2.year)&&((studentId.serial)==id2.serial)));
}
