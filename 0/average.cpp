#include "average.h"

double average(const double data[], int length){
	double sum=0;
	double average;
	for (int i=0; i<length;i++){
		sum+=data[i];
	}
	average=sum/length;
	return average;
}
