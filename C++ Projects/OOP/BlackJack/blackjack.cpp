//Luan Nguyen - Y383P299
// PROJECT: BLACKJACK- simulate n time for games and see if the dealer bust or not
//			if dealer has 1, it can be 11 if range from 17 to 21
//			otherwise, it just is one and require to hit other card.
#include <iostream>
#include <stdlib.h>// for random number
#include <time.h> // for random number
#include <iomanip> // to get precision of number of float
using std::cout ;
using std::cin ;
using std::endl;


int _random();
bool cond_bust (int , int  );
int one_game (int& , int&);
bool ace_case ( int& , int&, int );
int multi_games (int[]  ,int , int&);

int main(){
	cout<< "Welcome to blackjack simulation of dealer Busting probability"<<endl;
	// get cards for dealer starting by 2 cards
	srand(time(NULL)); // build random as clock but prevent reseed same time 
	int dealer_cards[10] = {0};// set dealer cards as array cuz it will be more than 2 cards 
	int bust;
	float result = 0;
	float conver_input;
	float conver_bust;
	int user_input = 0;
	cout<<" How many simulation are you gonna to run??? " <<"\t";
	cin >> user_input;

	// run similation by call function 	
	bust = multi_games(dealer_cards, 10 , user_input);
	// print out by convert bust times into float to get percentage

	conver_input= static_cast<float>(user_input);
	conver_bust = static_cast <float> (bust);

	result = conver_bust/conver_input;
	cout<<result<< endl;
	cout.precision(4); // get precision of result in 4 digits
	cout<<result * 100 <<" % is the prob for busting by dealer"<<endl;	
			
	return 0;
}



int _random(){
	// get random cards from 1 to 10;
	int rand_card= rand() % 13 + 1; // to count for Jack, Queen, King as 11,12,13
	return rand_card;
}
// function of bust condition if greater than 21
bool cond_bust(int dealer_got){
	if ( dealer_got > 21){
		return true;
	}

	return false;
}
// function of ace_case
//
// PLease read this ::: I built ace_case kinda different cuz ace_case only when it has ace and other card greater than 6
// => not busted
bool ace_case ( int& a, int& b){
    // set up if there is at least one ace and other card greater than 6 , => total will be at least
    // 17 (never busted)  so it will ace_case not busted => return true
	if ( a == 1 || b== 1){
		if (( (a >= 6) && (a <= 13)) || (( b >= 6) && ( b <= 13))){
			return true;
		}
	}
    //return false for any cases even with one ace in two original cards or two aces or none!!! 
	return false;	
}
int  one_game (int& a, int& b){
    // this is for checking two original cards of dealers whether has J,Q,K	
    if (a > 10)
    {
        a = 10;
    }else if (b > 10)
    {
        b = 10;
    }	
    // sum of two original dealers cards
    int sum = a+b;
    //  set while loop for new card  with the below conditions
	while ((sum < 17) && (ace_case(a,b) == false)) {
	    int draw = _random();// hit new card
        // set condition for new card in case it J,Q,K
		if (draw == 11 || draw== 12 || draw == 13){
			draw = 10;
		}
        // deal with ace card if it was new ace and total cards sum is greater than 17 and
        // smaller than 21 => new ace consider 11 and plus of ( two orginal cards)    
        if ((draw == 1) && (11 + sum) >= 17 && (11+ sum) <= 21){
			break; // break cuz they are not busted
		}
        // otherwise, just keep value of new card and keep adding
		sum += draw;// sum keep add with new card
	}
    // apply bust-checking function to check
    if ( cond_bust(sum) == true ){
	    return 1;
	}
    // return 0, for not bust
    return 0;
    }

// set simulation function for n games
int multi_games(int card[], int size , int& simu_times){
    int bust = 0;

    for (int i= 0; i< simu_times; i++){ // loop for n games
	    // random for 2 orginal cards
        card[1] = _random();
	    card[2] = _random();
        // set each bust of each game
	    int each_bust = 0;
	    each_bust= one_game(card[1],card[2]);
	    bust += each_bust; // accumulated bust time
	}
	
	return bust;	
}
