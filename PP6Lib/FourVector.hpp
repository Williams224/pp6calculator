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
  ThreeVector R;
  double I;
  double InvariantLength() const ;
  
public:

  //constructors
  FourVector(){ct=0;R.setX(0);R.setY(0);R.setZ(0);};   //empty decleration
  FourVector(double ct_, double x_, double y_ , double z_)   //take input
    :ct(ct_){R.setX(x_);R.setY(y_);R.setZ(z_);I=InvariantLength();}
  FourVector(const FourVector& tmp): ct(tmp.ct),R(tmp.R),I(tmp.I) // clone constructor
  {}

    FourVector(double _ct, const ThreeVector& Three):ct(_ct),I(InvariantLength()){ R=Three;}
  //set functions
  void Setct(double CT);
  void Setx(double X);
  void Sety(double Y);
  void Setz(double Z);
  void SetThreeVector(ThreeVector& tmp){
    R=tmp;
  }
  //get functions
  double getY()const {return R.getY();}
  double getX() const {return R.getX();}
  double getZ()const {return R.getZ();}
  double getCT()const {return ct;}
  double getInterval() const{return I;}
  ThreeVector getThreeVector()const;

  double GetInvariantLength()const ;
  //void SetFourVector();
  
  FourVector* Boost(double v);
  void PrintFourVector() const;
  Like GetFourVectorType();
  
  
  //operator overloads
  FourVector& operator+=(const FourVector& rhs){
    ct+=rhs.ct;
    R+=rhs.getThreeVector();
    I=InvariantLength();
    return *this;
  }
  FourVector& operator-=(const FourVector& rhs){
    ct-=rhs.ct;
    R-=rhs.getThreeVector();
    I=InvariantLength();
    return *this;
  }
  FourVector& operator *=(double rhs){
    R*=rhs;
    ct=rhs;
    I=InvariantLength();
    return *this;
  }
  FourVector& operator /=(double rhs){
    if(rhs!=0){
      R/=rhs;
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
      R=rhs.R;
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





