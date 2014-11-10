#include<iostream>
#include<string>
#include<climits>
#include<cmath>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include "Week1.hpp"
#include "Week2.hpp"
//#include "Stat.hpp"

//#include "Math.hpp"



//----------------------main-------------------------------
int main(){
  std:: string s="stat";
  std:: string c="math";
  std::string week;
  std::cout<<" Input options are: "<<std::endl;
  std::cout<<"Calculator [math] "<<std::endl;
  std::cout<<"Statistical [stat] "<<std::endl;
  std::cin>>week;
  bool match=false;
  if(week.compare(c)==0){
    Week1();
    match=true;
  }
  if(week.compare(s)==0){
    Week2();
    match=true;
  }
  if(match==false){
    std::cout<<"sorry not an option"<<std::endl;
  }
  


 return 0;
}
 

