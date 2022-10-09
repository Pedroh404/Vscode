#include <iostream>
#include "produto.hpp"
#include "pizza.hpp"

using namespace std;

class Pizza : protected Produto{
    private:
        string _sabor;
        int _num_pedacos;
        bool _borda_recheada;

    public:
        Pizza(string sabor, int pedacos, bool borda, int qtd){
            _sabor = sabor;
            _num_pedacos = pedacos;
            _borda_recheada = borda;
            _quantidade = qtd;
        }

        string descricao() override{
            cout << getQtd() << "X pizza " << _sabor << ", " << _num_pedacos << " pedaços ";
            if(_borda_recheada){
                cout << "e borda recheada";
            } else{
                cout << "sem borda recheada";
            }

        }

        float calcPreco() override{
            _valor_unitario = (5 * _num_pedacos);
            if(_sabor.find("especial") == 1){
                _valor_unitario += 8;
            }
            if(_borda_recheada == 1){
                _valor_unitario += 10;
            }
            return _valor_unitario * _quantidade;
        }
};