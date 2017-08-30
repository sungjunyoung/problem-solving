#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int arr[4000001] = {0,};
vector<int> vec;

int main() {

    int input = 0;
    cin >> input;

    for(int i=2; i<=4000000; i++){
        arr[i] = i;
    }

    for(int i=2; i<=sqrt(4000000); i++){
        if(arr[i] == 0)
            continue;
        for(int j=i+i; j<4000000; j+=i){
            arr[j] = 0;
        }
    }

    for(int i=2; i<=4000000 ; i++){
        if(arr[i] != 0)
            vec.push_back(arr[i]);
    }

    int count = 0, sum= 0, low=0, high=0;
    while(1){
        if(sum >= input) sum-=vec[low++];
        else if(high == vec.size()) break;
        else sum+=vec[high++];
        if(sum==input) count++;
    }

    cout << count << "\n";
    return 0;
}
