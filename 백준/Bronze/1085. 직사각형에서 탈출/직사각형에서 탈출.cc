#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int x1, x2, y1, y2;

	x1 = x - 0;
	x2 = w - x;
	y1 = y - 0;
	y2 = h - y;

	int arr[4] = {x1, x2, y1, y2};

	int min = 99999999;
	for (int i = 0; i < 4; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	cout << min << '\n';
}