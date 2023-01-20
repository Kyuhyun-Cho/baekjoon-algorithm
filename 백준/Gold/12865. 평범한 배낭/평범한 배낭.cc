#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int w[101];
int v[101];     
int dp[101][100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (w[j] > i) {
                dp[j][i] = dp[j-1][i];
            }
            else {
                dp[j][i] = max(dp[j-1][i-w[j]] + v[j], dp[j-1][i]);
            }
        }
    }

    cout << dp[n][k] << '\n';
}