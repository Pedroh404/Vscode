#include <iostream>
#include <list>
#include "acai.hpp"
#include "cachorro_quente.hpp"
#include "pizza.hpp"
#include "pedido.hpp"
#include "produto.hpp"

using namespace std;

class Pedido : public Produto{
    private:
        list<Produto*> _produtos;
        list<Produto*> :: iterator it;
        string _endereco;

    public:
        void adicionaProduto(Produto *p){

        }

        float calculaTotal(){

        }

        string resumo(){
            
        }
        
        void setEndereco(string endereco){
            _endereco = endereco;
        }
};