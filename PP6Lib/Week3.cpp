#include<iostream>
#include<cmath>
#include"FourVector.hpp"



//calculate invariant length of fourvector


//boost a fourvector in the z direction with a speed v




void Week3(){
  
  FourVector *Boosted = 0;
  // F->SetFourVector();
  double CT;
  double X;
  double Y;
  double Z;

   std::cout<<"enter time component"<<std::endl;
     std::cin>>CT;
     std::cout<<"enter x component"<<std::endl;
     std::cin>>X;
     std::cout<<"enter y component"<<std::endl;
     std::cin>>Y;
     std::cout<<"enter z component"<<std::endl;
     std::cin>>Z;

     FourVector *F= new FourVector(CT,X,Y,Z);
     FourVector A(CT,X,Y,Z);
     FourVector B(4,3,2,1);
     FourVector C;
     C=A-B;
     C.PrintFourVector();
  //output the four length of the input vector
  std::cout<<"Four length=  "<<F->GetInvariantLength()<<std::endl;

  //boost the vector and get a new boosted vector.
  Boosted=F->Boost(270000000);

  //std::cout<<"this is week3"<<std::endl;
  Boosted->PrintFourVector();
  
  if((F->GetFourVectorType())==TIMELIKE){
    std::cout<<"This four vector is time like"<<std::endl;
  }
  if((F->GetFourVectorType())==SPACELIKE){
    std::cout<<"This four vector is space like"<<std::endl;
  }
  if((F->GetFourVectorType())==LIGHTLIKE){
    std::cout<<"This four vector is light like"<<std::endl;
  }
  
  //output the four length after the boost to check it is invariant.
  std::cout<<"After Four Length=  "<<Boosted->GetInvariantLength()<<std::endl;

  delete F;
  delete Boosted;
}

