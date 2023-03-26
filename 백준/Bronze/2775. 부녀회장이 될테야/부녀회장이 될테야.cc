#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int t;
int k, n;
int arr[15][15];

int calc(int a, int b) {
    if(b == 1) {
        return 1;
    }
    if(a == 0) {
        return b;
    }
    return (calc(a-1, b) + calc(a, b-1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    for (int test_case = 0; test_case < t; test_case++) {
        cin >> k >> n;

        cout << calc(k, n) << '\n';
    }
}