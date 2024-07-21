/* Scissor - paper, paper - rock, rock - lizard, 
lizard - spock, spock - scissors, scissor - lizard,
lizard - paper, paper - spock, spock - rock,
 rock - scissors */
//the former dominates the later
 #include<iostream>
 #include<stdlib.h>
 #include<ctime>
 int main(){
  srand(int (time(NULL)));
  int computer = rand() % 5 + 1;
  int user = 0;
  std::cout<<"======================\n";
  std::cout<<"rock paper scissors!!!\n";
  std::cout<<"======================\n";
game:
  std::cout << "1) 🪨 - rock\n";
  std::cout << "2) 📃 - paper\n";
  std::cout << "3) ✂️ - scissor\n";
  std::cout << "4) 🦎 - lizard\n";
  std::cout << "5) 🪄 - spock\n";

  std::cout << "shoot! ";

  std::cin>>user;

  switch (user){
    case 1 :{
      if(computer == 2 || computer == 5){
        std::cout<<"You Lost.";
      }
      else{
        std::cout<<"You Won!!!!";
      }
      break;
    }
    case 2:{
      if(computer == 3 || computer == 4){
        std::cout<<"You Lost.";
      }
      else{
        std::cout<<"You Won!!!";
      }
      break;
    }
    case 3:{
      if(computer == 1 || computer == 5){
        std::cout<<"You Lost.";
      }
      else{
        std::cout<<"You Won!!!";
      }
      break;
    }
    case 4:{
      if(computer == 1 || computer == 3){
        std::cout<<"You Lost.";
      }
      else{
        std::cout<<"You Won!!!";
      }
      break;
    }
    case 5:{
        if(computer == 2 || computer == 4){
            std::cout<<"You Lost.";
        }
        else{
            std::cout<<"You Won!!!";
        }
        break;
    }
    default:{
      std::cout<<"Invalid Input\n";
      std::cout<<"Try Again 👍\n";
      goto game;
    } 
  }
 }