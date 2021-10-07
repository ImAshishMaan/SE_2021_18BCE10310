#include<bits/stdc++.h>
using namespace std;

class P{
    string name;

    public:
    bool isMovementPossible(string ){

    }
};

class Game{
    
    vector<vector<string>> board;
    vector<P> playerA,playerB;
    
    public:
    Game(){
        board.resize(5,vector<string>(5,"-"));
    }
    
    void displayBoard(){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                cout<<board[i][j]<<" \t ";
            }
            cout<<endl;
        }
    }
    
    void placeplayer(string p,int x,int y){
        board[x][y]=p;
    }

};