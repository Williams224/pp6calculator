#include<iostream>
#include<string>
using namespace std;

int main(){
 double a;
 double b;
 string operation;
 string plus="+";
 string minus="-";
 string times="*";
 string divide="/";

 cout<<"enter number 1"<<endl; //enter first number
 cin>>a;
   //input validation
 if(!cin){
   cout<<"incorrect input, stop trying to break my programme!"<<endl;
 } 

 cout<<"enter number 2"<<endl; //enter second number
 cin>>b;
 if(!cin){  //input validation
   cout<<"incorrect input, stop trying to break my programme!"<<endl; 
 }
 
 cout<<"enter operator"<<endl;
 cin>>operation;               //fill operator string;
 
 if(operation.compare(plus)==0){ //perform addition
   cout<<" a+b= "<<a+b<<endl;
 }
 if(operation.compare(minus)==0){ //perform subtraction
    cout<<" a-b= "<<a-b<<endl;
 }
 if(operation.compare(times)==0){  //perform times
   cout<<" a*b ="<<a*b<<endl;
 }
 if(operation.compare(divide)==0){ //peform divide
   cout<<" a/b ="<<a/b<<endl;
 }
 if((operation.compare(plus)!=0)&&(operation.compare(minus)!=0)&&(operation.compare(times)!=0)&&(operation.compare(divide)!=0)){
   cout<<"a=  "<<a<<"  b=   "<<b<<endl;  //default option if operator incorrect
 }

 //cout<<"product is=  "<<a*b<<endl; //cout product
 return 0;
}
