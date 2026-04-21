#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Ordenamiento: O(n log n)
Recorrido monedas: O(n)
*/

int main() {

    int N;
    cin >> N;

    vector<int> coins(N);

    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    int P, Q;
    cin >> P;
    cin >> Q;

    int change = Q - P;

    if (change == 0) {
        cout << "No hay cambio por dar" << endl;
        return 0;
    }

    if (change < 0) {
        cout << "Falta dinero para pagar ese producto" << endl;
        return 0;
    }

    // ordenar monedas de mayor a menor
    sort(coins.begin(), coins.end(), greater<int>());

    vector<int> count(N);

    // algoritmo avaro
    for (int i = 0; i < N; i++) {

        count[i] = change / coins[i];
        change = change % coins[i];

    }

    // imprimir resultados
    for (int i = 0; i < N; i++) {
        cout << count[i] << " moneda(s) de " << coins[i] << endl;
    }

    return 0;
}