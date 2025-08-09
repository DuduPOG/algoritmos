#include "ordenacao.hpp"
#include <chrono>
#include <iostream>

using namespace std;

const int SELECAO = 1;
const int INSERCAO = 2;
const int MERGE = 3;

void print_usage() {
    cout << "Programa para ordenação de números ineiros.\n\n";
    cout << "\tUso: teste_ordenacao [Opção]\n";
    cout << "\n";
    cout << "Onde 'Opção' é uma das opções a seguir:\n\n";
    cout << "\t -s: ordenação por seleção (padrão).\n";
    cout << "\t -i: ordenação por inserção.\n";
    cout << "\t -m: ordenação por merge-sort.\n";
    cout << "\t -h: Mostra instruções de uso de programa.\n\n";
}

int define_metodo(int argc, char **argv) {
    int metodo = SELECAO;
    if (argc > 2) {
        cout << "*** Quantidade de parâmetros inválidos *** \n\n";
        print_usage();
        exit(1);
    }
    if (argc == 2) {
        if (argv[1][0] != '-') {
            print_usage();
            exit(0);
        } else if (argv[1][1] == 's') {
            metodo = SELECAO;
            cerr << "Método seleção usado para ordenação.\n";
        } else if (argv[1][1] == 'i') {
            metodo = INSERCAO;
            cerr << "Método inserção usado para ordenação.\n";
        } else if (argv[1][1] == 'm') {
            metodo = MERGE;
            cerr << "Método merge-sort usado para ordenação.\n";
        } else {
            print_usage();
            exit(2);
        }
    }
    return metodo;
}

void imprime_array(int a[], int n) {
    int i;
    if (n > 0) {
        cout << a[0];
        for (i = 1; i < n; ++i)
            cout << " " << a[i];
        cout << "\n";
    }
}

int main(int argc, char **argv) {
    int n, i, metodo = define_metodo(argc, argv);
    cin >> n;
    int a[n];
    for (i = 0; i < n; ++i)
        cin >> a[i];
    auto beg = chrono::high_resolution_clock::now();
    switch (metodo) {
    case SELECAO:
        selecao(a, n);
        break;
    case INSERCAO:
        insercao(a, n);
        break;
    case MERGE:
        merge_sort(a, n);
        break;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - beg);
    cerr << n << " Tempo de ordenação: " << duration.count() << " microsegundo(s)" << endl;
    if (not ordenado(a, n)) {
        cerr << "\033[0;31mErro:\033[0m Array não ordenado. Saindo...\n";
        exit(-1);
    }
    // imprime_array(a,n); // Imprime, na saída padrão o array ordenado.
    return 0;
}
