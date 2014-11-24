#include "FileReader.hpp"
#include <sstream>
#include "Week4.hpp"
#include<vector>
#include"ParticleInfo.hpp"
#include<iostream>

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
  
}
