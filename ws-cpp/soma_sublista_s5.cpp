/*
O objetivo desta função é encontrar se existe alguma sublista de uma dada que resulta no número s
e retorna a que tenha a maior quantidade de elementos
*/
/*
#include <iostream>
#include <vector>

using namespace std;

void soma_sublista_bt(int* a, int tam, int soma, vector<int>& atual, vector<int>& maior) {
    if (soma == 0) {
        if (maior.empty() || atual.size() > maior.size())
            maior = atual;
        return;
    }
    if (soma < 0 || tam == 0)
        return;

    atual.push_back(a[tam - 1]);
    soma_sublista_bt(a, tam - 1, soma - a[tam - 1], atual, maior);
    atual.pop_back();

    soma_sublista_bt(a, tam - 1, soma, atual, maior);
}

int main() {
    int n, s;
    cin >> n >> s;
    int* a = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> atual, resultado;
    soma_sublista_bt(a, n, s, atual, resultado);

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
#include <numeric>
#include <chrono>

using namespace std;

void exibirMaiorSublista(const vector<int>& arr, int s) {
    int n = arr.size();
    vector<int> melhor_sublista;
    int maior_tamanho = 0;

    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += arr[j];
            if (current_sum == s) {
                int tamanho_atual = j - i + 1;
                if (tamanho_atual > maior_tamanho) {
                    maior_tamanho = tamanho_atual;
                    melhor_sublista.clear();
                    for (int k = i; k <= j; ++k) {
                        melhor_sublista.push_back(arr[k]);
                    }
                }
            }
        }
    }
    
    if (melhor_sublista.empty()) {
        cout << "0" << std::endl;
    } else {
        for (int elemento : melhor_sublista) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

int main() {
    auto inicio = chrono::high_resolution_clock::now();
    // Casos de teste para n de 10 a 30
    for (int n = 10; n <= 30; ++n) {
        vector<int> arr(n);
        // Preenche o array com valores para o teste
        for (int i = 0; i < n; ++i) {
            arr[i] = (i % 10) + 1; // Array com valores repetidos
        }
        
        // Caso de teste 1: Soma que tem sublistas de diferentes tamanhos
        int s1 = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10; 
        cout << "Caso de teste com n=" << n << ", s=" << s1 << ": ";
        exibirMaiorSublista(arr, s1);

        // Caso de teste 2: Soma que não existe
        int s2 = 1000;
        cout << "Caso de teste com n=" << n << ", s=" << s2 << ": ";
        exibirMaiorSublista(arr, s2);
    }
    auto fim = chrono::high_resolution_clock::now();
    auto duracao = chrono::duration_cast<chrono::microseconds>(fim - inicio);
    cout << "Tempo de processamento: " << duracao.count() << " microssegundos" << endl;
    return 0;
}