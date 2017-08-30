#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int hanoi(string a, string b, string c){

}

int main() {
    pair<int,string> tower[3];

    for(int i=0;i<3;i++){
        cin >> tower[i].first;
        cin >> tower[i].second;
    }

    string flat[3];
    for(int i=0;i<3;i++){
        cin >> tower[i].second;
    }



    return 0;
}