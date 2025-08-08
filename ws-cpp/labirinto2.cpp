/*
O objetivo desta função é mostrar a quantidade de caminhos possíveis até a saída
*/

#include <iostream>

using namespace std;

int labirinto_bt(int labirinto[20][20], int linha, int coluna, int l, int c){

    if (l == -1 || c == -1 || l == linha || c == coluna || labirinto[l][c] != 0)
        return 0;
    if (l == linha - 1 && c == coluna - 1)
        return 1;

    labirinto[l][c] = 9;    

    int ans =
        labirinto_bt(labirinto, linha, coluna, l+1, c) +
        labirinto_bt(labirinto, linha, coluna, l, c+1) +
        labirinto_bt(labirinto, linha, coluna, l, c-1) +
        labirinto_bt(labirinto, linha, coluna, l-1, c);

    labirinto[l][c] = 0;
    return ans;
}

int main() {
    int linha, coluna, labirinto[20][20]; cin >> linha >> coluna;

    for (int i=0 ; i<linha ; ++i)
        for (int j=0 ; j<coluna ; ++j)
            cin >> labirinto[i][j];

    cout << labirinto_bt(labirinto, linha, coluna, 0, 0);

    return 0;
}