#include<iostream>
#include<string>
#include<climits>
#include<cmath>
#include<vector>
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
  double Out;
  Out=sqrt((i*i)+(j*j)+(k*k));
  return Out;
}

double FourLength(double i,double j, double k, double l){
  double Out;
  Out= sqrt((i*i)-(j*j)-(k*k)-(l*l));
  return Out;
}

void Swap(double& x, double& y){
  int remx;
  int remy;
  remx=x;
  remy=y;
  x=remy;
  y=remx; 
}

int main(){
 double a;
 double b;
 double c;
 double d;
 double v;
 double n;
 double swapme;
 double swapme2;
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

 swapme=5;
 swapme2=10;

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
     std::cout<<"positive solution=   "<<std::endl;
     print(CalcQuadraticP(a,b,c));
     std::cout<<"negative solution=    "<<std::endl;
     print(CalcQuadraticN(a,b,c));
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
 

