#include <iostream>
#include<cstdlib>
#include<cmath>
#include "Math.hpp"
#include "Week2.hpp"

void Average(int n, double *A, double& M){
  double Sum;
  for(int j=0;j<n;j++){
    Sum+=A[j];
  }
  double N=n;
  M=Sum/N;
}
double StandardDeviation(int n, double *A, double M){
  double Sum;
  for(int k=0;k<n;k++){
    Sum+=(A[k]-M)*(A[k]-M); 
  }
  double N=n;
  return (sqrt(Sum/N));
}

void Week2(){
  srand(time(NULL));
  double Px[100];
  double Py[100];
  double Pz[100];
  double M[100];
  double E[100];
  double Mean;

  for(int i=0; i<100; ++i){
    Px[i]=(1+rand()%1000)/10.0;
    Py[i]=(1+rand()%1000)/10.0;
    Pz[i]=(1+rand()%1000)/10.0;
    M[i]=(1+rand()%1000)/10.0;
    E[i]=sqrt(((Px[i]*Px[i])+(Py[i]*Py[i])+(Pz[i]*Pz[i])+(M[i]*M[i])));
  }
  //PrintArray(100,Px);
  //PrintArray(100,Py);
  //PrintArray(100,Pz);
  PrintArray(100,E);
  Average(100,E,Mean);
  print(StandardDeviation(100,E,Mean));
  std::cout<<"Mean = "<<Mean<<std::endl;
  std::cout<<" this is the week2 function"<<std::endl;


}
