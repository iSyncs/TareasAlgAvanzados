#include <iostream>
#include <vector>
#include <string>

using namespace std;

// construye dp
// complejidad: o(n*m)
vector<vector<int>> construirDP(const string& A, const string& B) {
    int n = A.size();
    int m = B.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp;
}

// reconstruye lcs
// complejidad: o(n+m)
string reconstruirLCS(const string& A, const string& B, vector<vector<int>>& dp) {
    int i = A.size();
    int j = B.size();

    string lcs = "";

    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs = A[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string A, B;

    cout << "A: ";
    cin >> A;

    cout << "B: ";
    cin >> B;

    vector<vector<int>> dp = construirDP(A, B);
    string lcs = reconstruirLCS(A, B, dp);

    cout << "LCS = \"" << lcs << "\"" << endl;
    cout << "Longitud = " << lcs.length() << endl;

    return 0;
}