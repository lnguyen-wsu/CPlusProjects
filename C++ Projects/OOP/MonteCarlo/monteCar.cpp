// Luan Nguyen - Y383P299
// Project MOnte Carlo function 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){

const int  number_dots = 1000000;
float x;
float y;
float pi;

int count = 0;
// set up loop for simulation

for (int i=0;i<number_dots ;i++)
{
	float d = 0;
	//set random number for x,y for coordinates from 0 to 1
	x = ((float) (rand()))/(float) RAND_MAX;
	y = ((float) (rand()))/(float) RAND_MAX;
	d = sqrt((x*x) + (y*y));	
	if (d<=1){
	count ++;
	}
	
}
// time for truth of pi
cout<<" This is total number of dots in the circle "<<endl;
cout << count<<endl;
pi = float((4*count)/float(number_dots));
cout.precision(12);
cout<<" real pi based on simulation "<< endl;
cout<<pi<<endl;

  
return 0;
} 
