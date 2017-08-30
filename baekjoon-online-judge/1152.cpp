//
// Created by 성준영 on 2017. 4. 12..
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    bool emptyFlag = false;
    for (int i = 0; i <= input.length() - 1; i++) {
        if (input[i] != ' ') {
            break;
        }
        if(i == input.length()-1){
            emptyFlag = true;
        }
    }

    if(emptyFlag){
        cout << 0 << endl;
        return 0;
    }


    int count = 1;
    for (int i = 1; i < input.length() - 1; i++) {


        if (input[i] == ' ' && input[i - 1] != ' ' && input[i + 1] != ' ') {
            count++;
        }
    }


    cout << count;
}