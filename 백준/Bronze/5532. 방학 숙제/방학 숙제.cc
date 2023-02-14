#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	int date_1 = 0;
	int date_2 = 0;
	if (a % c > 0) {
		date_1 += a / c + 1;
	}
	else {
		date_1 += a / c;
	}

	if (b % d > 0) {
		date_2 += b / d + 1;
	}
	else {
		date_2 += b / d;
	}

	if (date_1 > date_2) {
		cout << l - date_1 << '\n';
	}
	else {
		cout << l - date_2 << '\n';
	}

}