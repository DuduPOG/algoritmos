#include <iostream>

using namespace std;

int troco(int m, int v){
    if (v == 0){
        return 0;
    }
    if (v < 0){
        return 9987847;
    }
    int menor_troco = 1 + min({troco(m, v - m[0]), troco(m, v - m[1]), troco(m, v - m[2])});
    return menor_troco;
}

int main(){

    int qtd, valor; cin >> qtd >> valor;
    int moedas[qtd];
    for (int i = 0; i < qtd; ++i){
        cin >> moedas[i];
    }
    cout << troco(moedas, valor) << endl;
    
    return 0;
}