#include "Carriage.h"
#include <iostream>
#include<vector>
using namespace std;


Carriage::Carriage(Pumpkin::Colour a){
	carrColor=	a;
	dateOfBirth=currentDate();
}


Pumpkin::Colour Carriage::colour() const{
	return carrColor;
}


Pumpkin* Carriage::change() const{
	int date_=currentDate();
	if (date_!=dateOfBirth){
	Pumpkin *newobj=Pumpkin::Create(carrColor);
    return newobj;
}
	else 
		return nullptr;
}
