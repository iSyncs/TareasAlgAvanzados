#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
Complejidad de zFunction:
Tiempo: O(n)
Espacio: O(n)
*/
vector<int> zFunction(const string& s) {
    int n = static_cast<int>(s.size());
    vector<int> z(n, 0);
    int left = 0;
    int right = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= right) {
            z[i] = min(right - i + 1, z[i - left]);
        }

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }

        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }

    return z;
}

/*
Complejidad de findPatternPositions:
Tiempo: O(n + m)
Espacio: O(n + m)
*/
vector<int> findPatternPositions(const string& text, const string& pattern) {
    vector<int> positions;

    if (pattern.empty() || text.empty() || pattern.size() > text.size()) {
        return positions;
    }

    string combined = pattern + "$" + text;
    vector<int> z = zFunction(combined);
    int patternLength = static_cast<int>(pattern.size());

    for (int i = patternLength + 1; i < static_cast<int>(combined.size()); ++i) {
        if (z[i] == patternLength) {
            positions.push_back(i - patternLength - 1);
        }
    }

    return positions;
}

/*
Complejidad de main:
Tiempo: O(n + m)
Espacio: O(n + m)
*/
int main() {
    string text;
    string pattern;

    cout << "Ingresa el texto: ";
    getline(cin, text);

    cout << "Ingresa el patron: ";
    getline(cin, pattern);

    vector<int> positions = findPatternPositions(text, pattern);

    cout << "\nPosiciones donde aparece el patron:\n";

    for (int i = 0; i < static_cast<int>(positions.size()); ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << positions[i];
    }

    cout << '\n';

    return 0;
}
