//
// Created by 성준영 on 2017. 5. 15..
//

#include <iostream>
#include <vector>

using namespace std;

class Node {
private:
    char data;
    Node *left;
    Node *right;
public:
    Node(char data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    char getData() {
        return data;
    }

    void setData(char data) {
        this->data = data;
    }

    Node *getLeft() {
        return left;
    }

    void setLeft(Node *left) {
        this->left = left;
    }

    Node *getRight() {
        return right;
    }

    void setRight(Node *right) {
        this->right = right;
    }
};

class Tree {
private:
    Node *root;
public:
    Node *getRoot() const {
        return root;
    }

public :
    Tree() {
        root = NULL;
    }

    Tree(Node *root) {
        this->root = root;
    }

    void preOrder(Node * root){
        cout << root->getData();
        if(root->getLeft() != NULL) preOrder(root->getLeft());
        if(root->getRight() != NULL) preOrder(root->getRight());
    }

    void inOrder(Node *root){
        if(root->getLeft() != NULL)
            inOrder(root->getLeft());
        cout << root->getData();
        if(root->getRight() != NULL)
            inOrder(root->getRight());
    }

    void postOrder(Node *root){
        if(root->getLeft() != NULL) postOrder(root->getLeft());
        if(root->getRight() != NULL) postOrder(root->getRight());
        cout << root->getData();
    }

    void search(Node *root, char data, char leftData, char rightData){
        if(root == NULL){
            return;
        }
        else if(root->getData() == data){
            if(leftData != '.') root->setLeft(new Node(leftData));
            if(rightData != '.') root->setRight(new Node(rightData));
        }
        else {
            search(root->getLeft(), data, leftData, rightData);
            search(root->getRight(), data, leftData, rightData);
        }
    }

    void add(char data, char leftData, char rightData) {
        if (root == NULL) {
            if (data != '.') {
                root = new Node(data);
            }
            if (leftData != '.') {
                root->setLeft(new Node(leftData));
            }
            if(rightData != '.'){
                root->setRight(new Node(rightData));
            }
        } else {
            search(root, data, leftData, rightData);
        }
    }

};


int main() {
    Tree t;
    int n;
    cin >> n;
    while (n--) {
        char a, b, c;
        scanf(" %c %c %c", &a, &b, &c);
        t.add(a, b, c);
    }

    t.preOrder(t.getRoot());
    cout <<endl;
    t.inOrder(t.getRoot());
    cout << endl;
    t.postOrder(t.getRoot());

}