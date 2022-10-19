#include <iostream>
#include <list>
#include <string>
#include <map>
#include <vector>

using namespace std;


class Fatura{
    public:
        char _tipo;
        double _valor;
        long long int _codigo;

        vector<double> _value = {0};
        vector<long long int> _code;
        vector<char> _type;

        int x = 0;

        void imprimir(){
            cout << _type[x] << " " << _value[x] << " " << _code[x] << endl;
        }

        double getValor(){
            return _valor;
        }

        char getTipo(){
            return _tipo;
        }

        char getCodigo(){
            return _codigo;
        }
};

class Colecao{
    public:

        Fatura *fudeu = new Fatura();
        map<char, int> stat;

        int y = 0, B = 0, P = 0, G = 0;

        void adicionar(){
            cin >> fudeu -> _tipo >> fudeu -> _valor >> fudeu -> _codigo;

            stat.insert(pair <char, int> ('p', 0));
            stat.insert(pair <char, int> ('g', 0));
            stat.insert(pair <char, int> ('b', 0));

            if(fudeu -> getValor() > fudeu -> _value.back()){
                fudeu -> _value.push_back(fudeu -> getValor());
                fudeu -> _code.push_back(fudeu -> _codigo); 
                fudeu -> _type.push_back(fudeu -> getTipo());

                if(fudeu -> _value[0] == 0){
                    fudeu -> _value.erase(fudeu -> _value.begin());
                }
            }

            if(fudeu -> getValor() < fudeu -> _value.front()){
                fudeu -> _value.insert(fudeu -> _value.begin(), fudeu -> getValor()); 
                fudeu -> _code.insert(fudeu -> _code.begin(), fudeu -> _codigo); 
                fudeu -> _type.insert(fudeu -> _type.begin(), fudeu -> getTipo());
            }

            for(int i = 0; i < fudeu -> _value.size(); i++){

                if(fudeu -> getValor() > fudeu -> _value[i] && fudeu -> getValor() < fudeu -> _value[i + 1]){
                    y = i + 1;
                    fudeu -> _value.insert(fudeu -> _value.begin() + y, fudeu -> getValor()); 
                    fudeu -> _code.insert(fudeu -> _code.begin() + y, fudeu -> _codigo); 
                    fudeu -> _type.insert(fudeu -> _type.begin() + y, fudeu -> getTipo());
                }
            }

            if(fudeu -> getTipo() == 'p'){
                ++P;
                stat.at('p') = P;
            }

            if(fudeu -> getTipo() == 'g'){
                ++G;
                stat.at('g') = G;
            }

            if(fudeu -> getTipo() == 'b'){
                ++B;
                stat.at('b') = B;
            }
        }

        void proximo(){
            if( fudeu -> _value[0] != 0){
                fudeu -> x = fudeu -> _value.size() - 1;
                fudeu -> imprimir();
                fudeu -> x = 0;

                if(fudeu -> _type.back() == 'p'){
                 --P;
                    stat.at('p') = P;
                }

                if(fudeu -> _type.back() == 'g'){
                    --G;
                    stat.at('g') = G;
                }

                if(fudeu -> _type.back() == 'b'){
                    --B;
                    stat.at('b') = B;
                }   

                fudeu -> _value.pop_back(); 
                fudeu ->_code.pop_back(); 
                fudeu ->_type.pop_back();
            } else{
            cout << "";
            }
        }

        void print(){
            if(fudeu -> _value[0] != 0){
                for(fudeu -> x = 0; fudeu -> x < fudeu -> _value.size(); ++fudeu -> x){
                    fudeu -> imprimir();
                }
                fudeu -> x = 0;
            } else{
                cout << "";
            }
        }

        void status(){
            for(auto it = stat.begin(); it!= stat.end(); it++){
                cout << it -> first << " " << it -> second << endl;
            }

            if(auto it = stat.begin() == stat.end()){
                cout << 'b' << " " << 0 << endl;
                cout << 'g' << " " << 0 << endl;
                cout << 'p' << " " << 0 << endl;
            }
        }
};

int main(){
    Colecao *pedro = new Colecao();
    char c;
    int z = 0, loop = 1;

    while(loop){
        cin >> c;
        switch(c){
            case 'f':{
                pedro -> adicionar();
            }
            break;

            case 'r':{
                pedro -> proximo();
            }
            break;

            case 'p':{
                pedro -> print();
            }
            break;

            case 's':{
                pedro -> status();
            }
            break;

            case 'e':{
                loop = 0;
            }
            break;
        }
    }
}