#ifndef INPUT_MATH_HH
#define INPUT_MATH_HH


double multiply(double x, double y);

double add(double x, double y);

double take(double x,double y);

double over(double x,double y);

void print(double z);

double NormalInput(std::string str);

double Gradient();

double Constant();

double CalcIntercept(double x, double y);

bool NewQuadratic(double x, double y, double z,double& p, double& n );

double VectorSize();

double ThreeLength(double i, double j, double k);

double FourLength(double i,double j, double k, double l);

void Swap(double& x, double& y);

void PrintArray(int n,double *A);

void SortArray(int n, double *A);


#endif
