#include <iostream>
#include <cstring>

using namespace std;

int nowAcgt[4];

void checkAdd(char a) {
    switch (a) {
        case 'A':
            nowAcgt[0]++;
            break;
        case 'C':
            nowAcgt[1]++;
            break;
        case 'G':
            nowAcgt[2]++;
            break;
        case 'T':
            nowAcgt[3]++;
            break;
    }
}

void checkSub(char a) {
    switch (a) {
        case 'A':
            nowAcgt[0]--;
            break;
        case 'C':
            nowAcgt[1]--;
            break;
        case 'G':
            nowAcgt[2]--;
            break;
        case 'T':
            nowAcgt[3]--;
            break;
    }
}

int main() {
    memset(nowAcgt, 0, sizeof(nowAcgt));
    int s, p;
    cin >> s >> p;
    string dna;
    cin >> dna;


    int acgt[4];
    for (int i = 0; i < 4; i++) {
        cin >> acgt[i];
    }

    int count = 0;
    for (int i = 0; i <= dna.length() - p; i++) {
        if (i == 0) {
            for (int j = 0; j < p; j++) {
                checkAdd(dna[j]);
            }
        } else {
            checkSub(dna[i - 1]);
            checkAdd(dna[i + p - 1]);
        }

        int flag = true;
        for (int j = 0; j < 4; j++) {
            if (acgt[j] > nowAcgt[j]) {
                flag = false;
                break;
            }

        }

        if (flag == true)
            count++;
    }


    cout << count << '\n';

    return 0;
}