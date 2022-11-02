#include <iostream>

using namespace std;

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
        arr[i] = arr[i] % 42;
    }

    int answer[42] = {0, };
    for (int i = 0; i < 10; i++) {
        answer[arr[i]] += 1;
    }

    int cnt = 0;
    for (int i = 0; i < 42; i++) {
        if (answer[i] != 0) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}