#include "Punto.h"
#include "Distancia.h"
#include<algorithm> 

vector<Punto> GenPoints(int n, int k){ //Generar N puntos con k dimensiones
  vector<Punto> puntos;

  for(int i=0; i<n; i++){
    Punto A(k);
    puntos.push_back(A);
  }
  return puntos;
}

vector<double> GetDistances(int n, int k){ //Calcular distancias entre todos los puntos
  vector<double> distancias;
  vector<Punto> puntos=GenPoints(n,k);

  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      Distancia D(puntos[i],puntos[j]);
      distancias.push_back(D.GetDis());
    }
  }
  sort(distancias.begin(),distancias.end());
  return distancias;
}

void Granularidad(int n, int k){
  vector<double> distancias=GetDistances(n,k);
  int nDiv=25; // #divisiones o barras
  double sizeDiv = distancias.back()/nDiv; // tam division
  int s = distancias.size();
  double div = sizeDiv; //limite de la division
  int count=0;
  cout<<"Grado de Granularidad: "<<sizeDiv<<endl;
  for(int i=0; i<nDiv; i++){
    int amount = 0;
      double d=distancias[count];
    while(count<s && distancias[count] <= div){
      double d=distancias[count];
      amount++;
      count++;
    }
    cout<<div<<endl;
    cout<<amount<<endl;
    div=div+sizeDiv;
  }
}

int main(){
  srand(time(NULL));
  int n(100), k(1000); //n puntos //k dimensiones

  Granularidad(n,k);
  return 0;
}
