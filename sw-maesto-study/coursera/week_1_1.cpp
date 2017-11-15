//
// Created by 성준영 on 2017. 10. 10..
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    cin >> input;

    vector<char> stack;
    vector<int> indexStack;

    int i = 1;
    char back;
    for (char c : input) {
        if (stack.size() == 0) {
            back = '-';
        } else {
            back = stack.back();
        }


        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(c);
            indexStack.push_back(i);
        } else if ((c == ')' && back == '(') ||
                   ((c == ']' && back == '[')) ||
                   ((c == '}' && back == '{'))) {
            stack.pop_back();
            indexStack.pop_back();
        } else if (c == ')' || c == ']' || c == '}') {
            cout << i << endl;
            return 0;
        }
        i++;
    }

    if (stack.size() == 0) {
        cout << "Success" << endl;
    } else {
        int min = indexStack[0];
        for (int i = 0; i < indexStack.size(); i++) {
            if (indexStack[i] < min) {
                min = indexStack[i];
            }
        }
        cout << min << endl;
    }
    return 0;
}