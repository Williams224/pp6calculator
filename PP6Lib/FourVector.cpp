#include"FourVector.hpp"
#include<iostream>
#include<cmath>


const double c=3E8; //set the speed of light


void FourVector::Setct(double CT){
  ct=CT;
  I=InvariantLength();
}

void FourVector::Setx(double X){
  R.setX(X);
  I=InvariantLength();
}

void FourVector::Sety(double Y){
  R.setY(Y);
  I=InvariantLength();
}

void FourVector::Setz(double Z){
  R.setZ(Z);
  I=InvariantLength();
}


double FourVector::InvariantLength() const {
  return (ct*ct-R.getX()*R.getX()-R.getY()*R.getY()-R.getZ()*R.getZ());
}

FourVector* FourVector::Boost(double v){
  FourVector *boosted=new FourVector();
  double beta=v/c;
  double gamma=1/sqrt(1-(beta*beta));
  boosted->Setct(gamma*(ct-(beta*R.getZ())));
  boosted->Setx(R.getX());
  boosted->Sety(R.getY());
  boosted->Setz(gamma*((R.getZ())-(beta*ct)));
  //boosted
  return boosted;

}
double FourVector::GetInvariantLength()const{
  return I;
}

ThreeVector FourVector::getThreeVector() const{
  return R;
}
  
void FourVector::PrintFourVector() const{
  std::cout<<"ct=  "<<ct<<std::endl;
  std::cout<<"x=  "<<R.getX()<<std::endl;
  std::cout<<"y=  "<<R.getY()<<std::endl;
  std::cout<<"z=  "<<R.getZ()<<std::endl;
}

Like FourVector::GetFourVectorType(){
  if (InvariantLength()<0){
    return TIMELIKE;
  }
  else if (InvariantLength()==0){
    return LIGHTLIKE;
  }
  else {
    return SPACELIKE;
  }
}

std::ostream& operator<<(std::ostream& stream, const FourVector& Th){
  stream<<"(";
  stream<<Th.getCT()<<","<<Th.getX()<<","<<Th.getY()<<","<<Th.getZ()<<")";
    return stream;
      }

std::istream& operator>>(std::istream& stream, FourVector& Th){
  double Ct,Xx,Yy,Zz;
  stream>>Ct>>Xx>>Yy>>Zz;
  Th.Setct(Ct);
  Th.Setx(Xx);
  Th.Sety(Yy);
  Th.Setz(Zz);
  return stream;
}

FourVector operator+(const FourVector& lhs, const FourVector& rhs){
  FourVector temp(lhs);
  temp+=rhs;
  return temp;

}

FourVector operator-(const FourVector& lhs, const FourVector& rhs){
  FourVector temp(lhs);
  temp-=rhs;
  return temp;

}
  
