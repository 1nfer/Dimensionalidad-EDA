#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

class Punto{
  int dim; //dimensiones
  vector<double> coords; //coordenadas

public:
  Punto(int k){ //generar punto con k dimensiones
    dim=k;
    for(int i=0; i<k; i++)
      coords.push_back((rand()+rand()*rand()) / 1000000000.0);
  }

  ~Punto(){}

  int GetDim(){
    return dim;
  }

  double operator[] (int pos){
    return coords[pos];
  }
};