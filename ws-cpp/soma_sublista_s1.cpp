/*
O objetivo desta função é encontrar se existe alguma sublista de uma dada que resulta no número s
*/

/*
#include <iostream>

using namespace std;

bool soma_sublista_bt(int* a, int tam, int soma) {
    int r;
    if (soma == 0) 
        return true;
    if (soma < 0 || tam == 0) 
        return false;

    r = soma_sublista_bt(a, tam - 1, soma - a[tam - 1]);

    r = r || soma_sublista_bt(a, tam - 1, soma);
    return r;
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

bool existeSublista(const vector<int>& arr, int s) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += arr[j];
            if (current_sum == s) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    auto inicio = chrono::high_resolution_clock::now();
    // Casos de teste para n de 10 a 30
    for (int n = 10; n <= 30; ++n) {
        vector<int> arr(n);
        // Preenche o array com valores para o teste
        for (int i = 0; i < n; ++i) {
            arr[i] = (i + 1) * 2;
        }
        
        // Caso de teste 1: Soma que existe
        int s1 = 2 * (n / 2) + 2 * (n / 2 + 1); // Exemplo de soma de 2 elementos
        cout << "Caso de teste com n=" << n << ", s=" << s1 << ": ";
        if (existeSublista(arr, s1)) {
            cout << "1 (Existe)" << endl;
        } else {
            cout << "0 (Não existe)" << endl;
        }

        // Caso de teste 2: Soma que não existe
        int s2 = 1; 
        cout << "Caso de teste com n=" << n << ", s=" << s2 << ": ";
        if (existeSublista(arr, s2)) {
            cout << "1 (Existe)" << endl;
        } else {
            cout << "0 (Nao existe)" << endl;
        }
    }
    auto fim = chrono::high_resolution_clock::now();
    auto duracao = chrono::duration_cast<chrono::microseconds>(fim - inicio);
    cout << "Tempo de processamento: " << duracao.count() << " microssegundos" << endl;
    return 0;
}
