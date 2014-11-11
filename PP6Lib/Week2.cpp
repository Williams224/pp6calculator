#include <iostream>
#include<cstdlib>
#include<cmath>
#include "Math.hpp"
#include "FileReader.hpp"
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

void Gen(){
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
  std::cout<<"Standard Deviation= "<<(StandardDeviation(100,E,Mean))<<std::endl;
  std::cout<<"Mean = "<<Mean<<std::endl;
}


void Week2(){
  std::string G="gen";
  std::string D="data";
  std::string Quit="q";
  std::string Operation;
  int index;
  std::string Name[3000];
  double X[3000];
  double Y[3000];
  double Z[3000];
  
  
  FileReader f("/home/tw/mpagspp6/pp6calculator.git/observedparticles.dat");
  srand(time(NULL));
 
 
  do{
    std::cout<<"enter operation:"<<std::endl;
    std::cout<<"Gen[gen]"<<std::endl;
    std::cout<<"Data[data]"<<std::endl;
    std::cin>>Operation;
    if(Operation.compare(G)==0){
      Gen();

      if(f.isValid()){
	std::cout<<"file worked"<<std::endl;
	while(f.nextLine()){
	  
	  



	}
      }
    }
    if(Operation.compare(D)==0){
      

    }
    if(Operation.compare(Quit)==0){
      break;
    }
    std::cout<<" this is the week2 function"<<std::endl;
  }while(1);

}
