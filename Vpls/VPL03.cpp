#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Fatura{
    private:
        string _codigo;
        char _tipo;
        double _valor;

    public:
        Fatura(double x, char c, string s){
            _valor = x;
            _tipo = c;
            swap (_codigo, s);
        }

        double getValor(){
            return _valor;
        }

        char getTipo(){
            return _tipo;
        }

        string getCodigo(){
            return _codigo;
        }

        void imprimir(){
            cout << getTipo() << " " << getValor() << " " << getCodigo() << endl;
        }
};

class Colecao{
    private:
        stack <double> _value;
        Fatura *_fudeu;

    public:

    void setStack(double x){
        _value.push(x);
        stack<double> tmpStack = sortStack(_value);
    }

    // This function return the sorted stack
    stack<double> sortStack(stack<double> &input){
        stack<double> tmpStack;
 
        while (!input.empty()){
            // pop out the first element
            double tmp = input.top();
            input.pop();
 
            // while temporary stack is not empty and top
            // of stack is greater than temp
        while (!tmpStack.empty() && tmpStack.top() > tmp){
            // pop from temporary stack and push
            // it to the input stack
            input.push(tmpStack.top());
            tmpStack.pop();
        }
 
        // push temp in temporary of stack
        tmpStack.push(tmp);
    }
 
    return tmpStack;
}

    void adicionar(){
        double v;
        char t;
        string c;

        cin >> t >> v >> c;

        setStack(v);
        
        _fudeu = new Fatura(v, t, c);
    }

    void proximo(){
        
        _value.pop();
        
    }

    void print(){
        int t;
        for(t = 0; t < _value.size(); t++){
            _fudeu -> imprimir();
        }
    }
};

int main(){
    Colecao *p = new Colecao[1000];
    char c;
    int i = 1;

    while(i){
        cin >> c;
        switch(c){
            case 'f' : {
                p -> adicionar();
            }
            break;

            case 'r' : {
                p -> proximo();
            }
            break;

            case 'p' : {

            }
            break;

            case 's' : {

            }
            break;

            case 'e' : {
                i = 0;
            }
            break;
        }
    }
return 0;
}