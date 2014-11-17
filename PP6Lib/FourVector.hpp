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
  void Setct(double CT);
  void Setx(double X);
  void Sety(double Y);
  void Setz(double Z);
  
  FourVector(){ct=0;x=0;y=0;z=0;};   //empty decleration
  FourVector(double ct_, double x_, double y_ , double z_)   //take input
    :ct(ct_),x(x_),y(y_),z(z_){I=InvariantLength();}
  double GetInvariantLength()const ;
  //void SetFourVector();
  
  FourVector* Boost(double v);
  void PrintFourVector() const;
  Like GetFourVectorType();
  
};






