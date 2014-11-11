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

double IMass(int i, int j,double *X1, double *Y1, double *Z1, double *E1, double *X2, double *Y2, double *Z2, double *E2){
  double Sq;
  Sq=pow((E1[i]+E2[j]),2)-pow((X1[i]+X2[j]),2)-pow((Y1[i]+Y2[j]),2)-pow((Z1[i]+Z2[j]),2);
  return sqrt(Sq);
}

  


void Week2(){
  std::string G="gen";
  std::string D="data";
  std::string Quit="q";
  std::string Operation;
  int index=0;
  int Pselectindex=0;
  int Nselectindex=0;
  int M=0;
  std::string Name[3000];
  double X[3000];
  double Y[3000];
  double Z[3000];
  //double Energy[3000];
  std::string Source[3000];
  int Event[3000];
  std::string SelectedName[3000];
  double SelectedX[3000];
  double SelectedY[3000];
  double SelectedZ[3000];
  double SelectedEnergy[3000];
  int SelectedEvent[3000];
  std::string NSelectedName[3000];
  double NSelectedX[3000];
  double NSelectedY[3000];
  double NSelectedZ[3000];
  double NSelectedEnergy[3000];
  int NSelectedEvent[3000];
  // std::string SelectedSource[3000];
  std::string Muplus="mu+";
  std::string Muminus="mu-";
  std::string Run="run4.dat";
  double MuMass=0.106;
  
  FileReader f("/home/tw/mpagspp6/pp6calculator.git/observedparticles.dat");
  srand(time(NULL));
 
 
  do{
    std::cout<<"enter operation:"<<std::endl;
    std::cout<<"Gen[gen]"<<std::endl;
    std::cout<<"Data[data]"<<std::endl;
    std::cin>>Operation;
    if(Operation.compare(G)==0){
      Gen();
    }
    if(Operation.compare(D)==0){
      if(f.isValid()){
	std::cout<<"file worked"<<std::endl;
	while(f.nextLine()){
	  Event[index]=f.getFieldAsInt(1);
	  Name[index]=f.getFieldAsString(2);
	  X[index]=f.getFieldAsDouble(3);
	  Y[index]=f.getFieldAsDouble(4);
	  Z[index]=f.getFieldAsDouble(5);
	  Source[index]=f.getFieldAsString(6);
	  //std::cout<<Name[index]<<",  "<<X[index]<<"  ,"<<Source[index]<<std::endl;
	  index++;
	}
      }
      std::cout<<"index=  "<<index<<std::endl;
      for(int z=0;z<=index;++z){
	if(Source[z].compare(Run)==0){
	  if(Name[z].compare(Muplus)==0){
	    SelectedEvent[Pselectindex]=Event[z];
	    SelectedX[Pselectindex]=X[z];
	    SelectedY[Pselectindex]=Y[z];
	    SelectedZ[Pselectindex]=Z[z];
	    SelectedEnergy[Pselectindex]=sqrt(pow(X[z],2)+pow(Y[z],2)+pow(Z[z],2)+pow(MuMass,2));
	    SelectedName[Pselectindex]=Name[z];
	    Pselectindex++;
	  }
	  else if(Name[z].compare(Muminus)==0){
	    NSelectedEvent[Pselectindex]=Event[z];
	    NSelectedX[Nselectindex]=X[z];
	    NSelectedY[Nselectindex]=Y[z];
	    NSelectedZ[Nselectindex]=Z[z];
	    NSelectedEnergy[Nselectindex]=sqrt(pow(X[z],2)+pow(Y[z],2)+pow(Z[z],2)+pow(MuMass,2));
	    NSelectedName[Nselectindex]=Name[z];
	    Nselectindex++;
	  }
	}
      }
      
      for(int j=0;j<Pselectindex;++j){
	std::cout<<SelectedName[j]<<", "<<SelectedX[j]<<", "<<SelectedY[j]<<", "<<SelectedZ[j]<<", "<<SelectedEnergy[j]<<std::endl;
      }
      for(int k=0;k<Nselectindex;++k){
        std::cout<<NSelectedName[k]<<", "<<NSelectedX[k]<<", "<<NSelectedY[k]<<", "<<NSelectedZ[k]<<", "<<NSelectedEnergy[k]<<std::endl;
      }
      int cout=0;
      for(int a=0;a<Pselectindex;++a){
	for(int b=0;b<Nselectindex;++b){
	  std::cout<<IMass(a,b,SelectedX,SelectedY,SelectedZ,SelectedEnergy,NSelectedX,NSelectedY,NSelectedZ, NSelectedEnergy)<<std::endl;
	  cout++;
	}
      }
      std::cout<<cout<<std::endl;
	  
      

    }
    if(Operation.compare(Quit)==0){
      break;
    }
    std::cout<<" this is the week2 function"<<std::endl;
  }while(1);

}
