
#include<iostream>
#include<string>
#include<climits>
#include<cmath>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include "FileReader.hpp"
#include "Week1.hpp"
#include "Week2.hpp"
#include "Week3.hpp"
#include "Week4.hpp"
//#include "ParticleInfo.hpp"
//#include "Stat.hpp"

//#include "Math.hpp"



//----------------------main-------------------------------
int main(){
  std:: string s="stat";
  std:: string c="math";
  std:: string f="fourvectors";
  std::string four="week4";
  std:: string quit="q";
  std::string week;
  //  FileReader F("observedparticles.dat");
  // if(F.isValid()){
  //std::cout<<"worked"<<std::endl;
    //}

  do{
    std::cout<<" Input options are: "<<std::endl;
    std::cout<<"Calculator [math] "<<std::endl;
    std::cout<<"Statistical [stat] "<<std::endl;
    std::cout<<"FourVectors [fourvectors] "<<std::endl;
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
    if(week.compare(f)==0){
      Week3();
      match=true;
    }
    if(week.compare(quit)==0){
      break;
    }
    if(week.compare(four)==0){
      Week4();
      match=true;
    }
    if(match==false){
      std::cout<<"sorry not an option"<<std::endl;
    }
  }while(1);
  


  return 0;
}
 

