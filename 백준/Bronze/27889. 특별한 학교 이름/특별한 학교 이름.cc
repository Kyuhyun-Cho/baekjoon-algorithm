#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str; cin >> str;
    if (str == "NLCS") cout << "North London Collegiate School" << '\n';
    else if (str == "BHA") cout << "Branksome Hall Asia" << '\n';
    else if (str == "KIS") cout << "Korea International School";
    else cout << "St. Johnsbury Academy" << '\n';
}
