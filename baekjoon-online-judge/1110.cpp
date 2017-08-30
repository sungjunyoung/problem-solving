#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int first = n;
    int n2 = n;
    int count = 0;
    while(1){
        n = n2;
        n2 = n2%10*10 + (n2/10+n2%10)%10;
        count ++;
        if(first == n2){
            break;
        }
    }
    cout << count;
}