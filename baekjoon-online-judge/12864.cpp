#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    double books[5001] = {0,};

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> books[i];
    }

    int weight[5001] = {0,};
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
        sum += weight[i];
    }

    int d[5001] = {0,};
    vector<int> sub;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if(books[j] > books[i] || i==j){
                sub.push_back(weight[i]);
            } else{
                sub.push_back(d[j] + weight[i]);
            }
        }
        int maxD = sub[0];
        for(int j=1 ; j<sub.size();j++){
            maxD = max(maxD,sub[j]);
        }
        d[i] = maxD;
        sub.clear();
    }

    int maxSum = d[1];
    for(int i=1;i<= n;i++){
        maxSum=max(maxSum,d[i]);
    }

    cout << sum - maxSum << endl;


    return 0;
}