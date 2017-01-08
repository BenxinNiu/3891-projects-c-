#include "PumpkinPatch.h"
#include <vector>
#include<iostream>

/*
 * Create a container which contains n numbers of pumpkin with colour "c"
 *
 *@param n: size of the container
 *@param Colour: the colour of pumpkins
 *
 *@return pumpkin class
 *
*/
PumpkinPatch PumpkinPatch::Create(size_t n, Pumpkin::Colour c){
	       std::vector<Pumpkin*> container;
	         for (size_t i=0;i<n;i++){
	        	 container.push_back( Pumpkin::Create(c));
	         }	   
	         return PumpkinPatch(container);
}
/*
 * Construct a pumpkin patch from an existing vector of pumpkins.
 *
 *@param a: vector of Pumpkin pointer
 *
*/
PumpkinPatch::PumpkinPatch(std::vector<Pumpkin*> a ) {
	for (int i=0; i<a.size();i++){
		patch->push_back(a[i]);
	}	
}
// copy constructor
PumpkinPatch::PumpkinPatch(const PumpkinPatch& b){
	delete patch;
	patch=b.patch;
}
// destructor
PumpkinPatch::~PumpkinPatch(){
	delete [] patch;
} 
// assignment operator
PumpkinPatch& PumpkinPatch::operator = (const PumpkinPatch& c){
delete patch;
	patch=c.patch;
		return *this;
}
size_t PumpkinPatch::size() const{
	return patch->size();
}

/*
 * Index/subscript operator
 *
 * @param i : data location
 * @pre   i is less than the total number of pumpkins in the patch
 *
 * @return the data at index i
 */
Pumpkin& PumpkinPatch::operator[] (size_t i){
	int patchSize=(patch->size())-1;
	if(i>patchSize)
		throw std::string("accssess denied!!");
	return *((*patch)[i]);
}
// Beginning of the pumpkin data: supports range-based for loop.
Pumpkin** PumpkinPatch:: begin(){
	if(patch->size()!=0){
	Pumpkin *item=(*patch)[0];
	Pumpkin **address=&item;
	return address;
	}
	else 
		return nullptr;
}
//! End+1 of the pumpkin data: supports range-based for loop.
Pumpkin** PumpkinPatch:: end(){
	if(patch->size()!=0){   // check if the size of vector is 0
	int last=patch->size()-1;
	Pumpkin *item=(*patch)[last];
	Pumpkin **address=&item;
	return address;
	}
	else 
		return nullptr;
}
/*
 * Carve all of the pumpkins in the patch.
 *
 * @param  : none
 *
 * @return the number of pumpkins that were successfully carved
 */

size_t PumpkinPatch::carve(){
	int success=0;
	for (int i=0; i<patch->size();i++){
		Pumpkin item=*((*patch)[i]);
		if (!(item.carved())){
			item.carve();
			success++;
		}
	}
	return success;
}
/*
 * Light all of the pumpkins in the patch.
 *
 * @param  : none
 *
 * @return the number of pumpkins that were successfully lit
 */
size_t PumpkinPatch::light(){
	int success=0;
	for (int i=0; i<patch->size();i++){
		Pumpkin item=*((*patch)[i]);
		if (!(item.alight())){
			item.light();
			success++;
		}
	}
	return success;
}
/*
 * Convert all of the pumpkins in this patch into carriages.
 *
 * @param  : none
 *
 * @return the carriages created from the pumpkins
 */
std::vector<Carriage> PumpkinPatch::makeCarriages(){
	std::vector<Carriage> temp;
	for (int i=0; i<patch->size();i++){
			Pumpkin item=*((*patch)[i]);
			temp.push_back(Carriage(item.colour()));
			delete (*patch)[i];
			}
		
	return temp;
}


