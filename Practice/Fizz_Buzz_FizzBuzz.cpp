#include<iostream>
int main(){

    std::string F = "Fizz\n", B = "Buzz\n", FB = "FizzBuzz\n";
    
    for(int i = 1; i<=100; i++){

        if(i%15==0){
            std::cout<<FB;
        }
        else if(i%3==0){
            std::cout<<F;
        }
        else if(i%5==0){
            std::cout<<B;
        }
        else{
            std::cout<<i<<"\n";
        }
    }   
}