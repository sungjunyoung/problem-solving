#include <iostream>
#include <string>

using namespace std;

bool check(long long checkInt, int d1, int d2, int c1, int c2){
    int resultC1=0, resultC2=0;
    string checkString = to_string(checkInt);
    for(int i=0; i<checkString.size(); i++){
        if(checkString[i] == d1+'0'){
            resultC1++;
        }
        if(checkString[i] == d2+'0'){
            resultC2++;
        }

        if(c1==resultC1 && c2 == resultC2){
            return true;
        }
    }

    return false;

}

int main() {
    long long N;
    int d1, c1, d2, c2;
    cin >> N >> d1 >> c1 >> d2 >> c2;

    long long ans = N;
    while(1){
        if(check(ans,d1,d2,c1,c2)){
            cout << ans << endl;
            break;
        }
        ans++;
    }

    return 0;
}