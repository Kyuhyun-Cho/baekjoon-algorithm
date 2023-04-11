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

    int max = -1;
    int cnt = 0;
    for (int i = 0; i < 10; i++){
        int minus, plus;
        cin >> minus >> plus;
        cnt -= minus;
        cnt += plus;
        if (cnt > max) max = cnt;
    }
    cout << max << '\n';
}