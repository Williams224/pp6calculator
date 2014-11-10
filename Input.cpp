#include<iostream>
#include<string>
#include<climits>
#include<cmath>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include "Math.hpp"
//#include "Math.hpp"



//----------------------main-------------------------------
int main(){
 double a;
 double b;
 double c;
 double d;
 double v;
 double n;
 double swapme;
 double swapme2;
 double psolution;
 double nsolution;
 double tobesorted[20];
 //vector<double> V;
 std::string operation;
 std::string plus="+";
 std:: string minus="-";
 std:: string times="*";
 std:: string divide="/";
 std:: string line="intercept";
 std:: string quit="q";
 std:: string quad="quadratic";
 std:: string vec="vector";
 std:: string Mass="mass";
 std:: string Help="help";
 srand(time(NULL));
 swapme=5;
 swapme2=10;
 for(int i=0;i<20;++i){
   tobesorted[i]=1+rand()%50;
   std::cout<<tobesorted[i]<<std::endl;
 }
 SortArray(20,tobesorted);
 std::cout<<"-------------------"<<std::endl;
 PrintArray(20,tobesorted);
 

 std::cout<<"before: swapme= "<<swapme<<" swapme2=  "<<swapme2<<std::endl;
 Swap(swapme, swapme2);
 std::cout<<"after: swapme=  "<<swapme<<" swapme2=  "<<swapme2<<std::endl;
 do{
   bool matched=false;
   std::cout<<"enter operator (type help for help)"<<std::endl;
   std::cin>>operation;               //fill operator string;
 
   if(operation.compare(plus)==0){ //perform addition

     a=NormalInput("number one");
     b=NormalInput("number two");
     print(add(a,b));
     matched=true;
   }
   if(operation.compare(minus)==0){ //perform subtraction
     a=NormalInput("number one");
     b=NormalInput("number two");
     print(take(a,b));
     matched=true;
   }
   if(operation.compare(times)==0){  //perform times
     a=NormalInput("number one");
     b=NormalInput("number two");
     print(multiply(a,b));
     matched=true;
   }
   if(operation.compare(divide)==0){ //peform divide
     a=NormalInput("number one");
     b=NormalInput("number two(can not be 0)");

     a=NormalInput("Number");
     b=NormalInput("Number");
     print(add(a,b));
     matched=true;
   }

   if(operation.compare(line)==0){    //calculate line intercept
     a=Gradient();
     b=Constant();
     print(CalcIntercept(a,b));
     matched=true;
   }

   if(operation.compare(quad)==0){
     a=NormalInput("second order coefficient");
     b=NormalInput("first order coefficient");
     c=NormalInput("zeroth order coefficient");
     std::cout<<a<<"x^2+"<<b<<"x"<<"+"<<c<<std::endl;
     if(NewQuadratic(a,b,c,psolution,nsolution)==true){
       std::cout<<"positive solution= "<<psolution<<" negative solution=  "<<nsolution<<std::endl;
     }
     else if(NewQuadratic(a,b,c,psolution,nsolution)==false){
       std::cout<<" no solution"<<std::endl;
     }
     //std::cout<<"positive solution=   "<<std::endl;
     // print(CalcQuadraticP(a,b,c));
     //std::cout<<"negative solution=    "<<std::endl;
     //print(CalcQuadraticN(a,b,c));
     matched=true;
   }
   if(operation.compare(vec)==0){
     v=VectorSize();
     matched=true;
     if(v==3){
       a=NormalInput("component 1");
       b=NormalInput("component 2");
       c=NormalInput("component 3");
       print(ThreeLength(a,b,c));
     }
     if(v==4){
       a=NormalInput("time component");
       b=NormalInput("x component");
       c=NormalInput("y component");
       d=NormalInput("z component");
       print(FourLength(a,b,c,d));
     }
     if((v!=3)&&(v!=4)){
       std::cout<<"sorry only supports vectors of length 3 and 4"<<std::endl;
      }
   }
   if(operation.compare(Mass)==0){
     matched=true;
     a=0;
     b=0;
     c=0;
     d=0;
     n=NormalInput("number of daughter particles");
     for(int i=0; i<n;i++){
       a+=NormalInput("Energy");
       b+=NormalInput("px");
       c+=NormalInput("py");
       d+=NormalInput("pz");
     }
     print(FourLength(a,b,c,d));
   }
   
   if(operation.compare(Help)==0){
     std::cout<<"Operator options are:- "<<std::endl;
     std::cout<<plus<<std::endl;
     std::cout<<minus<<std::endl;
     std:: cout<< times<<std::endl;
     std:: cout<< divide<<std::endl;
     std:: cout<< line<<std::endl;
     std:: cout<< quit<<std::endl;
     std:: cout<< quad<<std::endl;
     std:: cout<< vec<<std::endl;
     std:: cout<< Mass<<std::endl;
     std:: cout<< Help<<std::endl;
     std::cout<< " type 'q' to quit "<<std::endl;

   }

   if(operation.compare(quit)==0){
     matched=true;
     break;
   }
   if(matched==false){
     std::cout<<"that is not a valid operator"<<std::endl;
     // std::cout<<"a=  "<<a<<"  b=   "<<b<<"  c=   "<<c<<std::endl;  //default option if operator incorrect
   }
 }while(1);
 return 0;
}
 

