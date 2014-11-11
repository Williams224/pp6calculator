#include <iostream>
#include<cstdlib>
#include<cmath>
#include "Math.hpp"
#include "FileReader.hpp"
#include "Week2.hpp"


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
  std::string Name[1005];
  double X[1005];
  double Y[1005];
  double Z[1005];
  std::string Source[1005];
  int Event[1005];
  std::string SelectedName[1005];
  double SelectedX[1005];
  double SelectedY[1005];
  double SelectedZ[1005];
  double SelectedEnergy[1005];
  int SelectedEvent[1005];
  std::string NSelectedName[1005];
  double NSelectedX[1005];
  double NSelectedY[1005];
  double NSelectedZ[1005];
  double NSelectedEnergy[1005];
  int NSelectedEvent[1005];
  std::string Muplus="mu+";
  std::string Muminus="mu-";
  std::string Run="run4.dat";
  double MuMass=0.106;
  int H=0;
  double InvMass[145];
  int EvPlus[145];
  int EvMinus[145];
  
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
	//std::cout<<"file worked"<<std::endl;
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
      // std::cout<<"index=  "<<index<<std::endl;
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
	    NSelectedEvent[Nselectindex]=Event[z];
	    NSelectedX[Nselectindex]=X[z];
	    NSelectedY[Nselectindex]=Y[z];
	    NSelectedZ[Nselectindex]=Z[z];
	    NSelectedEnergy[Nselectindex]=sqrt(pow(X[z],2)+pow(Y[z],2)+pow(Z[z],2)+pow(MuMass,2));
	    NSelectedName[Nselectindex]=Name[z];
	    Nselectindex++;
	  }
	}
      }
      
      
      for(int a=0;a<Pselectindex;++a){
	for(int b=0;b<Nselectindex;++b){
	  InvMass[H]=IMass(a,b,SelectedX,SelectedY,SelectedZ,SelectedEnergy,NSelectedX,NSelectedY,NSelectedZ, NSelectedEnergy);
	  EvPlus[H]=SelectedEvent[a];
	  EvMinus[H]=NSelectedEvent[b];
	  H++;
	}
      }
      LinkSortArray((Pselectindex*Nselectindex),InvMass,EvPlus,EvMinus);
      
      std::cout<<"----------Top 10 Invariant Masses----------"<<std::endl;
      std::cout<<"Invariant mass |"<<" Mu+ EventNumber| "<<" Mu- EventNumber| "<<std::endl;
      for(int v=0;v<10;++v){
	std::cout<<InvMass[v]<<"       |  "<<EvPlus[v]<<"           |  "<<EvMinus[v]<<"           |  "<<std::endl;
      }
      

    }
    if(Operation.compare(Quit)==0){
      break;
    }
  }while(1);

}
