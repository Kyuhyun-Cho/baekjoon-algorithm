#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int tmp;
    int arr[n] = {0, };
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr[i] = tmp;
    }

    int min = 1000001;
    int max = -1000001;

    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << min << " " << max << '\n';
}