#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

struct tInvestimento{
  float Montante,JurosAno,Periodo;

    void setMontante(float m){
      Montante=m;
    }
    void setPeriodo(float p){
      Periodo=p;
    }
    void setJurosAN(float an){
      JurosAno=an;
    }
    float getMontante(){
      return Montante;
    }
    float getPeriodo(){
      return Periodo;
    }
    float getJurosAN(){
      return JurosAno;
    }
    

    float MontanteFinalJS(float p){
    return (Montante*JurosAno*p)+Montante;
    }
    float MontanteFinalJS(){
    return (Montante*JurosAno*Periodo)+Montante;
    }

    float MontanteFinalJC(float p){
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
  float v;
  tInvestimento invest;
  No* prox;

  No(float e){
    this->v=e;
    this->prox=NULL;
  }
  No(tInvestimento t){
    this->invest=t;
    this->prox=NULL;
  }
  void DefinirProx(No* p){
    prox=p;
  }
  float getValor(){
    return v;
  }
  void getValorI(){
    cout<<invest.getMontante()<<" "<<invest.getPeriodo()<<" "<<invest.getJurosAN()<<endl;
  }

  tInvestimento getValorO(){
    return invest;
  }
  No* getProx(){
    return prox;
  }
};

class ListaEncadeada{
  ofstream saida;
  public:
  No* primeiro;
  No* ultimo;


  ListaEncadeada(){
    primeiro=ultimo=NULL;
  }
  bool Vazia(){
    return (primeiro==NULL);
  }
  void NovoElemento(float vv){
    No* novo = new No(vv);
    if(Vazia()){
      primeiro=ultimo=novo;
    }else{
      ultimo->DefinirProx(novo);
      ultimo=novo;
    }
  }
  void NovoElemento(tInvestimento t){
    No* novo = new No(t);
    if(Vazia()){
      primeiro=ultimo=novo;
    }else{
      ultimo->DefinirProx(novo);
      ultimo=novo;
    }
  }
  int tamanhoLista(){
    if(Vazia()){
      return 0;
    }
    No* i = primeiro;
    int tamanho =0;
    do{
      i=i->getProx();
      tamanho++;
    }while(i);
    return tamanho;
  }

    void ExportarDados(){
      No* bd = primeiro;  
      saida.open("bd.txt",ios::out);
      for(int i=0;i<tamanhoLista();i++){
      saida<<bd->getValor()<<endl;
      bd=bd->getProx();
      }
      saida.close();
    } 
    void Impressão(){
      No* bd = primeiro;  
      for(int i=0;i<tamanhoLista();i++){
      bd->getValorO();
      cout<<"Conjunto "<<i+1<<"\nMontante: R$"<<(bd->getValorO()).getMontante()<<"\nPeriodo: "<<(bd->getValorO()).getPeriodo()<<" anos\nJuros anuais: "<<(bd->getValorO()).getJurosAN()<<"\nValor do montante ao final do Periodo por:"<<"\nJuros simples: "<<(bd->getValorO()).MontanteFinalJS()<<"\nJuros compostos: "<<(bd->getValorO()).MontanteFinalJC()<<"\nConversão de juros anuais para mensais: "<<(bd->getValorO()).ConversaoJanoJmes()<<endl;
      cout<<"-------------------"<<endl;
     
      bd=bd->getProx();
      }
    } 
};


int main() {
  ifstream entrada;
  char resp1,resp2='S';
  int qntG,i=0;
  float aux;
  ListaEncadeada lista;
  ListaEncadeada listaS;

  while(resp2=='S' || resp2 == 's'){
    cout<<"Deseja gravar ou ler no banco de dados? Gravar [g] / Ler [l]"<<endl;
    cin>>resp1;
    if(resp1=='g'){
      cout<<"Quantos elementos deseja gravar?"<<endl;
      cin>>qntG;
      cout<<"Digite o Montante,Periodo e Juros anuais respectivamente"<<endl;
      for(int i=0; i<qntG*3;i++){
        cin>>aux;
        lista.NovoElemento(aux);
      }
      cout<<"Dados registrados com sucesso"<<endl;
      lista.ExportarDados();
    }else if (resp1=='l'){
      tInvestimento inv;
      i=0;
      entrada.open("bd.txt",ios::in);
      while(!entrada.eof()){
        i++;
        if(i==4){
          i=1;
          listaS.NovoElemento(inv);
        }
        entrada>>aux;
        if(i==1){
        inv.setMontante(aux);
        }else if(i==2){
        inv.setPeriodo(aux);
        }else{
        inv.setJurosAN(aux);
        }
      }
      entrada.close();
      listaS.Impressão();
    }

    cout<<"Deseja continuar no programa? Sim[S] / Não[N]"<<endl;
    cin>>resp2;
  }
}