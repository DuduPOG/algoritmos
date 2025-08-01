#include <iostream>

using namespace std;

bool soma_sublista_bt(int* a, int tam, int soma) {
    int r;
    if (soma == 0) return true; /* Aceita */
    if (soma < 0 || tam == 0) return false; /* Rejeita */
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