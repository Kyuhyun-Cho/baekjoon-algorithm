#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a1, a2, a3, a4;
	int b1, b2, b3, b4;
	cin >> a1 >> a2 >> a3 >> a4;
	cin >> b1 >> b2 >> b3 >> b4;

	int a = a1 + a2 + a3 + a4;
	int b = b1 + b2 + b3 + b4;

	if (a >= b) cout << a << '\n';
	else cout << b << '\n';
}