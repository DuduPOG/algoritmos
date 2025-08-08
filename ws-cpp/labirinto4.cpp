/*
O objetivo desta função é encontrar se existe saída no labirinto, não importa a célula da saída
*/

#include <iostream>

using namespace std;

bool labirinto_bt(int labirinto[20][20], int linha, int coluna, int li, int ci, int lf, int cf){

    if (li < 0 || ci < 0 || li == linha || ci == coluna || labirinto[li][ci] != 0)
        return false;
    if (li == lf && ci == cf)
        return true;

    labirinto[li][ci] = 9;    

    bool ans =
        labirinto_bt(labirinto, linha, coluna, li + 1, ci, lf, cf) ||
        labirinto_bt(labirinto, linha, coluna, li, ci + 1, lf, cf) ||
        labirinto_bt(labirinto, linha, coluna, li, ci - 1, lf, cf) ||
        labirinto_bt(labirinto, linha, coluna, li - 1, ci, lf, cf);

    labirinto[li][ci] = 0;
    return ans;
}

int main() {
    int linha, coluna, li, ci, lf, cf, labirinto[20][20];
    cin >> linha >> coluna;
    cin >> li >> ci;
    cin >> lf >> cf;

    for (int i=0 ; i<linha ; ++i)
        for (int j=0 ; j<coluna ; ++j)
            cin >> labirinto[i][j];

    cout << labirinto_bt(labirinto, linha, coluna, li, ci, lf, cf);

    return 0;
}