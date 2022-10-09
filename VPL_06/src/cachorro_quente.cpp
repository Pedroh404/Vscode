#include <iostream>
#include "produto.hpp"
#include "cachorro_quente.hpp"

using namespace std;

class CachorroQuente : protected Produto{
    private:
        int _num_salsichas;
        vector<string> _complementos;
        vector<string> :: iterator it;
        bool _prensado;

    public:
        CachorroQuente(int num_s, vector<string>& comp, bool prens, int qtd){
            _num_salsichas = num_s;
            _prensado = prens;
            _quantidade = qtd;
            for(it = _complementos.begin(); it < _complementos.end(); it++){
                *it = *comp;
                comp++;
            }
        }

        string descricao() override{
            cout << getQtd() << "X cachorro-quente ";
            if(_prensado){
                cout << "prensado ";
            }
            cout << "com " << _num_salsichas << " salsicha(s), ";
            for(it = _complementos.begin(); it < _complementos.end(); it++){
                if(it == _complementos.end() - 1){
                    cout << *it << "." << endl;
                } else{
                cout << *it << ", ";
                }

        }

        float calcPreco() override{
            _valor_unitario = 5 + (1.5 * _num_salsichas) + (1 * _complementos.size());
            if(_prensado == 1){
                _valor_unitario += 0.5;
            }
            return _valor_unitario * _quantidade;
        }
};