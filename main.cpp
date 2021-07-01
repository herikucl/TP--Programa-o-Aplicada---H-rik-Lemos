#include <iostream>
#include <math.h>
using namespace std;

struct tInvestimento{
  int Periodo;
  float Montante,JurosAno;

    float MontanteFinalJS(int p){
    return (Montante*JurosAno*p)+Montante;
    }
    float MontanteFinalJS(){
    return (Montante*JurosAno*Periodo)+Montante;
    }


    float MontanteFinalJC(int p){
    return Montante*pow((1+JurosAno),p);
    }
    float MontanteFinalJC(){
    return Montante*pow((1+JurosAno),Periodo);
    }

    float ConversaoJanoJmes(){
    return pow(1+JurosAno,(1.0/12.0))-1;
    }
};

int main() {
  
}