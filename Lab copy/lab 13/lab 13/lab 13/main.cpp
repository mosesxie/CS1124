//
//  main.cpp
//  lab 13
//
//  Created by Moses Xie on 4/29/16.
//  Copyright © 2016 Moses Xie. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    Node (int data = 0, Node* next = nullptr) : data(data), next(next) {}
    Node* next;
    int data;
};

void printBits(int n) {
    if (n < 2) {
        cout << n;
    }
    else {
        printBits(n/2);
        cout << n%2;
    }
}
void appendToHead(int val, Node*& headPtr) {
    Node* tmp = new Node(val, headPtr);
    cout << tmp->data<<endl;
    cout << tmp->next<<endl;
    headPtr = tmp;
//    returm tmp;
}

Node* sumoflists(Node* head1, Node* head2){
    if(!head1){
        return nullptr;
    }
    while(head1 != nullptr){
        Node* sum = new Node(head1->data + head2->data);
        sum->next = sumoflists(head1->next, head2->next);
        return sum;
    }
    return nullptr;
}

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

//int max(TNode* root) {
//    return root;
//    // Provide this code
//}



int main() {
    printBits(5);
    cout << endl;
    
    cout << "Sum of lists" << endl;
    Node* target = nullptr;

    appendToHead(3, target);
    appendToHead(2, target);
    appendToHead(1, target);
    Node* target2 = nullptr;
    
    appendToHead(3, target2);
    appendToHead(2, target2);
    appendToHead(1, target2);
    
    cout << target->data << target->next->data << target->next->next->data<<endl;
    cout << target2->data << target2->next->data << target2->next->next->data<<endl;

    Node* result = sumoflists(target,target2);
    cout << result->data << result->next->data << result->next->next->data;
    
    
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    //cout << max(&f) << endl;
    
    
    
    
    
    }


