#include<bits/stdc++.h>
using namespace std;


class Game{
    
    vector<vector<string>> board;
    unordered_map<string,pair<int,int>> p1,p2;
    
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
    
    void placeplayer(string player,string character,int x,int y){
        board[x][y]=player+"-"+character;
        if(player=="A"){
            p1[character]={x,y};
        }
        if(player=="B"){
            p2[character]={x,y};
        }
    }
    void playerlocations(){
        for(auto it:p1){
            cout<<it.first<<" x: "<<it.second.first<<" y: "<<it.second.second<<endl;
        }
        cout<<endl;
        for(auto it:p2){
            cout<<it.first<<" x: "<<it.second.first<<" y: "<<it.second.second<<endl;
        }
    }
    void removePlayer(string player,int x,int y){
        if(player=="P1"){
            p2.erase(board[x][y].substr(2,4));
        }
        if(player=="P2"){
            p1.erase(board[x][y].substr(2,4));
        }
        playerlocations();
    }
    bool movePlayer(string player,string input){
        string character = input.substr(0,2);
        string move = input.substr(3,input.size());
        if(player=="P1" && character[0]=='p'){
            if(p1.find(character)==p1.end()){
                cout<<"This character is dead move another.";
                return false;
            }
            int x = p1[character].first;
            int y = p1[character].second;
            if(move=="F"){
                if(x-1<0){
                    cout<<"Invalid move"<<endl;
                    return false;
                }
                if(board[x-1][y]!="-"){
                    if(board[x-1][y][0]=='A'){
                        cout<<"Can't move because your another player is here."<<endl;
                        return false;
                    }
                    removePlayer(player,x-1,y);
                }
                board[x-1][y]=board[x][y];
                board[x][y]="-";
                p1[character]={x-1,y};
            }
            if(move=="B"){
                if(x+1>4){
                    cout<<"Invalid move"<<endl;
                    return false;
                }
                if(board[x+1][y]!="-"){
                    if(board[x+1][y][0]=='A'){
                        cout<<"Can't move because your another player is here."<<endl;
                        return false;
                    }
                    removePlayer(player,x+1,y);
                }
                board[x+1][y]=board[x][y];
                board[x][y]="-";
                p1[character]={x+1,y};
            }
            if(move=="L"){
                if(y-1<0){
                    cout<<"Invalid move"<<endl;
                    return false;
                }
                if(board[x][y-1]!="-"){
                    if(board[x][y-1][0]=='A'){
                        cout<<"Can't move because your another player is here."<<endl;
                        return false;
                    }
                    removePlayer(player,x,y-1);
                }
                board[x][y-1]=board[x][y];
                board[x][y]="-";
                p1[character]={x,y-1};
            }
            if(move=="R"){
                if(y+1>4){
                    cout<<"Invalid move"<<endl;
                    return false;
                }
                if(board[x][y+1]!="-"){
                    if(board[x][y+1][0]=='A'){
                        cout<<"Can't move because your another player is here."<<endl;
                        return false;
                    }
                    removePlayer(player,x,y+1);
                }
                board[x][y+1]=board[x][y];
                board[x][y]="-";
                p1[character]={x,y+1};
            }

        }
        if(player=="P2" && character[0]=='p'){
            if(p2.find(character)==p2.end()){
                cout<<"This character is dead move another."<<endl;
                return false;
            }
            int x = p2[character].first;
            int y = p2[character].second;
            if(move=="F"){
                if(x+1>4){
                    cout<<"Invalid move"<<endl;
                    return false;
                }
                if(board[x+1][y]!="-"){
                    if(board[x+1][y][0]=='B'){
                        cout<<"Can't move because your another player is here."<<endl;
                        return false;
                    }
                    removePlayer(player,x+1,y);
                }
                board[x+1][y]=board[x][y];
                board[x][y]="-";
                p2[character]={x+1,y};
            }
            if(move=="B"){
                if(x-1<0){
                    cout<<"Invalid move"<<endl;
                    return false;
                }
                if(board[x-1][y]!="-"){
                    if(board[x-1][y][0]=='B'){
                        cout<<"Can't move because your another player is here."<<endl;
                        return false;
                    }
                    removePlayer(player,x-1,y);
                }
                board[x-1][y]=board[x][y];
                board[x][y]="-";
                p2[character]={x-1,y};
            }
            if(move=="L"){
                if(y+1>4){
                    cout<<"Invalid move"<<endl;
                    return false;
                }
                if(board[x][y+1]!="-"){
                    if(board[x][y+1][0]=='B'){
                        cout<<"Can't move because your another player is here."<<endl;
                        return false;
                    }
                    removePlayer(player,x,y+1);
                }
                board[x][y+1]=board[x][y];
                board[x][y]="-";
                p2[character]={x,y+1};
            }
            if(move=="R"){
                if(y-1<0){
                    cout<<"Invalid move"<<endl;
                    return false;
                }
                if(board[x][y-1]!="-"){
                    if(board[x][y-1][0]=='B'){
                        cout<<"Can't move because your another player is here."<<endl;
                        return false;
                    }
                    removePlayer(player,x,y-1);
                }
                board[x][y-1]=board[x][y];
                board[x][y]="-";
                p2[character]={x,y-1};
            }
        }
        return true;
    }
};