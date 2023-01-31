#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c) {
		cout << 10000 + a * 1000 << '\n';
	}
	else if (a != b && b != c && c != a) {
		int max_ = max(a, b);
		max_ = max(max_, c);
		cout << max_ * 100 << '\n';
	}
	else if( a == b && b != c) {
		cout << 1000 + a * 100 << '\n';
	}
	else if (b == c && a != b) {
		cout << 1000 + b * 100 << '\n';
	}
	else if (c == a && c != b) {
		cout << 1000 + c * 100 << '\n';
	}

	return 0;
} 
