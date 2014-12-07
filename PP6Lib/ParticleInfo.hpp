#ifndef PARTICLEINFO_HPP
#define PARTICLEINFO_HPP

#include"FileReader.hpp"
#include<map>

class ParticleInfo {
 private:
  //private constructors
  ParticleInfo(const ParticleInfo&);
  ParticleInfo& operator=(const ParticleInfo&);
  //getPDGCode map
  typedef std::map<std::string, int> PartIdCont;
  PartIdCont particleIds;
  typedef std::map<int, int> PartChargeCont;
  PartChargeCont particleCharges;
  typedef std::map<int,std::string> PartNameCont;
  PartNameCont particleNames;
  typedef std::map<int,double> PartMassMeVCont;
  PartMassMeVCont particleMassMeV;
  typedef std::map<int,double> PartMassGeVCont;
  PartMassGeVCont particleMassGeV;
  
 public:

//constructor
  ParticleInfo(std::string filepath){
    FileReader Input(filepath);
    if(Input.isValid()){
      while(Input.nextLine()){
	particleIds.insert(std::make_pair(Input.GetField<std::string>(1),Input.GetField<int>(2)));
	particleCharges.insert(std::make_pair(Input.GetField<int>(2),Input.GetField<int>(3)));
	particleNames.insert(std::make_pair(Input.GetField<int>(2),Input.GetField<std::string>(1)));
	particleMassMeV.insert(std::make_pair(Input.GetField<int>(2),Input.GetField<double>(4)));
	particleMassGeV.insert(std::make_pair(Input.GetField<int>(2),Input.GetField<double>(4)));
      }
			    
     
    }
  }
      
  //get members
  int getPDGCode(const std::string& name);
  int getCharge(int pdgcode);
  std::string getName(int pdgcode);
  double  getMassMeV(int pdgcode);
  double getMassGeV(int pdgcode);
  };
  
#endif 
