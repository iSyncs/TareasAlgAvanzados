#include <iostream>
#include <vector>
#include <string>

using namespace std;

// construye dp
// complejidad: o(n^2)
vector<vector<int>> construirDP(const string& s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                if (len == 2) dp[i][j] = 2;
                else dp[i][j] = 2 + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp;
}

// reconstruye lps
// complejidad: o(n)
string reconstruirLPS(const string& s, vector<vector<int>>& dp) {
    int i = 0;
    int j = s.size() - 1;

    string left = "";
    string right = "";

    while (i <= j) {
        if (i == j) {
            left += s[i];
            break;
        }

        if (s[i] == s[j]) {
            left += s[i];
            right = s[j] + right;
            i++;
            j--;
        } else if (dp[i + 1][j] >= dp[i][j - 1]) {
            i++;
        } else {
            j--;
        }
    }

    return left + right;
}

int main() {
    string s;

    cout << "S: ";
    cin >> s;

    vector<vector<int>> dp = construirDP(s);
    string lps = reconstruirLPS(s, dp);

    cout << "Longitud = " << dp[0][s.size() - 1] << endl;
    cout << "LPS posible = \"" << lps << "\"" << endl;

    return 0;
}