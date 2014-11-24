#ifndef INPUT_FOURVECTOR_HPP
#define INPUT_FOURVECTOR_HPP

#include"ThreeVector.hpp"

enum Like {
  SPACELIKE,
  TIMELIKE,
  LIGHTLIKE
};

class  FourVector{  //data structure to hold fourvector
private:
  double ct;
  double x;
  double y;
  double z;
  double I;
  double InvariantLength() const ;
public:

  //constructors
  FourVector(){ct=0;x=0;y=0;z=0;};   //empty decleration
  FourVector(double ct_, double x_, double y_ , double z_)   //take input
    :ct(ct_),x(x_),y(y_),z(z_){I=InvariantLength();}
  FourVector(const FourVector& tmp): ct(tmp.ct),x(tmp.x),y(tmp.y),z(tmp.z),I(tmp.I) // clone constructor
  {}

  FourVector(double _ct, const ThreeVector& Three){
    ct=_ct;
    x=Three.getX();
    y=Three.getY();
    z=Three.getZ();
    I=InvariantLength();
  }
  //set functions
  void Setct(double CT);
  void Setx(double X);
  void Sety(double Y);
  void Setz(double Z);
  void SetThreeVector(ThreeVector& tmp){
    x=tmp.getX();
    y=tmp.getY();
    z=tmp.getZ();
  }
  //get functions
  double getY()const {return y;}
  double getX() const {return x;}
  double getZ()const {return z;}
  double getCT()const {return ct;}
  double getInterval() const{return I;}
  ThreeVector& getThreeVector()const;

  double GetInvariantLength()const ;
  //void SetFourVector();
  
  FourVector* Boost(double v);
  void PrintFourVector() const;
  Like GetFourVectorType();
  
  
  //operator overloads
  FourVector& operator+=(const FourVector& rhs){
    ct+=rhs.ct;
    x+=rhs.x;
    y+=rhs.y;
    z+=rhs.z;
    I=InvariantLength();
    return *this;
  }
  FourVector& operator-=(const FourVector& rhs){
    ct-=rhs.ct;
    x-=rhs.x;
    y-=rhs.y;
    z-=rhs.z;
    I=InvariantLength();
    return *this;
  }
  FourVector& operator *=(double rhs){
    x=x*rhs;
    y=y*rhs;
    z=rhs;
    ct=rhs;
    I=InvariantLength();
    return *this;
  }
  FourVector& operator /=(double rhs){
    if(rhs!=0){
      x=x/rhs;
      y=y/rhs;
      z=z/rhs;
      ct=ct/rhs;
      I=InvariantLength();
      return *this;
    }
    else{
      return *this;
    }
  }

  FourVector& operator=(const FourVector& rhs){
    if(&rhs != this){
      ct=rhs.ct;
      x=rhs.x;
      y=rhs.y;
      z=rhs.z;
      I=InvariantLength();
    }
    return *this;
  }


};

std::ostream& operator<<(std::ostream& stream, const FourVector& Th);
std::istream& operator>>(std::istream& stream, FourVector& Th);

FourVector operator+(const FourVector& lhs, const FourVector& rhs);

FourVector operator-(const FourVector& lhs, const FourVector& rhs);

#endif





