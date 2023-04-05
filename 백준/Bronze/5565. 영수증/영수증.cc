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

    int a; cin >> a;
    for (int i = 0; i < 9; i++) {
        int b; cin >> b;
        a -= b;
    }
    cout << a << '\n';
}