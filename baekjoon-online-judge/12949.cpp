#include <iostream>

using namespace std;

int countResult(string input) {

    pair<int, int> point;
    point.first = 0;
    point.second = 0;

    int count = 0;

    for (int i = 1; i <= input.length(); i++) {
        if (input[i - 1] == 'U') {
            point.second += 1;
        } else if (input[i - 1] == 'D') {
            point.second -= 1;
        } else if (input[i - 1] == 'L') {
            point.first -= 1;
        } else if (input[i - 1] == 'R') {
            point.first += 1;
        }

        if (point.first == 0 && point.second == 0) {
            count++;
        }
    }

    return count;
}

int maxResult(string input, int index) {
    int max = 0;
    string temp = input;
    temp[index] = 'U';

    max = countResult(temp);

    temp = input;
    temp[index] = 'D';
    if (max < countResult(temp)) {
        max = countResult(temp);
    }

    temp = input;
    temp[index] = 'L';
    if (max < countResult(temp)) {
        max = countResult(temp);
    }

    temp = input;
    temp[index] = 'R';
    if (max < countResult(temp)) {
        max = countResult(temp);
    }

    return max;

}

int main() {
    string s;
    int m;

    cin >> s >> m;

    int D[301][301];

    D[1][1] =
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 1; j <= m; j++) {
            D[]
        }
    }


    return 0;
}




















