#include"Particle.hpp"
#include<cmath>

double Particle::getMagMomentum() const{
  double Mag;
  Mag=sqrt(Momentum.getX()*Momentum.getX()+Momentum.getY()*Momentum.getY()+Momentum.getZ()*Momentum.getZ());
  return Mag;
}

void Particle::setThreeMomentum(ThreeVector& _Th){
  double E;
  E=sqrt((_Th.getX()*_Th.getX())+(_Th.getY()*_Th.getY())+(_Th.getZ()*_Th.getZ())+(Mass*Mass));
  Momentum.Setct(E);
  Momentum.Setx(_Th.getX());
  Momentum.Sety(_Th.getY());
  Momentum.Setz(_Th.getZ());
}

void Particle::setThreeMomentum(double _x, double _y, double _z){
  Momentum.Setx(_x);
  Momentum.Sety(_y);
  Momentum.Setz(_z);
  double E=sqrt(Momentum.getX()*Momentum.getX()+Momentum.getY()*Momentum.getY()+Momentum.getZ()*Momentum.getZ());
  Momentum.Setct(E);
}
