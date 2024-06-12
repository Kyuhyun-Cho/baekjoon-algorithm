#include <iostream>
#include <vector>

using namespace std;

unsigned long long dp[81];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int n; cin >> n;

    dp[1] = 4;
    dp[2] = 6;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << '\n';
}