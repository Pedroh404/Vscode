#include<iostream>
#include<map>
#include<vector>

using namespace std;


class Fatura{
public:
char tipo;
double valor;
double codigo;
vector<double> valorr = {0};
vector<long long int> codic;
vector<char> tip;
map<char,int> status;
int t = 0;

void imprimir(){

cout << tip[t] << " " << valorr[t] << " "<< codic[t];

}
double getValor(){
double y = 0;
y = valor;
return y;
}
char getTipo(){
char l = 0;
l = tipo;
return l;
}

};


class Colecao{
public:

Fatura *Fa = new Fatura();
int j = 0;
int quantp = 0;
int quantb = 0;
int quantg = 0;

void adicionar(){

cin >> Fa->tipo;
cin >> Fa->valor;
cin >> Fa->codigo;
Fa->status.insert(pair<char,int>('p',0));
Fa->status.insert(pair<char,int>('b',0));
Fa->status.insert(pair<char,int>('g',0));

if (Fa->getValor() > Fa->valorr.back()){

    Fa->valorr.push_back(Fa->getValor());
     Fa->codic.push_back(Fa->codigo);
      Fa->tip.push_back(Fa->getTipo());
      
      if(Fa->valorr[0]== 0){
        Fa->valorr.erase(Fa->valorr.begin());
    }
    

}
if (Fa->getValor()< Fa->valorr.front()){

       Fa->valorr.insert(Fa->valorr.begin(), Fa->getValor());
        Fa->tip.insert(Fa->tip.begin(), Fa->getTipo());
         Fa->codic.insert(Fa->codic.begin(), Fa->codigo);
}


for (int i = 0; i < Fa->valorr.size(); i++){

    if (Fa->getValor()> Fa->valorr[i] && Fa->getValor()< Fa->valorr[i+1]){
            j = i + 1;
         Fa->valorr.insert(Fa->valorr.begin() + j, Fa->getValor());
    Fa->codic.insert(Fa->codic.begin() + j, Fa->codigo);
    Fa->tip.insert(Fa->tip.begin() + j, Fa->getTipo());
    }
    

}
if (Fa->getTipo() == 'p' ){
    ++quantp;
    Fa->status.at('p') = quantp;
}
if (Fa->getTipo() == 'b' ){
    ++quantb;
    Fa->status.at('b') = quantb;
}
if (Fa->getTipo() == 'g' ){
    ++quantg;
    Fa->status.at('g') = quantg;
}

}

void proximo(){
  

    Fa->t = Fa->valorr.size() - 1;
    Fa->imprimir();
    cout << "\n";
 Fa->t = 0;
if (Fa->tip.back()== 'p' ){
    --quantp;
    Fa->status.at('p') = quantp;
}
if (Fa->tip.back() == 'b' ){
    --quantb;
    Fa->status.at('b') = quantb;
}
if (Fa->tip.back() == 'g' ){
    --quantg;
    Fa->status.at('g') = quantg;
}
Fa->valorr.pop_back();
Fa->codic.pop_back();
Fa->tip.pop_back();


}
void imprimirr(){

for(Fa->t = 0; Fa->t < Fa->valorr.size(); ++Fa->t ){
    Fa->imprimir();
   cout <<"\n";
}
Fa->t = 0;


}
void statuss(){
Fa->status.insert(pair<char,int>('p',0));
Fa->status.insert(pair<char,int>('b',0));
Fa->status.insert(pair<char,int>('g',0));    
    
for (auto it = Fa->status.begin();it!=Fa->status.end(); it++){
    cout<< it->first << " "<< it->second;
    cout << "\n";

}


}


};


int main(){

Colecao * cl = new Colecao();
char u;
int h = 0;
 
for(int i = 0; i < 10000; i++){
 cin>>u;
        
    
    if (u =='f'){
        cl->adicionar();}
    
    if  (u == 'r'){
        if (cl->Fa->valorr[0] != 0){
      
        
        cl ->proximo();}
        if (cl->Fa-> valorr[0] == 0){
            cout << "";
        }
        
    }
    
    
    if (u == 'p'){
        
        if (cl->Fa->valorr[0] != 0){
        cl->imprimirr();}
        
        
        }
        
    }
    
    if(u == 's'){
        cl->statuss();}
    
     if(u == 'e'){
        break;}
    
  
    }
    
    




return 0;
}