/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */

#include "snowman.cpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib> 
using namespace std;

int main() {
for(int i=0;i<5;i++){
    int x=0;
    for(int j=0;j<8;j++){
        x=(x+rand()%4+1);
        if(j<7)
        x=x*10;
    }
    cout<<"random exemple num :"<<i+1<<endl;
    cout<<ariel::snowman(x)<<endl;
    cout<<"\n"<<endl;
}
return 0;
}
