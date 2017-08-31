//
// Created by 성준영 on 2017. 8. 31..
//

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> fivot = v[0];

    int x;
    int y;

    if(v[1][0] == fivot[0]){
        x = v[2][0];
    } else {
        if(fivot[0] == v[2][0]){
            x = v[1][0];
        } else {
            x = fivot[0];
        }
    }

    if(v[1][1] == fivot[1]){
        y = v[2][1];
    } else {
        if(fivot[1] == v[2][1]){
            y = v[1][1];
        } else {
            y = fivot[1];
        }
    }

    vector<int> ans;
    ans.push_back(x);
    ans.push_back(y);


    return ans;
}

int main() {
    vector<vector<int> > v;
    vector<int> a;
    a.push_back(1);
    a.push_back(1);

    vector<int> b;
    b.push_back(2);
    b.push_back(2);

    vector<int> c;
    c.push_back(1);
    c.push_back(2);

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    cout << solution(v)[0] << ", " << solution(v)[1] << endl;

}