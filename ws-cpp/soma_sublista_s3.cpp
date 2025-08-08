/*
O objetivo desta função é encontrar se existe alguma sublista de uma dada que resulta no número s
e retorná-la
*/
/*
#include <iostream>
#include <vector>

using namespace std;

vector<int> soma_sublista_bt(int* a, int tam, int soma, vector<int>& atual) {
    if (soma == 0) {
        return atual;
    }
    if (soma < 0 || tam == 0)
        return {};

    atual.push_back(a[tam - 1]);
    vector<int> res = soma_sublista_bt(a, tam - 1, soma - a[tam - 1], atual);
    if (!res.empty())
        return res;
    atual.pop_back();

    res = soma_sublista_bt(a, tam - 1, soma, atual);
    if (!res.empty())
        return res;

    return {};
}

int main() {
    int n, s;
    cin >> n >> s;
    int* a = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> atual;
    vector<int> resultado = soma_sublista_bt(a, n, s, atual);

    if (!resultado.empty()) {
        for (int x : resultado)
            cout << x << " ";
        cout << endl;
    } else {
        cout << 0 << endl;
    }

    delete[] a;
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void exibirSublista(const vector<int>& arr, int s) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += arr[j];
            if (current_sum == s) {
                for (int k = i; k <= j; ++k) {
                    cout << arr[k] << " ";
                }
                cout << endl;
                return;
            }
        }
    }
    cout << "0" << endl;
}

int main() {
    auto inicio = chrono::high_resolution_clock::now();
    // Casos de teste para n de 10 a 30
    for (int n = 10; n <= 30; ++n) {
        vector<int> arr(n);
        // Preenche o array com valores para o teste
        for (int i = 0; i < n; ++i) {
            arr[i] = (i + 1) * 3;
        }

        // Caso de teste 1: Soma que existe
        int s1 = 3 * (n / 2) + 3 * (n / 2 + 1);
        cout << "Caso de teste com n=" << n << ", s=" << s1 << ": ";
        exibirSublista(arr, s1);

        // Caso de teste 2: Soma que não existe
        int s2 = 1;
        cout << "Caso de teste com n=" << n << ", s=" << s2 << ": ";
        exibirSublista(arr, s2);
    }
    auto fim = chrono::high_resolution_clock::now();
    auto duracao = chrono::duration_cast<chrono::microseconds>(fim - inicio);
    cout << "Tempo de processamento: " << duracao.count() << " microssegundos" << endl;
    return 0;
}

