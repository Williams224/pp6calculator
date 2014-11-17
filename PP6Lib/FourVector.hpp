struct FourVector{   //data structure to hold fourvector
  double ct;
  double x;
  double y;
  double z;
};

FourVector* createFourVector();

void destroyFourVector(FourVector *&q);

