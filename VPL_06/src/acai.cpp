#include <iostream>
#include "produto.hpp"
#include "acai.hpp"

using namespace std;

class Acai : protected Produto{
    private :
        int _tamanho;
        vector<string> _complementos;
        vector<string> :: iterator it;

    public:
     
        Acai(int tam, vector<string>& comp, int qtd){
            _tamanho = tam;
            _quantidade = qtd;
            for(it = _complementos.begin(); it < comp.end(); it++){
                *it = *comp;
                comp++;                
            }
        }

        string descricao() override{
            cout << getQtd() << "X açaí de " << _tamanho << "ml, com ";
            for(it = _complementos.begin(); it < _complementos.end(); it++){
                if(it == _complementos.end() - 1){
                    cout << *it << "." << endl;
                } else{
                cout << *it << ", ";
                }
            }
        }

        float calcPreco() override{
            _valor_unitario = (0.02 * _tamanho) + (2 * _complementos.size());
            return _quantidade * _valor_unitario;
        }


};