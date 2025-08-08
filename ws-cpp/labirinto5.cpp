/*
O objetivo desta função é encontrar o menor caminho até uma saída qualquer levando em conta
o somatório, incluindo valores de célula negativos com o ponto de início e fim sendo o valor 0
*/

#include <iostream>
#include <climits>

using namespace std;

int labirinto_bt(int labirinto[20][20], int linha, int coluna, int li, int ci, int lf, int cf) {
    // Verifica limites e obstáculos
    if (li < 0 || ci < 0 || li >= linha || ci >= coluna || labirinto[li][ci] == 9)
        return INT_MAX;
    if (li == lf && ci == cf)
        return labirinto[li][ci];

    int valor_atual = labirinto[li][ci];

    labirinto[li][ci] = 9;

    int min_path = INT_MAX;
    min_path = min(min_path, labirinto_bt(labirinto, linha, coluna, li + 1, ci, lf, cf));
    min_path = min(min_path, labirinto_bt(labirinto, linha, coluna, li, ci + 1, lf, cf));
    min_path = min(min_path, labirinto_bt(labirinto, linha, coluna, li, ci - 1, lf, cf));
    min_path = min(min_path, labirinto_bt(labirinto, linha, coluna, li - 1, ci, lf, cf));

    labirinto[li][ci] = valor_atual;

    if (min_path == INT_MAX)
        return INT_MAX;
    return valor_atual + min_path;
}

int main() {
    int linha, coluna, li, ci, lf, cf, labirinto[20][20];
    cin >> linha >> coluna;
    cin >> li >> ci;
    cin >> lf >> cf;

    for (int i = 0; i < linha; ++i)
        for (int j = 0; j < coluna; ++j)
            cin >> labirinto[i][j];

    cout << labirinto_bt(labirinto, linha, coluna, li, ci, lf, cf);
}