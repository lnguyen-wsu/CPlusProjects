// Programmer: Luan Nguyen
// Project: simulation about rock-paper-scissor
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
int comp_random() {
	srand(time(NULL));
	int comp = rand() % 3 + 1;

	return comp;
}
int main() {

	cout << "WELCOME TO ROCK-PAPER-SCISSOR " << endl;
	cout << "This is instruction for playing game " << endl;
	cout << "User's ROCK " << ":" << 10 << endl;
	cout << "User's Scissor" << ":" << 20 << endl;
	cout << "User's paper " << ":" << 30 << endl;
	cout << "This is Computer options " << endl;
	cout << "Comp's ROCK" << ":" << 1 << endl;
	cout << "Comp's Scissor " << ":" << 2 << endl;
	cout << "Comp's paper " << ":" << 3 << endl;

	cout << "Let 's play !!" << endl;
	
	// declare data types

	// test for computer about random numbers 
	// use for do while for loop
	
	 char input ;
         cout<<" let 's get started !! do you want to play? " << endl;
         cin>> input;
	
	while(input =='y'|| input=='Y')
	{
	int user_input ;
	cout<< "PLease pick your own choice !!"<<endl;
	cin>> user_input;
	
	// do while for user-iput and comp random numer
		if ( user_input == 10 || user_input== 20 || user_input==30) {
			int sum =0;// declare sum
			int comp = comp_random();
			sum = comp + user_input;
			switch (sum){
				case 12:
				case 23:
				case 31:
					cout << " Good job !! you are winner !! "<<endl;  
					if ((user_input == 10) and (comp == 2)) {
						cout << " your is rock and computer is scissor" << endl;
					}
					else if ((user_input == 20) and (comp == 3)) {

						cout << "Your is scissor and comp is paper !!" << endl;
					}
					else if ((user_input == 30) and (comp == 1)) {
						cout << "Yours is paper and comp is a big rock" << endl;
					}
					break;
					
				case 11:
				case 22:
				case 33:
					cout<< " You are draw "<<endl;
					if (( user_input ==10) and( comp==1)){
						cout<< " your is rock and computer is rock too"<<endl;
					}else if ((user_input==20) and( comp==2)){

						cout<< "Your is scissor and com is scissor also !!"<<endl;
					}else if ((user_input ==30) and( comp==3)){
						cout<< "Yours is paper and comp is al paper"<<endl;
					}
					break;
				case 13:
				case 21:		
				case 32:
					cout<< " SOrry !! you losT" <<endl;
					if ((user_input == 10) and (comp == 3)) {
						cout << " your is rock and computer is paper" << endl;
					}
					else if ((user_input == 20) and (comp == 1)) {

						cout << "Your is scissor and com is Big Rock !!" << endl;
					}
					else if ((user_input == 30) and (comp == 2)) {
						cout << "Yours is paper and comp is scissor" << endl;
					}
					break;
					
			}
		
				

	}
				cout<<"THANKS FOR PLAYING !! DO YOU WANT TO PLAY AGAIN ? (y/n)"<<endl;
				cin>> input;
	}

	cout << "Thanks so much for spending time with us !!! Have a wonderful day !!!" << endl;

	return 0;
}
