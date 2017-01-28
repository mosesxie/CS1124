//
//  main.cpp
//  lab 12
//
//  Created by Moses Xie on 4/22/16.
//  Copyright © 2016 Moses Xie. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* link;
    
    Node(int number):data(number), link(nullptr){};
};

class Sequence {
public:
    Node* current;
    Node* head;
    Sequence():head(nullptr), current(nullptr){};
    
    ~Sequence(){
        clear();
    };
    
    Sequence(const Sequence& seq) {
        if (seq.head == nullptr) {
            head = nullptr;
            current = nullptr;
        } else {
            head = new Node(seq.head->data, nullptr);
            current = head;
            Node* tmp = seq.head;
            while (tmp != nullptr) {
                current->link = new Node(tmp->data, nullptr);
                current = current->link;
                tmp = tmp->link;
            }
        }
    }
    
    Sequence& operator=(Sequence& other) {
        if (this != &other) {
            Sequence* seq = new Sequence(other);
            return *seq;
        }
        return other;
    }

    
    void reset(){
        current = head;
    }

    void add(int number)
    {
        if(head==nullptr)
        {
            head = new Node(number);
            current = head;
        }
        else{
            if(current!=nullptr)
            {
                if(current->link == nullptr)
                {
                    current->link = new Node (number);
                    current = current->link;
                }
                else{
                
                    Node* temp = current->link;
                    current->link = new Node(number);
                    current = current->link;
                    current->link =  temp;
                }
            }
            
        }
    }
    void remove(){
        if(current != nullptr){
            Node* temp = head;
            while(temp->link != current){
                temp = temp->link;
            }
            temp->link = temp->link->link;
        }
    }
    int data(){
        if (current == nullptr){
            cout<< "invalid" << endl;
            return NULL;
        }
        
        else{
            return current->data;
        }
    }
    void next(){
        if (current == nullptr){
            current = nullptr;
        }
        else{
            current = current->link;
        }
    }
    bool valid(){
        return current != nullptr;
    }
    void clear(){
        this->reset();
        while(current != nullptr){
            if (current->link != nullptr){
                Node* temp = current->link;
                delete current;
                current = temp;
            }
        }
        
    }
    void display(){
        if(head == nullptr){
            cout << endl;
            return;
        }
        Node* increment = head;
        while(increment->link != nullptr){
            cout << increment->data << " ";
            increment = increment->link;
        }
        cout << increment->data << " " << endl;
    }
    
    
};

int main() {
    Sequence s;
    for (int i = 0; i < 6; ++i) s.add(i);
    s.display();
    cout << "==========\n";
    s.reset();
    for (int i = 0; i < 3; ++i) {
        s.next();
    }
    s.add(42);
    s.display();
    cout << "==========\n";
    s.reset();
    for (int i = 0; i < 2; ++i) {
        s.next();
    }
    s.remove();
    s.display();
    cout << "==========\n";
    s.clear();
    s.display();
    cout << "==========\n";
}
