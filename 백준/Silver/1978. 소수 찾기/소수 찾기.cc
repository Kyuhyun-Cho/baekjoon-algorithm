#include <iostream>

using namespace std;

int main() {
    int n;
    int cnt = 0;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            continue;
        }
        cnt++;
        for (int j = 2; j < arr[i]; j++) {
            if (arr[i] % j == 0) {
                cnt--;
                break;
            }
        }
    }
    cout << cnt << '\n';
}