#include<iostream>

//123 456 789 147 258 369 159 753 
const int r = 3;
const int c = 3;
int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
char ans[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char Reset[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int combinations[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{7,5,3}};

void show_the_board(char array[r][c]){
std::cout<<"\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(j==0)std::cout<<" ";
            std::cout<<array[i][j];
            if(j < c-1){
                std::cout<<" | ";
            }
        }
        if(i< r-1){
            std::cout<<"\n"<<"---|---|---\n";
        }
    }
    std::cout<<"\n";
    return ;
}

bool if_taken(int p){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(p==arr[i][j]){
                if(ans[i][j]=='X' || ans[i][j]=='O') return true;
                else return false;
            }
        }
    }
}

void get_input(int in){
    show_the_board(ans);
re1:
    std::cout<<"\nEnter the position number: ";
    int p;
    std::cin>>p;
    if(p<1 || p>9) {
        std::cout<<"\n Enter a position between 1 - 9.";
        goto re1;
    }
    if(if_taken(p)){
        std::cout<<"\n The entered position is already taken!!!";
        goto re1;
    }
    char inp;
    if(in == 1) inp = 'X';
    else inp = 'O';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(p==arr[i][j]){
                ans[i][j]=inp;
            }
        }
    }
}

void player_X(){
    get_input(1);
}

void player_O(){
    get_input(2);
}

bool check_X(int x){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x == arr[i][j]){
                if(ans[i][j]=='X') return true;
                else return false;
            }
        }
    }
}

bool check_for_X(){
    for(int i=0;i<8;i++){
        int c=0;
        for(int j=0;j<3;j++){
            if(check_X(combinations[i][j])) c++;
            else break;
        }
        if(c==3) return true;
    }
    return false;
}

bool check_O(int x){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x == arr[i][j]){
                if(ans[i][j]=='O') return true;
                else return false;
            }
        }
    }
}

bool check_for_O(){
    for(int i=0;i<8;i++){
        int c=0;
        for(int j=0;j<3;j++){
            if(check_O(combinations[i][j])) c++;
            else break;
        }
        if(c==3) return true;
    }
    return false;
}

void reset(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans[i][j] =  Reset[i][j];
        }
    }
    return;
}

int main(){
    std::cout<<"\n\n\nWELCOME TO TICK-TACK-TOE\n";
    std::cout<<"========================\n";
    std::cout<<"Player 1 will control X and Player 2 will control O\n";
    std::string player1, player2;
    std::cout<<"Enter the name of player 1: ";
    std::cin>>player1;
    std::cout<<"Enter the name of player 2: ";
    std::cin>>player2;

start:
    int turns = 0;
    bool X_won = false, O_won = false;
    show_the_board(ans);
    while(turns < 9){
        player_X();
        turns++;
        if(turns>4){
            X_won = check_for_X();
            if(X_won)break;
        } 
        player_O();
        turns++;
        if(turns>5) {
            O_won = check_for_O();
            if(O_won)break;
        }
    }
    if(X_won){
        std::cout<<"\nCongrats "<<player1<<" have won!!!!\n";
    }
    else if(O_won){
        std::cout<<"\nCongrats "<<player2<<" have won!!!\n";
    }
    else{
        std::cout<<"\nIt's a draw!!!\n";
    }
    std::cout<<"\n Enter 1 to restart: ";
    int asd = 0;
    std::cin>>asd;
    if(asd==1) {
        reset();
        goto start;
    }
    else std::cout<<"\n\n Bye byee!!\n\n";
}