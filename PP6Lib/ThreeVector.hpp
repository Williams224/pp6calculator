
class ThreeVector{
private:
  double x;
  double y;
  double z;
  double length;
  void compute_length();
public:
  void setX(double x_);
  void setY(double y_);
  void setZ(double z_);
  void PrintThree() const ;
};
