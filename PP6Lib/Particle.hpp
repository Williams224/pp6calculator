#ifndef INPUT_PARTICLE_HPP
#define INPUT_PARTICLE_HPP
#include"FourVector.hpp"
#include<cmath>

class Particle{
private:
   int pdgcode;
  double Mass;
  FourVector Momentum;
 
public:

  //get functions
  double getEnergy() const {return Momentum.getCT();}
  FourVector& getFourMomentum() {return Momentum;}
  double getMagMomentum() const;
  double getMassGeV() const {return Mass;}
  int getPDGCode()const{return pdgcode;}
  ThreeVector& getThreeMomentum() const {return Momentum.getThreeVector();}

  //constructors
  Particle();
  Particle(const Particle& tmp);
  Particle(int _pdgcode, double _mass):pdgcode(_pdgcode),Mass(_mass){};
  Particle(int _pdgcode, double _mass, ThreeVector& _Th):pdgcode(_pdgcode),Mass(_mass){
    Momentum.Setx(_Th.getX());
    Momentum.Sety(_Th.getY());
    Momentum.Setz(_Th.getZ());
    double E= sqrt(Mass*Mass+Momentum.getX()*Momentum.getX()+Momentum.getY()*Momentum.getY()+Momentum.getZ()*Momentum.getZ());
    Momentum.Setct(E);
  }
  Particle(int _pdgcode, double _E, double _x, double _y, double _z):pdgcode(_pdgcode){
    Momentum.Setct(_E);
    Momentum.Setx(_x);
    Momentum.Sety(_y);
    Momentum.Setz(_z);
    Mass=sqrt(Momentum.getInterval());
  }
  

  //set functions
  void setMass(double _mass){Mass=_mass;}
  void setPDGCode(int _pdgcode){pdgcode=_pdgcode;}
  void setThreeMomentum(ThreeVector& _Th);
  void setThreeMomentum(double _x, double _y, double _z);
};

#endif
