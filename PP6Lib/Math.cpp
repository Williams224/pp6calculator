
#include<iostream>
#include<string>
#include<climits>
#include<cmath>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include "Math.hpp"

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

double NormalInput(std::string str){
  double c;
  std::cout<<"enter "<<str<<std::endl; //enter first number
   std::cin>>c;
   
   while(!std::cin){ //input validation
     std::cout<<"incorrect input, stop trying to break my programme!"<<std::endl;

     std::cout<<"enter number "<<std::endl;

     std::cout<<"enter "<<str<<std::endl;
     std::cin.clear();
     std::cin.ignore(INT_MAX,'\n');
     std::cin>>c;
     
   } 
   return c;
}

double Gradient(){
  double g;
  std::cout<<"enter gradient"<<std::endl;
  std::cin>>g;
  while(!std::cin){ //input validation
    std::cout<<"incorrect input, stop trying to break my programme!"<<std::endl;
    std::cout<<"enter gradient"<<std::endl;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cin>>g;
  }
  return g;
}

double Constant(){
  double I;
  std::cout<<"enter constant"<<std::endl;
  std::cin>>I;
  while(!std::cin){ //input validation
    std::cout<<"incorrect input, stop trying to break my programme!"<<std::endl;
    std::cout<<"enter constant"<<std::endl;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cin>>I;
  }
  return I;
}

double CalcIntercept(double x, double y){
  //double z;
  //z=;
  return ((-1)*y)/x ;
}

/*double CalcQuadraticP(double x, double y, double z){
  double Out;
  Out=(((-1)*y)+sqrt((y*y)-(4*x*z))/(2*x));
  return Out;
}

double CalcQuadraticN(double x, double y, double z){
   double Out;
  Out=(((-1)*y)-sqrt((y*y)-(4*x*z))/(2*x));
  return Out;
  }*/

bool NewQuadratic(double x, double y, double z,double& p, double& n ){
  double discriminant=(y*y)-(4*x*z);
  if(discriminant<0){
    return false;
  }
  else{
  n=(((-1)*y)-sqrt(discriminant)/(2*x));
  p=(((-1)*y)+sqrt(discriminant)/(2*x));
  return true;
  }
}

double VectorSize(){
  int V;
  std::cout<<"enter length of vector"<<std::endl;
  std::cin>>V;
  while(!std::cin){ //input validation
    std::cout<<"incorrect input, stop trying to break my programme!"<<std::endl;
    std::cout<<"enter length of vector"<<std::endl;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cin>>V;
  }
  return V;
}

double ThreeLength(double i, double j, double k){
  //double Out;
  //Out=;
  return (sqrt((i*i)+(j*j)+(k*k)));
}

double FourLength(double i,double j, double k, double l){
  //double Out;
  //Out= ;
  return (sqrt((i*i)-(j*j)-(k*k)-(l*l)));
}

void Swap(double& x, double& y){
  double rem;
  //double rem;
  rem=x;
  x=y;
  y=rem;
  //remy=y;
  //x=remy;
  //y=remx; 
}

void IntSwap(int& x, int& y){
  int rem;
  rem=x;
  x=y;
  y=rem;
}


void PrintArray(int n,double *A){
  for(int i=0;i<n;++i){
    std::cout<<A[i]<<std::endl;
  }
}

void SortArray(int n, double *A){
  bool notsorted;
  do{
    notsorted=false;
    for(int j=0;j<(n-1);++j){
      if(A[j]<A[j+1]){
	Swap(A[j],A[j+1]);
	notsorted=true;
      }

    }
  }
  while(notsorted==true);
}


