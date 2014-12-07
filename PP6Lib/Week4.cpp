#include "FileReader.hpp"
#include <sstream>
#include "Week4.hpp"
#include<vector>
#include"ParticleInfo.hpp"
#include<iostream>
#include "Algorithms.hpp"
#include "Particle.hpp"
#include "InvMass.hpp"
#include<algorithm>

bool InvSortFunction(InvMass i, InvMass j){
  return (i.getM()>j.getM());
    }

void Week4(){
  FileReader File("/Users/Tim/PhD/Cpp/pp6calculator.git/PP6Lib/PDG.dat");
  std::vector<std::string> Name;
  std::vector<int> pdgcode;
  std::vector<int> charge;
  std::vector<double> mass;
  if(File.isValid()){
    //int n=0;
    while(File.nextLine()){
      Name.push_back(File.GetField<std::string>(1));
      pdgcode.push_back(File.GetField<int>(2));
      charge.push_back(File.GetField<int>(3));
      mass.push_back(File.GetField<double>(4));
    }
  }

  auto iterName=Name.begin();
  auto iterpdg=pdgcode.begin();;
  auto itercharge=charge.begin();
  auto itermass=mass.begin();
  auto iterNameend=Name.end();
  for(;iterName!=iterNameend;++iterName,++iterpdg,++itercharge,++itermass){
    std::cout<<"Name: "<<*iterName<<"  pdgcode: "<<*iterpdg<<"  charge: "<<*itercharge<<"  mass: "<<*itermass<<std::endl;
  }
  std::string filepath="/Users/Tim/PhD/Cpp/pp6calculator.git/PP6Lib/PDG.dat";
  ParticleInfo *Database= new ParticleInfo(filepath);
  std::string N="B+";
  int code=0;
  code=Database->getPDGCode(N);
  std::cout<<"pdgcode=  "<<code<<std::endl;
  int Charge=0;
  Charge=Database->getCharge(code);
  std::cout<<"charge=  "<<Charge<<std::endl;
  std::string returnname;
  returnname=Database->getName(code);
  std::cout<<"name= "<<returnname<<std::endl;
  std::cout<<"Mass=  "<<Database->getMassGeV(code)<<std::endl;


  //algorithms exercise 5-----------------------
  Algorithms();
  //Invariant mass sort.

  std::vector<Particle> Muplus;
  std::vector<Particle> Muminus;
  FileReader Observed("/Users/Tim/PhD/Cpp/pp6calculator.git/PP6Lib/observedparticles.dat");
  if(Observed.isValid()){
    while(Observed.nextLine()){
      std::string run=Observed.GetField<std::string>(6);
      if(run.compare("run4.dat")==0){
	std::string polarity=Observed.GetField<std::string>(2);
	if(polarity.compare("mu+")==0){
	  int pdg=Database->getPDGCode(polarity);
	  Particle *MUPLUS= new Particle(pdg,Database->getMassGeV(pdg),Observed.GetField<int>(1));
	  MUPLUS->setThreeMomentum(Observed.GetField<double>(3),Observed.GetField<double>(4),Observed.GetField<double>(5));
	  Muplus.push_back(*MUPLUS);
	  delete MUPLUS;
	}
	if(polarity.compare("mu-")==0){
	  int pdg=Database->getPDGCode(polarity);
	  Particle *MUMINUS= new Particle(pdg,Database->getMassGeV(pdg),Observed.GetField<int>(1));
	  MUMINUS->setThreeMomentum(Observed.GetField<double>(3),Observed.GetField<double>(4),Observed.GetField<double>(5));
	  Muminus.push_back(*MUMINUS);
	  delete MUMINUS;
	}
      }
    }
  }
  std::vector<InvMass> Invariantmasses;
 
  auto mumend=Muminus.end();
  
  auto mupend=Muplus.end();
  for(auto mup=Muplus.begin();mup!=mupend;++mup){ 
    for(auto mum=Muminus.begin();mum!=mumend;++mum){
      InvMass *Combination = new InvMass(*mup,*mum);
      Invariantmasses.push_back(*Combination);
      // Combination;
    }
  }
  auto Combegin=Invariantmasses.begin();
  auto Comend=Invariantmasses.end();
  for(;Combegin!=Comend;++Combegin){
    std::cout<<" M=  "<<Combegin->getM()<<" PID1= "<<Combegin->getEvent1()<<" PID2= "<<Combegin->getEvent2()<<std::endl;
  }
  std::sort(Invariantmasses.begin(),Invariantmasses.end(),InvSortFunction);
  std::cout<<"now sorted---------------------------------"<<std::endl;
  for(auto Combegin=Invariantmasses.begin();Combegin!=Comend;++Combegin){
    std::cout<<" M=  "<<Combegin->getM()<<" PID1= "<<Combegin->getEvent1()<<" PID2= "<<Combegin->getEvent2()<<std::endl;
  }
}
