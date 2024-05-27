#include <iostream>
#include <vector>
using namespace std;

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayMenu(){
    cout<<"Welcome to the our play place: "<<endl;
    cout<<"Game rules are: "<<endl;
    cout<<"You can't enter bet more than your balance "<<endl;
    cout<<"If yas press y or Y otherwise enter different key"<<endl;

}
const int reelCount=3;
const vector<int> numbers= {0,1,2,3,4};
int balance;
int bet;


int spinReel(){
    return numbers[rand()% numbers.size()];
}

void getBalance(){
    cout<<"Enter your balace: ";
    cin>>balance;
}


void getBetRate(){
    cout<<"Enter the bet that you want play: ";
    cin>>bet;
}

int newBalanceWin(){
    balance=balance+bet*10;
}

int newBalanceLose(){
    balance=balance-bet;
}



int main(){
    vector<int> guess;
    guess.push_back(spinReel());

    char playAgain='y';
    displayMenu();

    while(playAgain=='y' || playAgain=='Y'){
        getBalance();
        getBetRate();
        for(int i=0;i<reelCount;i++){
            guess.push_back(spinReel());
            cout<<guess[i]<<" ";
        }
        cout<<endl;
        if(guess[0]==guess[1] && guess[0]==guess[2]){
            cout<<"You won, Your new Balance: "<<endl;
            cout<<newBalanceWin();
            cout<<endl;
        }
        else{
            cout<<"You lose, Your new balance: "<<endl;
            cout<<newBalanceLose();
            cout<<endl;
        }
        cout<<"For continue enter the 'y' or 'Y'";
        cin>>playAgain;  
    }
    

    return 0;
}