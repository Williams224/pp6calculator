#include<iostream>
#include<cmath>
#include<cstdlib>
#include"FourVector.hpp"
#include"ThreeVector.hpp"
#include"Particle.hpp"
#include "FileReader.hpp"
#include "Math.hpp"


//calculate invariant length of fourvector


//boost a fourvector in the z direction with a speed v




void Week3(){
  
  FourVector *Boosted = 0;
  FourVector *F = new FourVector();
  std::cout<<"enter components of four vector"<<std::endl;
  std::cin>>*F;

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



  //---------------------homework-------------------------------------
  FileReader f("/Users/Tim/PhD/Cpp/pp6calculator.git/PP6Lib/observedparticles.dat"); //get data from file
  std::string Run= "run4.dat";
  std::string muplus="mu+";
  std::string muminus="mu-";
  Particle *Muplus[1005];
  Particle *Muminus[1005];
  int itplus=0;
  int itminus=0;
  if(f.isValid()){
    std::cout<<"isvalid"<<std::endl;
    while(f.nextLine()){
      std::string source=f.getFieldAsString(6);
      if(source.compare(Run)==0){  //get particles that are in run4.
	std::string Name=f.getFieldAsString(2);
	if(Name.compare(muplus)==0){
	  ThreeVector tmp(f.getFieldAsDouble(3),f.getFieldAsDouble(4),f.getFieldAsDouble(5));
	  Muplus[itplus]=new Particle(f.getFieldAsInt(1),0.105658,tmp);  //as we are dealing with the same particle use pdgID field to carry event number.
	  //Eventplus[itplus]=f.getFieldAsInt(1);
	  itplus++;
	}
	if(Name.compare(muminus)==0){
	  ThreeVector tmp(f.getFieldAsDouble(3),f.getFieldAsDouble(4),f.getFieldAsDouble(5));
	  Muminus[itminus]=new Particle(f.getFieldAsInt(1),0.105658,tmp);
	  //Eventminus[itminus]=f.getFieldAsInt(1);
	  itminus++;
	}
      }
    }
  }
  
  for(int i=0;i<itminus;++i){
    std::cout<<"Energy=   "<<Muminus[i]->getEnergy()<<std::endl;
  }
  double I[200];
  int Eventplus[1005];
  int Eventminus[1005];
  int Iit=0;
  for(int a=0;a<itminus;++a){
    for(int b=0;b<itplus;++b){
      FourVector tmp;
      tmp=(Muminus[a]->getFourMomentum())+(Muplus[b]->getFourMomentum());
      std::cout<<tmp<<"   ; "<<sqrt(tmp.getInterval())<<std::endl;
      I[Iit]=sqrt(tmp.getInterval());
      Eventplus[Iit]=Muplus[b]->getPDGCode();
      Eventminus[Iit]=Muminus[a]->getPDGCode();
      Iit++;
    }
  }
  
  LinkSortArray((itplus*itminus),I,Eventplus,Eventminus);

std::cout<<"----------Top 10 Invariant Masses----------"<<std::endl;  //output table showing top 10 invariant mass contributions.
      std::cout<<"Invariant mass |"<<" Mu+ EventNumber| "<<" Mu- EventNumber| "<<std::endl;
      for(int v=0;v<10;++v){
	std::cout<<I[v]<<"       |  "<<Eventplus[v]<<"           |  "<<Eventminus[v]<<"           |  "<<std::endl;
      }

  delete F;
  delete Boosted;
}

