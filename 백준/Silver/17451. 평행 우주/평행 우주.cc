#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    long long n;
    cin >> n;
    long long vel[n] = {0,};
    for (int i = 0; i < n; i++) {
        cin >> vel[i];
    }

    for (int i = n-2; i >= 0; i--) {
        long long share = vel[i+1] / vel[i];
        long long mod = vel[i+1] % vel[i];
        if (mod != 0) mod = 1;
        vel[i] = vel[i] * (share+mod);
    }

    cout << vel[0] << '\n';

    return 0;
}