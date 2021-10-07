#include<bits/stdc++.h>
#include "board.h"
using namespace std;


int main(){
    Game g;
    
    string userInput;
    
    g.displayBoard();
    
    cout<<"player1 Input: ";
    for(int i=0;i<5;i++){
        cin>>userInput;
        userInput="A-"+userInput;
        g.placeplayer(userInput,4,i);
    }

    cout<<"player2 Input: ";
    for(int i=0;i<5;i++){
        cin>>userInput;
        userInput="B-"+userInput;
        g.placeplayer(userInput,0,i);
    }

    g.displayBoard();
    return 0;
}