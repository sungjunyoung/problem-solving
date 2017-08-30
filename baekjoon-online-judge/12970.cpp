#include <iostream>
#include <vector>

using namespace std;

int main() {

    int w, h, a;
    cin >> w >> h >> a;

    if (w * h == a) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> partA;
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            partA.push_back(i);
        }
    }

    int n;
    if (partA.size() % 2 == 1) {
        n = (int) partA.size() + 1;
    } else {
        n = (int) partA.size();
    }
    vector<pair<int, int>> pairPartA(n / 2);
    for (int i = 0; i < partA.size() / 2; i++) {
        pairPartA[i].first = partA[i];
        pairPartA[i].second = partA[partA.size() - 1 - i];
    }
    if (partA.size() % 2 == 1) {
        pairPartA[n / 2 - 1].first = partA[partA.size() / 2];
        pairPartA[n / 2 - 1].second = partA[partA.size() / 2];
    }

    int checkW, checkH;
    int count;
    vector<int> resultVec;

    for(int j=0;j<2;j++){
        for (int i = 0; i < pairPartA.size(); i++) {
            count = 0;
            checkW = pairPartA[i].first;
            checkH = pairPartA[i].second;
            if (checkW > w || checkH > h) {
                continue;
            }

            do {
                if (checkW == w) {
                    break;
                }
                checkW *= 2;
                count++;
            } while (checkW < w);
            do {
                if (checkH == h) {
                    break;
                }
                checkH *= 2;
                count++;
            } while (checkH < h);
            resultVec.push_back(count);
        }

        swap(w, h);
    }


    int min = 1000000;
    for (int i = 0; i < resultVec.size(); i++) {
        if (resultVec[i] < min) {
            min = resultVec[i];
        }
    }

    if (min == 1000000) {
        cout << -1 << endl;
    } else {
        cout << min << endl;
    }

    return 0;
}