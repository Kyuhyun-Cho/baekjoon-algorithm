#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int weight, height;
	int arr[n][3] = { {0,0,0} };
	for (int i = 0; i < n; i++) {
		cin >> weight >> height;
		arr[i][0] = weight;
		arr[i][1] = height;

	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
				arr[i][2] += 1;
			}
			else if (arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1]) {
				arr[j][2] += 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i][2] + 1 << " ";
	}
	
}