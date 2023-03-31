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
    int answer = 0;
    while(true) {
        int a; cin >> a;
        if (a == -1) {
            cout << answer << '\n';
            return 0;
        }
        answer += a;
    }
}