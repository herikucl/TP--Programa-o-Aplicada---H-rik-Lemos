#include <iostream>
#include <fstream>
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

class No{
  public:
  int v;
  No* prox;

  No(int e){
    this->v=e;
    this->prox=NULL;
  }
  void DefinirProx(No* p){
    prox=p;
  }
  int getValor(){
    return v;
  }
  No* getProx(){
    return prox;
  }
};

class ListaEncadeada{
public:
No* primeiro;
No* ultimo;

ListaEncadeada(){
  primeiro=ultimo=NULL;
}
bool Vazia(){
  return (primeiro==NULL);
}
void NovoElemento(int vv){
  No* novo = new No(vv);
  if(Vazia()){
    primeiro=ultimo=novo;
  }else{
    ultimo->DefinirProx(novo);
    ultimo=novo;
  } 
}

};


int main() {
  ofstream saida;
  ifstream entrada;
  string verificador;
  char resp1;
  int qntG;

  while(verificador!="sim"){
    cout<<"Deseja gravar ou ler no banco de dados? Gravar [g] / Ler [l]"<<endl;
    cin>>resp1;
    if(resp1=='g'){
      cout<<"Quantos elementos deseja gravar?"<<endl;
      cin>>qntG;

    }

  }


}