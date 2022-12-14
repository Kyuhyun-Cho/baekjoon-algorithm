#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    cin >> a >> b;
    
    multiset<int> mset;
    multiset<int>::iterator iter;
    int num;
    for (int i = 0; i < a; i++) {
        cin >> num;
        mset.insert(num);
    }
    for (int i = 0; i < b; i++) {
        cin >> num;
        mset.insert(num);
    }

    for(iter = mset.begin(); iter != mset.end(); iter++){
        cout << *iter << " " ;
    }
}
