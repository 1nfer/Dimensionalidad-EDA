#include <iostream>
#include <math.h>

class Distancia{
private:
  double dis;

public:
  Distancia(Punto A, Punto B){
    int d=A.GetDim();
    for(int i=0; i<d; i++)
      dis+=pow(A[i]-B[i],2.0);
    dis=sqrt(dis);
  }
 
  ~Distancia(){}

  double GetDis(){
    return dis;
  }
};
