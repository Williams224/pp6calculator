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
  return acos(z/(sqrt(x*x+y*y+z*z)));
}

double ThreeVector::getTheta() const{
  return sqrt(x*x+y*y+z*z);
}

