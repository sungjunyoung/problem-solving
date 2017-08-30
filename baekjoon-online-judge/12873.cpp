#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> people(n);
    for(int i=1;i<=n;i++){
        people[i-1] = i;
    }

    auto it = people.begin();
    for(int i=1; i<n;i++){
        int p = ((long long)i*i*i-1)%people.size();
        for(int i=0;i<p;i++){
            it++;
            if(it==people.end()){
                it=people.begin();
            }
        }
        it = people.erase(it);
        if(it == people.end()){
            it=people.begin();
        }
    }

    cout << people[0] << endl;

    return 0;
}