#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	long long sum = 0;
	long long XOR = 0;
	int first;
	int second;
	for(int i = 0; i < n; i++) {
		cin >> first;
		if(first == 1) {
			cin >> second;
			sum = sum + second;
			XOR = XOR ^ second;
		}
		else if(first == 2) {
			cin >> second;
			sum = sum - second;
			XOR = XOR ^ second;
		}
		else if(first == 3) {
			cout << sum << '\n';
		}
		else if(first == 4) {
			cout << XOR << '\n';
		}
	}
} 