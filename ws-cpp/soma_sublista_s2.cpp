/*
O objetivo desta função é mostrar quantas sublistas resultam em s
*/
/*
#include <iostream>

using namespace std;

int soma_sublista_bt(int* a, int tam, int soma) {
    int r1, r2 = 0;
    if (soma == 0) 
        return 1;
    if (soma < 0 || tam == 0)
        return 0;

    r1 = soma_sublista_bt(a, tam - 1, soma - a[tam - 1]);

    r2 = r1 + soma_sublista_bt(a, tam - 1, soma);

    return r2;
}

int main() {
    int* a, n, s, i; cin >> n >> s;
    a = new int[n];
    for (i = 0; i < n; ++i) 
        cin >> a[i];
    cout << soma_sublista_bt(a, n, s);
    delete a;
    return 0;
}
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>

using namespace std;

int contarSublistas(const vector<int>& arr, int s) {
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += arr[j];
            if (current_sum == s) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    auto inicio = chrono::high_resolution_clock::now();
    // Casos de teste para n de 10 a 30
    for (int n = 10; n <= 30; ++n) {
        vector<int> arr(n);
        // Preenche o array com valores para o teste
        for (int i = 0; i < n; ++i) {
            arr[i] = (i % 5) + 1; // Array com valores repetidos
        }
        
        // Caso de teste 1: Soma que existe e tem múltiplas ocorrências
        int s1 = 3; 
        cout << "Caso de teste com n=" << n << ", s=" << s1 << ": ";
        cout << contarSublistas(arr, s1) << endl;

        // Caso de teste 2: Soma que não existe
        int s2 = 100;
        cout << "Caso de teste com n=" << n << ", s=" << s2 << ": ";
        cout << contarSublistas(arr, s2) << endl;
    }
    auto fim = chrono::high_resolution_clock::now();
    auto duracao = chrono::duration_cast<chrono::microseconds>(fim - inicio);
    cout << "Tempo de processamento: " << duracao.count() << " microssegundos" << endl;
    return 0;
}