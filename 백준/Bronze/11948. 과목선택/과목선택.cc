#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr[4];
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

	int arr_[2];
	cin >> arr_[0] >> arr_[1];

	sort(arr, arr+4);
	sort(arr_, arr_+2);

	cout << arr[3] + arr[2] + arr[1] + arr_[1];
}