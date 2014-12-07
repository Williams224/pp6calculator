#include "Algorithms.hpp"
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>

void Algorithms(){
  srand(time(NULL));
  std::cout<<"do something"<<std::endl;
  std::vector<int> V; 
  
  
  for(int i=0;i<10;i++){
    V.push_back(rand()%100);	     
  }
  std::cout<<"got here"<<std::endl;
  std::copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, "\n"));
  std::cout<<" Min element= "<< *std::min_element(V.begin(),V.end());
  std::cout<<" Max element=  "<< *std::max_element(V.begin(),V.end())<<std::endl;
  std::sort(V.begin(),V.end());
  std::cout<<"Sorted elements are:  "<<std::endl;
  std::copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
