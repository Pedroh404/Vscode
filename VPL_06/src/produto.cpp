#include <iostream>
#include <vector>
#include <string>
#include "produto.hpp"

using namespace std;

class Produto{
    protected:
        int _quantidade;
        float _valor_unitario;

    public:
        int getQtd(){
            return _quantidade;
        }

        float getValor(){
            return _valor_unitario;
        }
        
        virtual string descricao(){
            cout << getQtd() << "X ";
        }

        virtual float calcPreco(){
            return getValor();

        }
};