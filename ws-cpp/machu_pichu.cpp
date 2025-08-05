#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int machu_pichu(int matriz[20][20], int linha, int coluna, int l, int c) {

    if (l == 0) {
        return matriz[l][c];
    }

    if (l < 0 || l > linha - 1 || c < 0 || c > coluna - 1) {
        return 2000000;
    }

    matriz[l][c] = 9;

    int menor = matriz[l][c] +
              min({machu_pichu(matriz, linha, coluna, l - 1, c),
              machu_pichu(matriz, linha, coluna, l - 1, c - 1),
              machu_pichu(matriz, linha, coluna, l - 1, c + 1)});

    matriz[l][c] = 0;
    
    return menor;
}

int main() {

    int matriz_g[20][20], linha, coluna; cin >> linha >> coluna;

    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna; ++j) {
            cin >> matriz_g[i][j];
        }
    }

    cout << machu_pichu(matriz_g, linha, coluna, linha - 1, 0) << endl;

    return 0;
}