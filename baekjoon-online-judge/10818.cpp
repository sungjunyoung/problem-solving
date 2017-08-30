//
// Created by 성준영 on 2017. 4. 10..
//

#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> numList;

    while (n--) {
        int num;
        scanf("%d", &num);
        numList.push_back(num);
    }

    int min = numList[0];
    int max = numList[0];

    for (int i = 0; i < numList.size(); i++) {
        if(numList[i] < min){
            min = numList[i];
        }

        if(numList[i] > max){
            max = numList[i];
        }
    }

    printf("%d\n%d", min, max);
}