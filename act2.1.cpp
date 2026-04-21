#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long BASE = 31;
const long long MOD = 1000000007;

/*
Complejidad de buildPowers:
Tiempo: O(n)
Espacio: O(n)
*/
vector<long long> buildPowers(int n) {
    vector<long long> powers(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
        powers[i] = (powers[i - 1] * BASE) % MOD;
    }

    return powers;
}

/*
Complejidad de buildPrefixHash:
Tiempo: O(n)
Espacio: O(n)
*/
vector<long long> buildPrefixHash(const string& text) {
    int n = static_cast<int>(text.size());
    vector<long long> prefixHash(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        long long value = static_cast<long long>(text[i]);
        prefixHash[i + 1] = (prefixHash[i] * BASE + value) % MOD;
    }

    return prefixHash;
}

/*
Complejidad de substringHash:
Tiempo: O(1)
Espacio: O(1)
*/
long long substringHash(
    const vector<long long>& prefixHash,
    const vector<long long>& powers,
    int left,
    int right
) {
    long long hashValue =
        prefixHash[right + 1] - (prefixHash[left] * powers[right - left + 1]) % MOD;

    if (hashValue < 0) {
        hashValue += MOD;
    }

    return hashValue;
}

/*
Complejidad de areEqualSubstrings:
Tiempo: O(1)
Espacio: O(1)
*/
bool areEqualSubstrings(
    const vector<long long>& prefixHash,
    const vector<long long>& powers,
    int l1,
    int r1,
    int l2,
    int r2
) {
    if ((r1 - l1) != (r2 - l2)) {
        return false;
    }

    long long hash1 = substringHash(prefixHash, powers, l1, r1);
    long long hash2 = substringHash(prefixHash, powers, l2, r2);

    return hash1 == hash2;
}

/*
Complejidad de main:
Tiempo: O(n)
Espacio: O(n)
*/
int main() {
    string text;
    int l1, r1, l2, r2;

    cout << "Ingresa el string: ";
    getline(cin, text);

    vector<long long> powers = buildPowers(static_cast<int>(text.size()));
    vector<long long> prefixHash = buildPrefixHash(text);

    cout << "Ingresa l1 y r1: ";
    cin >> l1 >> r1;

    cout << "Ingresa l2 y r2: ";
    cin >> l2 >> r2;

    if (areEqualSubstrings(prefixHash, powers, l1, r1, l2, r2)) {
        cout << "Los substrings son iguales\n";
    } else {
        cout << "Los substrings son diferentes\n";
    }

    return 0;
}
