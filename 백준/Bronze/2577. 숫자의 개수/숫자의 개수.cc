#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int total = a * b * c;
    string str_total = to_string(total);
    int arr[10] = {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0};

    for (int i = 0; i < str_total.length(); i++) {
        int index = total % 10;
        arr[index] = arr[index] + 1;
        total = total / 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << '\n';
    }
}