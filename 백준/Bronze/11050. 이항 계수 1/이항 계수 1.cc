#include <iostream>

using namespace std;

int factorial(int num) {
	int result = 1;
	for (int i = 1; i <= num; i++) {
		result *= i;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	cout <<  factorial(n)/ factorial(k) / factorial(n-k) << '\n';
}

