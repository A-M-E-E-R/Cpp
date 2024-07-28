#include<iostream>
#include<string>
#include<stdlib.h>

//the program should bleep  the word taken from the texxt taken...

void beep(std::string word, std::string & text){
  for(int i = 0;i<text.size();i++){
    int match = 0;
    int j=0;
      while(j<word.size()){
        if(word[j]==text[i]){
          j++;
          i++;
          match++;
        }
        else break;
      }  
      if(match==word.size()){
        i -= match;
        match =0;
        for(int k=0;k<word.size();k++){
          text[i] = '*';
          i++;
        }
      }
    }
}

int main(){
  std::string word ;
  std::string text ;
  std::cout<<"Enter the word to be bleeped: ";
  std::cin>>word;
  std::cin.ignore();
  std::cout<<"Enter the sample text with or without the word to be bleeped: ";
  std::getline(std::cin,text);
  beep(word,text);
  std::cout<<"The final text: ";
  std::cout<<text;

}