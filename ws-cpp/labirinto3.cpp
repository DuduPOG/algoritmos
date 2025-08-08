/*
O objetivo desta função é encontrar o menor caminho mostrando a quantidade mínima de células percorridas
*/

#include <iostream>
#include <climits>

using namespace std;

int labirinto_bt(int labirinto[20][20], int linha, int coluna, int l, int c) {
    if (l < 0 || c < 0 || l >= linha || c >= coluna || labirinto[l][c] != 0)
        return INT_MAX;
    if (l == linha - 1 && c == coluna - 1)
        return 1;

    labirinto[l][c] = 9;

    int min_path = INT_MAX;

    min_path = min(min_path, labirinto_bt(labirinto, linha, coluna, l+1, c));
    min_path = min(min_path, labirinto_bt(labirinto, linha, coluna, l, c+1));
    min_path = min(min_path, labirinto_bt(labirinto, linha, coluna, l, c-1));
    min_path = min(min_path, labirinto_bt(labirinto, linha, coluna, l-1, c));

    labirinto[l][c] = 0;

    if (min_path == INT_MAX)
        return INT_MAX;
    return min_path + 1;
}

int main() {
    int linha, coluna, labirinto[20][20];
    cin >> linha >> coluna;

    for (int i = 0; i < linha; ++i)
        for (int j = 0; j < coluna; ++j)
            cin >> labirinto[i][j];

    int resultado = labirinto_bt(labirinto, linha, coluna, 0, 0);
    cout << resultado << endl;
}