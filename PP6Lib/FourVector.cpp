#include"FourVector.hpp"

FourVector* createFourVector(){

  return new FourVector;
}

void destroyFourVector(FourVector *&q){
  if(q){
    delete q;
    q=0;
  }
}
