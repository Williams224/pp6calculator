#include "FileReader.hpp"
#include <sstream>
#include "Week4.hpp"

void Week4(){
  FileReader File("/Users/Tim/PhD/Cpp/pp6calculator.git/PP6Lib/PDG.dat");
  if(File.isValid()){
    //int n=0;
    while(File.nextLine()){
      double Field=File.GetField<int>(3);
      std::cout<<"Field=  "<<Field<<std::endl;
    }
  }
      
      
}
