#include <iostream>
#include <string>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;

    for (int t = 0; t < testCase; t++) {
        int n;
        cin >> n;

        int dp[11] = {0, };
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        cout << dp[n] << '\n';
    }
}
