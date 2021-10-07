#include<bits/stdc++.h>
#include "board.h"
using namespace std;


int main(){
    Game g;
    
    string userInput;
    
    cout<<"player1 Input: ";
    for(int i=0;i<5;i++){
        cin>>userInput;
        g.placeplayer("A",userInput,4,i);
    }

    cout<<"player2 Input: ";
    for(int i=0;i<5;i++){
        cin>>userInput;
        g.placeplayer("B",userInput,0,i);
    }
    g.displayBoard();

    //checking all player locations stored g.playerlocations();
    bool player = true;
    string move;
    while(true){
        cin>>move;
        if(player){
            g.movePlayer("P1",move);
            player=!player;
        }
        else{
            g.movePlayer("P2",move);
            player=!player;
        }
        g.displayBoard();
    }
    return 0;
}