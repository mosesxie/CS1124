//
//  main.cpp
//  lab11
//
//  Created by Moses Xie on 4/15/16.
//  Copyright © 2016 Moses Xie. All rights reserved.
//

#include <iostream>
#include <cstdlib> // To allow NULL if no other includes
using namespace std;

struct Node {
    Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
    int data;
    Node* link;
};


void printList (Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->link;
    }
    cout << endl;
}

Node* listInsertHead(int entry, Node*& headPtr) {
    headPtr = new Node(entry, headPtr);
    return headPtr;
    
}

void spliceList(Node*& entryPoint, Node*& subList){
    Node* temp = entryPoint->link;
    entryPoint->link = subList;
    while(subList->link != nullptr){
        subList = subList->link;
    }
    subList->link = temp;
}

Node* findList(Node* node1, Node* node2) {
    if (node1 == NULL)
        return NULL;
    
    cout << "\nAttempt match: ";
    printList(node1);
    
    Node* currentNode2 = NULL;
    Node* tmpSearch = node1;
    Node* start = NULL;
    while (tmpSearch != NULL) {
        Node* tmpFind = tmpSearch;
        currentNode2 = node1;
        while (currentNode2 != NULL && tmpFind != NULL) {
            if (currentNode2->data != tmpFind->data) break;
            currentNode2 = currentNode2->link;
            tmpFind = tmpFind->link;
            
        }
        if (currentNode2 == NULL) {
            start = tmpSearch;
            break;
        }
        tmpSearch = tmpSearch->link;
    }
    
    if (start != NULL) {
        return start;
    } else {
        cout << "Failed to match" << endl;
        return NULL;
    }
}



int main() {
//    std::cout << "Part One:\n" << std::endl;
//    Node* l1 = NULL;
//    listInsertHead(1, l1);
//    listInsertHead(9, l1);
//    Node* ptr = listInsertHead(7, l1);
//    listInsertHead(5, l1);
//    
//    Node* l2 = NULL;
//    listInsertHead(2, l2);
//    listInsertHead(3, l2);
//    Node* ptr2 = listInsertHead(6, l2);
//    
//    cout << "L1: ";
//    printList(l1);
//    cout << "L2: ";
//    printList(l2);
//
//    spliceList(ptr, ptr2);
//    
//    cout << "L1: ";
//    printList(l1);
//    cout << "L2: ";
//    printList(l2);

    cout << "Part Two:" << endl;
    
    Node* target = NULL;
    listInsertHead(5, target);
    listInsertHead(7, target);
    listInsertHead(6, target);
    listInsertHead(3, target);
    listInsertHead(2, target);
    listInsertHead(9, target);
    listInsertHead(1, target);

    cout << "Target: ";
    printList(target);
    
    Node* find1 = NULL;
    listInsertHead(6, find1);
    listInsertHead(3, find1);
    listInsertHead(2, find1);
    listInsertHead(9, find1);
    
    printList(findList(target, find1));
    
    Node* find2 = NULL;
    listInsertHead(6, find2);
    listInsertHead(2, find2);
    listInsertHead(3, find1);
    printList(findList(target, find2));
    
    Node* find3 = NULL;
    listInsertHead(2, find3);
    listInsertHead(9, find3);
    listInsertHead(1, find1);
    listInsertHead(4, find1);
    
    printList(findList(target, find3));


    }
