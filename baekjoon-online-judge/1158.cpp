#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> men;
    vector<int> order;
    int n, m, i, index;
    cin >> n >> m;

    for (i = 1; i <= n; i++)
        men.push_back(i);

    index = m-1;
    while(1){
        order.push_back(men[index]);
        men.erase(men.begin()+index);
        index = index+m-1;

        if(men.size() == 0){
            break;
        }
        while(index>= men.size()) {
            index = index - men.size();
        }
    }

    cout << "<";
    for ( i=0; i<n-1;i++){
        cout << order[i] << ", ";
    }

    cout << order[n-1] << ">";

    return 0;
}