#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input;
    cin >> input;
    vector<char> inputVector;
    long long count = 0;

    for (int i = 0; i < input.size(); i++) {
        inputVector.push_back(input[i]);
        if (inputVector[inputVector.size() - 2] == '(' && inputVector[inputVector.size() - 1] == ')') {
            inputVector.pop_back();
            inputVector.pop_back();
            count ++;
        }
    }

    cout << count;

    return 0;
}