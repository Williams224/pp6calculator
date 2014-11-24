#include<iostream>
#include<map>
#include"ParticleInfo.hpp"

int ParticleInfo::getPDGCode(const std::string& name){
  
  PartIdCont::iterator p = particleIds.find(name);
  std::cout<<"Name:  "<<(*p).second<<std::endl;
  return (*p).second;
}

int ParticleInfo::getCharge(int pdgcode){
  PartChargeCont::iterator C=particleCharges.find(pdgcode);
  return (*C).second;

}

std::string ParticleInfo::getName(int pdgcode){
  PartNameCont::iterator N=particleNames.find(pdgcode);
  return (*N).second;
}

double ParticleInfo::getMassGeV(int pdgcode){
  PartMassGeVCont::iterator M=particleMassGeV.find(pdgcode);
  return (*M).second;
}
