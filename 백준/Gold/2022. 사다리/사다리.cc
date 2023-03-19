#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double x, y, c, w, h1, h2;
double high;
double low = 1;
double answer;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> x >> y >> c;
	
	if (x <= y) high = x;
	else high = y;

	while (low + 0.001 <= high) {
		w = (low+high) / 2;
		h1 = sqrt(x*x - w*w);
		h2 = sqrt(y*y - w*w);
		double c_ = (h1*h2)/(h1+h2);
		if (c_ >= c) {
			answer = w;
			low = w;
		}
		else {
			high = w;
		}
	}
	cout << answer << '\n';
}