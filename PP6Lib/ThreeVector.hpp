#ifndef INPUT_THREEVECTOR_HPP
#define INPUT_THREEVECTOR_HPP

#include<iostream>
class ThreeVector{
private:
  double x;
  double y;
  double z;
  double length;
  void compute_length();
public:
  //constructors
  ThreeVector(){x=0;y=0;z=0;length=0;}; //empty constructor.
  ThreeVector(double x_, double y_, double z_):x(x_),y(y_),z(z_){compute_length();}
  ThreeVector(const ThreeVector& tmp):x(tmp.x),y(tmp.y),z(tmp.z){}
  void setX(double x_);
  void setY(double y_);
  void setZ(double z_);
  double getX()const {return x;};
  double getY()const {return y;};
  double getZ()const {return z;};
  void PrintThree() const ;
  double getlength() const ;
  double getPhi() const;
  double getR() const;
  double getTheta() const;
  void setPolars(double r, double theta, double phi);
  ThreeVector& operator+=(const ThreeVector& rhs){
    x+=rhs.x;
    y+=rhs.y;
    z+=rhs.z;
    return *this;
  }
  ThreeVector& operator-=(const ThreeVector& rhs){
    x-=rhs.x;
    y-=rhs.y;
    z-=rhs.z;
    return *this;
  }
  ThreeVector& operator*=(double rhs){
    x=x*rhs;
    y=y*rhs;
    z=z*rhs;
    return *this;
  }
  ThreeVector& operator/=(double rhs){
    if(rhs!=0){
      x=x/rhs;
      y=y/rhs;
      z=z/rhs;
      return*this;
    }
    else{
      //std::cout<<"can not divide by zero"<<std::endl;
      return*this;
    }
      
  }
  ThreeVector& operator=(const ThreeVector& rhs){
   if(&rhs != this){
     x=rhs.x;
     y=rhs.y;
     z=rhs.z;
    }
    return *this;
  }



};

std::ostream& operator<<(std::ostream& stream, const ThreeVector& Th);

std::istream& operator>>(std::istream& stream, ThreeVector& Th);


#endif
