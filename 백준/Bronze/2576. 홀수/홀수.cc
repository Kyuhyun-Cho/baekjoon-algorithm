#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sum = 0;
    int min = 101;
    for (int i = 0; i < 7; i++) {
        int num;
        cin >> num;
        if (num % 2 == 1) {
            sum += num;
            if (num < min) {
                min = num;
            }
        }
    }
    if (sum == 0) {
        cout << -1 << '\n';
        return 0;
    }
    cout << sum << '\n' << min <<'\n';
}