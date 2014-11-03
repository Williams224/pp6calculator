#include<iostream>
#include<string>
#include<climits>
#include<cmath>
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

double NormalInput(std::string str){
  double c;
  std::cout<<"enter "<<str<<std::endl; //enter first number
   std::cin>>c;
   
   while(!std::cin){ //input validation
     std::cout<<"incorrect input, stop trying to break my programme!"<<std::endl;
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
  double z;
  z=((-1)*y)/x;
  return z;
}

double CalcQuadraticP(double x, double y, double z){
  double Out;
  Out=(((-1)*y)+sqrt((y*y)-(4*x*z))/(2*x));
  return Out;
}

double CalcQuadraticN(double x, double y, double z){
   double Out;
  Out=(((-1)*y)-sqrt((y*y)-(4*x*z))/(2*x));
  return Out;
}

int main(){
 double a;
 double b;
 double c;
 std::string operation;
 std::string plus="+";
 std:: string minus="-";
 std:: string times="*";
 std:: string divide="/";
 std:: string line="intercept";
 std:: string quit="q";
 std:: string quad="quadratic";
 do{
 
   std::cout<<"enter operator"<<std::endl;
   std::cin>>operation;               //fill operator string;
 
   if(operation.compare(plus)==0){ //perform addition
     a=NormalInput("Number");
     b=NormalInput("Number");
     print(add(a,b));
   }
   if(operation.compare(minus)==0){ //perform subtraction
     a=NormalInput("Number");
     b=NormalInput("Number");
     print(take(a,b));
   }
   if(operation.compare(times)==0){  //perform times
     a=NormalInput("Number");
     b=NormalInput("Number");
     print(multiply(a,b));
   }
   if(operation.compare(divide)==0){ //peform divide
     a=NormalInput("Number");
     b=NormalInput("Number");
     print(over(a,b));
   }
   if(operation.compare(line)==0){    //calculate line intercept
     a=Gradient();
     b=Constant();
     print(CalcIntercept(a,b));
   }
   if(operation.compare(quad)==0){
     a=NormalInput("second order coefficient");
     b=NormalInput("first order coefficient");
     c=NormalInput("zeroth order coefficient");
     std::cout<<a<<"x^2+"<<b<<"x"<<"+"<<c<<std::endl;
     std::cout<<"positive solution=   "<<std::endl;
     print(CalcQuadraticP(a,b,c));
     std::cout<<"negative solution=    "<<std::endl;
     print(CalcQuadraticN(a,b,c));
   }
	 
   if(operation.compare(quit)==0){
     break;
   }
   if((operation.compare(plus)!=0)&&(operation.compare(minus)!=0)&&(operation.compare(times)!=0)&&(operation.compare(divide)!=0)&&(operation.compare(line))&&(operation.compare(quad))){
     std::cout<<"a=  "<<a<<"  b=   "<<b<<std::endl;  //default option if operator incorrect
   }
 }while(1);
 return 0;
}
