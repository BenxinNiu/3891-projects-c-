#include <iostream>
#include <cmath>
#include "Expression.h"
#include <memory>	// std::unique_ptr
using namespace calc;

// implement the Literal constructor
ExpPtr Expression::Literal(double a){
  Litera *address=new Litera(a); // pointer to an Litera object
  ExpPtr p (address); // take that as a pointer to ExpPtr
  p->oneBit=a;   // store the value
  return p;  // return ExpPtr
}
// Litera class constructor
Litera::Litera(double a){
	val=a;
}
// implement virtual method
double Expression::evaluate() const{
  return oneBit;
}
// override virtual method from parent
double Litera::evaluate() const{
  return val;
}
// override virtual method from parent
double BinaryOperation::evaluate() const{
  return result;
}
// BinaryOperation class constructor
BinaryOperation::BinaryOperation(ExpPtr lhs, ExpPtr rhs){
	y=lhs->oneBit;
	z=rhs->oneBit;
}
//Add constructor
ExpPtr BinaryOperation::Add(ExpPtr lhs, ExpPtr rhs){
     BinaryOperation *address=new BinaryOperation(std::move(lhs), std::move(rhs));
     address->result=(address->y)+(address->z);
     double temp=address->result;
     ExpPtr p (address);
     p->oneBit=temp;
     return p;
}
// Subtract constructor
ExpPtr BinaryOperation::Subtract(ExpPtr lhs, ExpPtr rhs){
     BinaryOperation *address=new BinaryOperation(std::move(lhs), std::move(rhs));
     address->result=(address->y)-(address->z);
     double temp=address->result;
     ExpPtr p (address);
     p->oneBit=temp;
     return p;
}
// Multiply constructor
ExpPtr BinaryOperation::Multiply(ExpPtr lhs, ExpPtr rhs){
     BinaryOperation *address=new BinaryOperation(std::move(lhs), std::move(rhs));
     address->result=(address->y)*(address->z);
     double temp=address->result;
     ExpPtr p (address);
     p->oneBit=temp;
     return p;
}
// Divide constructor
ExpPtr BinaryOperation::Divide(ExpPtr lhs, ExpPtr rhs){
     BinaryOperation *address=new BinaryOperation(std::move(lhs), std::move(rhs));
     address->result=(address->y)/(address->z);
     double temp=address->result;
     ExpPtr p (address);
     p->oneBit=temp;
     return p;
}

