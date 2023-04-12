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

    int a, b, c, d, p;
    cin >> a >> b >> c >> d >> p;
    a *= p;
    if (p <= c) {
        cout << min(a, b);
    }
    else {
        b += (p-c) * d;
        cout << min(a, b);
    }
}