#include "Pumpkin.h"
#include <iostream>
#include<vector>
using namespace std;


Pumpkin* Pumpkin::Create(Colour a){
	Pumpkin *address=new Pumpkin;
	address->pumpkinColor=a;
	address->carved_=false;
	address-> alight_=false;
	return address;
}

std::vector<Pumpkin> Pumpkin::CreatePumpkins(unsigned int n, Colour c, bool carved){
	vector<Pumpkin> list;
	for (int i=0;i<n;i++){
		Pumpkin *object=new Pumpkin;
			object->pumpkinColor=c;
			object->carved_=carved;
			object-> alight_=false;
			list.push_back(*object);
	}
	return list;
}

bool Pumpkin::carved() const{
	return carved_;
}

void Pumpkin::carve(){
	if (carved_==true)
 throw PumpkinException ("this has been carved!\n");

	else{ 
		carved_=true;
		cout<<"carving the pumpkin into a jack-o-....\n";
	}
}
bool Pumpkin::alight() const{
	return (carved_==true&&alight_==true);
}

void Pumpkin::light(){
	if (carved_==false||alight_==true)
	throw PumpkinException ("this has been lit!\n");

	else{
		cout<<"lighting the pumpkin\n";
		alight_=true;
	}
		
}

Pumpkin::Colour Pumpkin::colour()const{
	return pumpkinColor;
}

PumpkinException:: PumpkinException(std::string message){
	mess=message;
}

string  PumpkinException::message() const{
	return mess;
}
