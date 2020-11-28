#include<iostream>
using namespace std;
//if there is no return value, c/c++ returns the return value of the last statement
int fun(){
    printf("Nothing\n"); //printf returns the length of number of character processed
}
int main(){
   printf("Return value of fun() %d", fun());
}

