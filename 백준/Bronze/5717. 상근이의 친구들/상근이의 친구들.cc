#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a = -1;
	int b = -1;
	while (true) {
		cin >> a >> b;
		if (a + b == 0) break;
		cout << a + b << '\n';
	}
}