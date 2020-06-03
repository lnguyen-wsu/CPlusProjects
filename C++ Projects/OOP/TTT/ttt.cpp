// this is TTT game
// Luan Nguyen
#include <iostream>
#include <string>
using namespace std;
void Display(char a[3][3]);
void get_input (char a[3][3],int ,char);
char  winnerx (char a[][3],int);
char winnero (char a[][3],int);
bool gameOver(char a[][3], int );
char help_func(char a[][3],int,char);
void refresh(char a[][3],int);
void winner_sta (char );
int main () {
	cout<<"Hello"<< endl;
	char  arry[3][3]={'1','2','3','4','5','6','7','8','9'};
	// 2 dimentional array
	cout<<"This is field which you will play on it "<<endl; 
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<arry[i][j]<<"   " ;
			}
			cout<<endl;	
		}
	char turn = 'X';
	char answer;
	cout<<" Do you want to play ?? (y/n)"<<endl;
	cin>>answer;
	while (answer=='Y' || answer =='y'){
	cout<<"Welcome to TTT game"<<endl;
	get_input(arry,3,turn);
	winnerx(arry,3);
	winnero (arry,3);
	cout<<"Person..."<< winnerx(arry,3) << winnero(arry,3)<< " ... is the winner !!!"<<endl;
	cout<< "Do you want to play again ?? ::: (y/n)"<<"  ";
	cin >> answer;
	refresh (arry,3);

	}
	cout <<"Thanks for playing !!"<<endl;
	
return 0;
}

// function for gameover
void refresh (char a[][3],int size){
	char replace [3][3] ={ '1','2','3','4','5','6','7','8','9'};
	for (int i = 0; i<3;i++){
		for (int j =0;j<3;j++){
		a[i][j] = replace[i][j];
	}
   }
}
bool gameOver (char a[][3],int size){
	return (winnerx(a,size)=='X' ||winnero(a,size)=='O') ; 
}

// function for winner
char winnerx(char a[][3],int size){
	char check;	
	check = help_func(a,size,'X');
	return check;
}
char winnero(char a[][3], int size){
	char check;
	check = help_func(a,size,'O');
	return check;	
}
char help_func(char a[][3],int size,char turn){

	if ((a[0][0] == a[1][1])&& (a[2][2] == a[0][0])&&(a[1][1]==a[2][2])&&(a[0][0] == turn)){
		return turn;
	
	}else if (( a[2][0] == a[1][1])&&(a[1][1] == a[0][2])&&(a[0][2]==a[2][0])&&(a[1][1] == turn)){
		return turn;
	}else if ((a[0][0]==a[1][0])&& (a[2][0]==a[0][0])&&(a[1][0]=a[2][0])&&(a[0][0]==turn)){
		return turn;
	}else if ((a[0][1] == a[1][1])&&(a[1][1] == a[2][1])&&(a[0][1]=a[2][1])&&(a[1][1] == turn)){
		return turn;
	}else if ((a[0][2] == a[1][2])&&(a[0][2] == a[2][2])&&(a[1][2]==a[2][2])&&(a[2][2] == turn)){
		return turn;
	}else if ((a[0][0] == a[0][1])&&(a[0][0] ==a[0][2])&& (a[0][2]=a[0][1])&&(a[0][0] == turn)){
		return turn;
	}else if ((a[1][0] == a[1][1])&& (a[1][0] == a[1][2])&& (a[1][1]==a[1][2])&&(a[1][1] == turn)){
		return turn;
	}else if ((a[2][0]  == a[2][1])&& (a[2][2] ==a[2][1])&& (a[2][2]==a[2][0])&&(a[2][2] == turn)){
		return turn;
	}

	return '.';
} 

void Display (char a[3][3]){
	for (int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		cout<<a[i][j]<< " ";
		}	
		cout<<endl;
	}
}
void winner_sta (char better_one){
	if (better_one == 'X'){
                cout<< "Mr.X is the winner"<<endl;
        }
	else if ( better_one =='O'){
                cout<<"Mr.O is s the winner"<<endl;
        }
	
}
void get_input ( char a [][3],int size, char better_one){
	int move_x;
	while (gameOver (a,3)!=true) 
	{
		char stop;	
		stop = winnerx (a,3);
		cout << stop << "........"<<endl;	
		cout<<"Please only input only number !! Thanks !!!"<< endl;
		cout<< better_one << "   Please make your move"<<" " ;
		cin >> move_x;
		while(true){
			if ((move_x>=1) && (move_x<=9) && a[(move_x-1)/3][(move_x-1)%3]!='X' &&  a[(move_x-1)/3][(move_x-1)%3]!='O'){
		   
			
			       	a[(move_x-1)/3][(move_x-1)%3]= better_one ;
			       	better_one=(better_one == 'X') ? 'O' : 'X';
				Display(a);
				break;
			}else{
				cout<<"This is invalid move"<<endl;
				cout<<"PLease input your move again !!!"<<endl;
				cin >>move_x; 
		     	}
		 
	        }
	} 
}





