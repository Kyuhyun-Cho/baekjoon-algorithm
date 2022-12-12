#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	int primeNum[b+1] = {0, };

	for (int i = 2; i <= b; i++) {
		primeNum[i] = i;
	}

	for (int i = 2; i <= sqrt(b); i++) {
		if (primeNum[i] == 0) continue;
		for (int j = i * i; j <= b; j += i) {
			primeNum[j] = 0;
		}
	}

	for (int i = a; i <= b; i++) {
		if (primeNum[i] != 0) {
			cout << primeNum[i] << '\n';
		}
	}
	
	return 0;
}