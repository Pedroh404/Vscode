#include <iostream>
#include <list>
#include "produto.hpp"
#include "venda.hpp"

using namespace std;

class Venda : public Pedido{
    private:
        list<Pedido*> _pedidos;
        list<Pedido*> :: iterator it;

    public:
        void adicionaPedido(Pedido* p){

        }

        void imprimeRelatorio(){
            
        }
};      
