#include<iostream>
#include<string>
#include<climits>
#include<cmath>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include "Math.hpp"
#include "Week1.hpp"
//#include "Math.hpp"



//----------------------main-------------------------------
int main(){
  std:: string s="stat";
  std:: string c="calc";
  std::string week;
  std::cout<<" Input options are: "<<std::endl;
  std::cout<<"Calculator [calc] "<<std::endl;
  std::cout<<"Statistical [stat] "<<std::endl;
  std::cin>>week;
  bool match=false;
  if(week.compare(c)==0){
    Week1();
    match=true;
  }
  if(week.compare(s)==0){
    //do something
    match=true;
  }
  if(match==false){
    std::cout<<"sorry not an option"<<std::endl;
  }
  


 return 0;
}
 

