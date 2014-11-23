#include<iostream>
#include<cmath>
#include"FourVector.hpp"
#include"ThreeVector.hpp"
#include"Particle.hpp"



//calculate invariant length of fourvector


//boost a fourvector in the z direction with a speed v




void Week3(){
  
  FourVector *Boosted = 0;
  FourVector *F = new FourVector();
  std::cout<<"enter components of four vector"<<std::endl;
  std::cin>>*F;
  /*ThreeVector Three;
  Three=F->getThreeVector();
  std::cout<<Three<<std::endl;*/
  
  /*ThreeVector *T = new ThreeVector();
     ThreeVector* Tfull =new ThreeVector(5,4,3);
     // ThreeVector* Tclone= new ThreeVector(*Tfull);
      T->PrintThree(); 
      Tfull->PrintThree();
     //  Tclone->PrintThree();
     std::cout<<"Phi=  "<<Tfull->getPhi()<<std::endl;
     std::cout<<"R=   "<<Tfull->getR()<<std::endl;
     std::cout<<"Theta=   "<<Tfull->getTheta()<<std::endl;
     
     T->setPolars(7.07,1.132,0.674);
     
     T->PrintThree();
     std::cout<<"----------------------------------"<<std::endl;
     
     ThreeVector O(5,4,3);
     ThreeVector D(6,7,8);
     O+=D;
     std::cout<<"O+=D=  "<<std::endl;
     O.PrintThree();
     O-=D;
     std::cout<<"O-=D=  "<<std::endl;
     O.PrintThree();
     O*=3;
     std::cout<<"O*3=  "<<std::endl;
     O.PrintThree();
     O/=3;
     std::cout<<"O/3=  "<<std::endl;
     O.PrintThree();
     
     std::cout<<O<<std::endl;
     std::cin>>O;
     std::cout<<O<<std::endl;*/
  ThreeVector Th= F->getThreeVector();
  Particle *B0= new Particle(511,5279.58,Th);
  std::cout<<"PDG code=  "<<B0->getPDGCode()<<std::endl;
  std::cout<<"Energy=  "<<B0->getEnergy()<<std::endl;
  
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

