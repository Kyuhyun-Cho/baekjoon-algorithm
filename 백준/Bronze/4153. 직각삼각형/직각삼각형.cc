#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	
	while(true) {
		int a, b, c;
		cin >> a >> b >> c;

		if ( (a + b + c) == 0 ) {
			break;
		}

		int arr[3] = {a, b, c};
		int max = -1;
		for (int i = 0; i < 3; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}

		if (pow(max,2) == pow(arr[0],2) + pow(arr[1],2) || pow(max,2) == pow(arr[1],2) + pow(arr[2],2) || pow(max,2) == pow(arr[0],2) + pow(arr[2],2)) {
			cout << "right" << '\n';
		}
		else {
			cout << "wrong" << '\n';
		}
	}
	
}