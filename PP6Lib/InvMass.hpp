#ifndef INPUT_InvMass_HPP
#define INPUT_InvMass_HPP

#include "Particle.hpp"
//This is a class to hold the invariant mass of a combination of 2 particles along with the eventnumbers of the particles.
class InvMass{
private:
  int EventNum1;
  int EventNum2;
  double M;  //invariant mass
public:
  //constructors
  InvMass(Particle P1, Particle P2);
  
  //gets
  int getEvent1(){return EventNum1;}
  int getEvent2(){return EventNum2;}
  double getM(){return M;}
};





#endif
