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

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min(a+d, b+c) << '\n';
}