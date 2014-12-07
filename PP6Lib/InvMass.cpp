#include"InvMass.hpp"
#include"ThreeVector.hpp"
#include"Particle.hpp"

InvMass::InvMass(Particle P1, Particle P2){
  EventNum1=P1.getEventNumber();
  EventNum2=P2.getEventNumber();
  double E1=P1.getEnergy();
  double E2=P2.getEnergy();
  M=((E1+E2)*(E1+E2))-pow(((P1.getThreeMomentum().getX())+(P2.getThreeMomentum().getX())),2)-pow(((P1.getThreeMomentum().getY())+(P2.getThreeMomentum().getY())),2)-pow(((P1.getThreeMomentum().getZ())+(P2.getThreeMomentum().getZ())),2);
}
