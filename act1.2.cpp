#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

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
        cout << "Falta dinero para pagar" << endl;
        return 0;
    }

    sort(coins.begin(), coins.end());

    vector<int> dp(change + 1, INT_MAX);
    vector<int> used(change + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= change; i++) {
        for (int j = 0; j < N; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                    used[i] = j;
                }
            }
        }
    }

    if (dp[change] == INT_MAX) {
        cout << "No es posible dar cambio con las monedas dadas" << endl;
        return 0;
    }

    vector<int> count(N, 0);
    int current = change;

    while (current > 0) {
        int idx = used[current];
        count[idx]++;
        current -= coins[idx];
    }

    for (int i = N - 1; i >= 0; i--) {
        cout << count[i] << " moneda(s) de " << coins[i] << endl;
    }

    return 0;
}