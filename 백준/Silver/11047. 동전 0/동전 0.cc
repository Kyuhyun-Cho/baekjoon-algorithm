#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int tmp;
    int coin[n] = {0, };
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        coin[i] = tmp;
    }

    int answer = 0;
    for (int i = n-1; i >= 0; i--) {
        if (k / coin[i] > 0) {
            int count = k / coin[i];
            k = k - (coin[i] * count);
            answer += count;
        }
    }
    cout << answer << '\n';
}