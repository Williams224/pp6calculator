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

double NormalInput(){
  double c;
  std::cout<<"enter number 1"<<std::endl; //enter first number
   std::cin>>c;
   
   while(!std::cin){ //input validation
     std::cout<<"incorrect input, stop trying to break my programme!"<<std::endl;
     std::cout<<"enter number 1"<<std::endl;
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

int main(){
 double a;
 double b;
 std::string operation;
 std::string plus="+";
 std:: string minus="-";
 std:: string times="*";
 std:: string divide="/";
 std:: string line="intercept";
 std:: string quit="q";
 do{
 
   std::cout<<"enter operator"<<std::endl;
   std::cin>>operation;               //fill operator string;
 
   if(operation.compare(plus)==0){ //perform addition
     a=NormalInput();
     b=NormalInput();
     print(add(a,b));
   }
   if(operation.compare(minus)==0){ //perform subtraction
     a=NormalInput();
     b=NormalInput();
     print(take(a,b));
   }
   if(operation.compare(times)==0){  //perform times
     a=NormalInput();
     b=NormalInput();
     print(multiply(a,b));
   }
   if(operation.compare(divide)==0){ //peform divide
     a=NormalInput();
     b=NormalInput();
     print(over(a,b));
   }
   if(operation.compare(line)==0){    //calculate line intercept
     a=Gradient();
     b=Constant();
     print(CalcIntercept(a,b));
   }
	 
   if(operation.compare(quit)==0){
     break;
   }
   if((operation.compare(plus)!=0)&&(operation.compare(minus)!=0)&&(operation.compare(times)!=0)&&(operation.compare(divide)!=0)&&(operation.compare(line))){
     std::cout<<"a=  "<<a<<"  b=   "<<b<<std::endl;  //default option if operator incorrect
   }
 }while(1);
 return 0;
}
