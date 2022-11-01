#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int reverse_a = 0;
    int reverse_b = 0;

    reverse_a = reverse_a + (a % 10 * 100);
    a = a / 10;
    reverse_a = reverse_a + (a % 10 * 10);
    a = a / 10;
    reverse_a = reverse_a + (a % 10 * 1);

    reverse_b = reverse_b + (b % 10 * 100);
    b = b / 10;
    reverse_b = reverse_b + (b % 10 * 10);
    b = b / 10;
    reverse_b = reverse_b + (b % 10 * 1);

    if (reverse_a > reverse_b) {
        cout << reverse_a << '\n';
    }
    else {
        cout << reverse_b << '\n';
    }
}