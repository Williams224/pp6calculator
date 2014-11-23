
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
  void PrintThree() const ;
  double getlength() const ;
  double getPhi() const;
  double getR() const;
  double getTheta() const;
};
