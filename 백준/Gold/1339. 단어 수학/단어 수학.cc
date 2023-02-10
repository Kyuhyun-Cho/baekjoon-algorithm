#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int n;
string arr[10];
int len[10];
int digit[26];
int answer;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;   
    for (int i = 0; i < n; i++) {
        cin >> arr[i];;
        len[i] = arr[i].length();
    }

    for (int i = 0; i < n; i++) {
        int idx = 1;
        for (int j = len[i]-1; j >= 0; j--) {
            digit[arr[i][j] - 'A'] += idx;
            idx *= 10;
        }
    }
    sort(digit, digit+26, cmp);
    
    for (int i = 0; i < 10; i++) {
        answer += digit[i] * (9 - i);
    }

    cout << answer << '\n';
}