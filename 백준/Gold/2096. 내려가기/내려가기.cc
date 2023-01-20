#include <iostream>

using namespace std;

int n;
int arr[100001][3];
int max_dp[2][3];
int min_dp[2][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + arr[i][0];
        max_dp[1][1] = max(max_dp[0][0], max(max_dp[0][1], max_dp[0][2])) + arr[i][1];
        max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + arr[i][2];

        max_dp[0][0] = max_dp[1][0];
        max_dp[0][1] = max_dp[1][1];
        max_dp[0][2] = max_dp[1][2];
    }
    
    for (int i = 1; i <= n; i++) {
        min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + arr[i][0];
        min_dp[1][1] = min(min_dp[0][0], min(min_dp[0][1], min_dp[0][2])) + arr[i][1];
        min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + arr[i][2];

        min_dp[0][0] = min_dp[1][0];
        min_dp[0][1] = min_dp[1][1];
        min_dp[0][2] = min_dp[1][2];
    }
    
    cout << max(max_dp[0][0], max(max_dp[0][1], max_dp[0][2])) << ' ';
    cout << min(min_dp[0][0], min(min_dp[0][1], min_dp[0][2])) << '\n';
}