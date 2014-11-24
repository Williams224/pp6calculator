#include"ThreeVector.hpp"
#include<iostream>
#include<cmath>

void ThreeVector::compute_length()  {
  length= (sqrt(x*x+y*y+z*z));
}

void ThreeVector::setX(double x_){
  x=x_;
  compute_length();
}

void ThreeVector::setY(double y_){
  y=y_;
  compute_length();
}

void ThreeVector::setZ(double z_){
  z=z_;
  compute_length();
}

void ThreeVector::PrintThree() const{
  std::cout<<"x= "<<x<<std::endl;
  std::cout<<"y=  "<<y<<std::endl;
  std::cout<<"z=  "<<z<<std::endl;
}

double ThreeVector::getlength() const{
    return length;
}

double ThreeVector::getPhi() const{
  return atan(y/x);
}

double ThreeVector::getR() const{
   return sqrt(x*x+y*y+z*z);
}

double ThreeVector::getTheta() const{

  return acos(z/(sqrt(x*x+y*y+z*z)));
}

void ThreeVector::setPolars(double r, double theta, double phi){
  x=r*sin(theta)*cos(phi);
  y=r*sin(theta)*sin(phi);
  z=r*cos(theta);

}

std::ostream& operator<<(std::ostream& stream, const ThreeVector& Th){
  stream<<"(";
    stream<<Th.getX()<<","<<Th.getY()<<","<<Th.getZ()<<")";
    return stream;
      }

std::istream& operator>>(std::istream& stream, ThreeVector& Th){
  double Xx,Yy,Zz;
  stream>>Xx>>Yy>>Zz;
  Th.setX(Xx);
  Th.setY(Yy);
  Th.setZ(Zz);
  return stream;
}
