#include<iostream>
#include<string>
#include<climits>
//using namespace std;
double multiply(double x, double y){
  return x*y;
}

double add(double x, double y){
  return (x+y);
}

double take(double x,double y){
  return (x-y);
}

double over(double x,double y){
  if(y!=0){
    return x/y;
  }
  else{
    std::cout<<"can not divide by 0"<<std::endl;
    return 0;
  }
}

void print(double z){
  std::cout<<"answer=    "<<z<<std::endl;
}
  


int main(){
 double a;
 double b;
 std::string operation;
 std::string plus="+";
 std:: string minus="-";
 std:: string times="*";
 std:: string divide="/";
 std:: string quit="q";
 do{
   std::cout<<"enter number 1"<<std::endl; //enter first number
   std::cin>>a;
   
   while(!std::cin){ //input validation
     std::cout<<"incorrect input, stop trying to break my programme!"<<std::endl;
     std::cout<<"enter number 1"<<std::endl;
     std::cin.clear();
     std::cin.ignore(INT_MAX,'\n');
     std::cin>>a;
     
   } 
   
   std::cout<<"enter number 2"<<std::endl; //enter second number
   std::cin>>b;

   while(!std::cin){ //input validation
   std::cout<<"incorrect input, stop trying to break my programme!"<<std::endl;  
   std::cout<<"enter number 2"<<std::endl;
   std::cin.clear();
   std::cin.ignore(INT_MAX,'\n');
   std::cin>>b;
   
   }
 
   std::cout<<"enter operator"<<std::endl;
   std::cin>>operation;               //fill operator string;
 
   if(operation.compare(plus)==0){ //perform addition
     //std::cout<<" a+b= "<<a+b<<std::endl;
     print(add(a,b));
   }
   if(operation.compare(minus)==0){ //perform subtraction
     //std::cout<<" a-b= "<<a-b<<std::endl;
     print(take(a,b));
   }
   if(operation.compare(times)==0){  //perform times
     //std::cout<<" a*b ="<<a*b<<std::endl;
     print(multiply(a,b));
   }
   if(operation.compare(divide)==0){ //peform divide
     //std::cout<<" a/b ="<<a/b<<std::endl;
     print(over(a,b));
   }
   if(operation.compare(quit)==0){
     break;
   }
   if((operation.compare(plus)!=0)&&(operation.compare(minus)!=0)&&(operation.compare(times)!=0)&&(operation.compare(divide)!=0)){
     std::cout<<"a=  "<<a<<"  b=   "<<b<<std::endl;  //default option if operator incorrect
   }
 }while(1);
 //std::cout<<"product is=  "<<a*b<<std::endl; //std::cout product
 return 0;
}
