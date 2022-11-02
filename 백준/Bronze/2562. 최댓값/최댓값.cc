#include <iostream>

using namespace std;

int main() {
    int arr[9];
    int index;
    int max = -1;
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 9; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i + 1;
        }
    }
    
    cout << max << '\n' << index << '\n';

    return 0;
}