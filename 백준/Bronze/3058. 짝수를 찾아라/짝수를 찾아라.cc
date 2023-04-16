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

    int t; cin >> t;
    while(t--) {
        int sum = 0;
        int min = 101;
        for (int i = 0; i < 7; i++) {
            int num; cin >> num;
            if (num % 2 == 0) {
                sum += num;
                if (num < min) {
                    min = num;
                }
            }
        }
        cout << sum << ' ' << min << '\n';
    }

    
}