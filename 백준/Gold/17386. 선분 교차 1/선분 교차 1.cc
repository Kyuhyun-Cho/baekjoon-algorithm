#include <iostream>
#define coord pair<long long, long long>
#define x first
#define y second

using namespace std;

int ccw(coord a, coord b, coord c){
	long long val = ((a.x*b.y)+(b.x*c.y)+(c.x*a.y)) - ((b.x*a.y)+(c.x*b.y)+(a.x*c.y));
	if (val > 0) return 1;
	else if (val == 0) return 0;
	else return -1;
}

int main() {
	coord a, b, c, d;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;

	int A = ccw(a,b,c)*ccw(a,b,d);
	int B = ccw(c,d,a)*ccw(c,d,b);

	if ((A <= 0) && (B <= 0)) cout << 1 << '\n';
	else cout << 0 << '\n';
}