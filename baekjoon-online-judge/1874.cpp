#include <iostream>
#include <vector>
#include "queue"
#include "stack"

using namespace std;


int main() {
    vector<int> numQueue;
    vector<int> inputQueue;
    vector<int> stack;
    vector<int> resultVector;
    string result = "";
    int count;
    int num;
    int i = 1;
    cin >> count;
    while (count--) {
        cin >> num;
        inputQueue.push_back(num);
        numQueue.push_back(i);
        i++;
    }

    count = 0;
    while (inputQueue.size() != 0) {
        if (stack.size() == 0) {
            stack.push_back(numQueue.front());
            result.append("+\n");
            numQueue.erase(numQueue.begin());
        } else if (stack[stack.size()-1] < inputQueue.front()) {
            stack.push_back(numQueue.front());
            result.append("+\n");
            numQueue.erase(numQueue.begin());
        } else if (stack[stack.size()-1] > inputQueue.front()) {
            result="NO";
            break;
        } else if (stack[stack.size()-1] == inputQueue.front()) {
            inputQueue.erase(inputQueue.begin());
            resultVector.push_back(stack[stack.size()-1]);
            stack.pop_back();
            result.append("-\n");
        }
        count ++;
    }
    cout << result << endl;

    return 0;
}