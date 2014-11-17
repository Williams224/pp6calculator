#include<iostream>
#include<cmath>
#include"FourVector.hpp"

const double c=300000000; //set the speed of light

//calculate invariant length of fourvector
double InvariantLength(FourVector *f){
  return ((f->ct)*(f->ct)-(f->x)*(f->x)-(f->y)*(f->y)-(f->z)*(f->z));
}

//boost a fourvector in the z direction with a speed v
FourVector* Boost(FourVector* old, double v){
  FourVector *boosted= createFourVector();
  double beta=v/c;
  double gamma=1/sqrt(1-(beta*beta));
  boosted->ct=gamma*((old->ct)-(beta*old->z));
  boosted->x=old->x;
  boosted->y=old->y;
  boosted->z=gamma*((old->z)-(beta*old->ct));
  return boosted;

}

void PrintFourVector(FourVector* f){
  std::cout<<"ct=  "<<f->ct<<std::endl;
  std::cout<<"x=  "<<f->x<<std::endl;
  std::cout<<"y=  "<<f->y<<std::endl;
  std::cout<<"z=  "<<f->z<<std::endl;
}





void Week3(){
  FourVector *F=createFourVector();
  FourVector *Boosted= 0;
  std::cout<<"enter time component"<<std::endl;
  std::cin>>F->ct;
  std::cout<<"enter x component"<<std::endl;
  std::cin>>F->x;
  std::cout<<"enter y component"<<std::endl;
  std::cin>>F->y;
  std::cout<<"enter z component"<<std::endl;
  std::cin>>F->z;

  //output the four length of the input vector
  std::cout<<"Four length=  "<<InvariantLength(F)<<std::endl;

  //boost the vector and get a new boosted vector.
  Boosted=Boost(F,270000000);

  //std::cout<<"this is week3"<<std::endl;
  PrintFourVector(Boosted);
  
  //output the four length after the boost to check it is invariant.
  std::cout<<"After Four Length=  "<<InvariantLength(Boosted)<<std::endl;
}

