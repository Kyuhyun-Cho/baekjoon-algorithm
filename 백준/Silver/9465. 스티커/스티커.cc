#include <iostream>
#include <algorithm>

using namespace std;

int t, n; 
int dp[2][100001];
int arr[2][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    for (int T = 0; T < t; T++) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + arr[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + arr[1][i];
        }
        cout << max(dp[0][n], dp[1][n]) << '\n';
    }
}    