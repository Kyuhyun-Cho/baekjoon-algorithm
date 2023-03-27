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

    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c && c == 60) {
        cout << "Equilateral" << '\n';
    }
    else if (a+b+c == 180 && (a==b || b==c || c==a)) {
        cout << "Isosceles" << '\n';
    }
    else if (a+b+c == 180) {
        cout << "Scalene" << '\n';
    }
    else {
        cout << "Error" << '\n';
    }
}