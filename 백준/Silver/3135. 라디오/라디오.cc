#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int n;
	cin >> n;

	int n_hz[n]; 
	for (int i = 0; i < n; i++) {
		cin >> n_hz[i];
	}

	int min = abs(a-b);
	
	int click;
	for (int i = 0; i < n; i++) {
		click = 1;
		click += abs(n_hz[i] - b);
		if (click < min) {
			min = click;
		}
	}

	cout << min << '\n';
}