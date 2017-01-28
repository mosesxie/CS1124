//
//  Polynomial.cpp
//  hw8
//
//  Created by Moses Xie on 5/6/16.
//  Copyright © 2016 Moses Xie. All rights reserved.
//

#include "polynomial.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;


Node::Node(int number): data(number), next(nullptr){};

Polynomial::Polynomial(){};

Polynomial::Polynomial(const vector<int>& numbers):degree(numbers.size()){
    coefficients = new Node(numbers[0]);
    Node* temp = coefficients;
    for (size_t i = 0; i < numbers.size(); ++i){
        temp = new Node(numbers[i]);
        if (coefficients != nullptr){
            temp->next = coefficients;
        }
        coefficients = temp;
        
    }
};

Polynomial::~Polynomial(){
    Node* temp = coefficients;
    while (temp != nullptr) {
        coefficients = coefficients->next;
        delete temp;
        temp = coefficients;
        }
    };

Polynomial::Polynomial(const Polynomial& rhs) : coefficients(nullptr) {
    this->degree = rhs.degree;
    Node* temp = rhs.coefficients;
    while (temp != nullptr){
        if (coefficients == nullptr) {
            coefficients = new Node(temp->data);
        }
        else {
            coefficients->next = new Node(temp->data);
            temp = coefficients->next;
        }
        temp = temp->next;
    }
}

Polynomial Polynomial::operator=(Polynomial& rhs){
    if(*this!=rhs){
        degree = rhs.degree;
        Node* temp = coefficients;
        while (temp != nullptr) {
            coefficients = coefficients->next;
            delete temp;
            temp = coefficients;
        }
    }
    degree = rhs.degree;
    Node* iter = rhs.coefficients;
    while (iter != nullptr){
        if (coefficients == nullptr) {
            coefficients = new Node(iter->data);
        }
        else {
            if (coefficients == nullptr) {
                return *this;
            }
            Node* tempPtr = coefficients;
            while (tempPtr->next != nullptr) {
                tempPtr = tempPtr->next;
                
                Node* last = tempPtr;
                last->next = new Node(iter->data);
            }
            iter = iter->next;
        }
        return *this;
    }
    return *this;
}

Polynomial& Polynomial::operator+=(Polynomial& addon){
    Node* current1 = coefficients;
    Node* current2 = addon.coefficients;
    if (current2 == nullptr) { return *this; }
    if (current1 == nullptr) { current1 = current2; return *this; }
    for (int i = 0; i < addon.degree + 1; ++i) {
        if ( current1 != nullptr && current2 != nullptr) {
            current1->data += current2->data;
            current1 = current1->next;
            current2 = current2->next;
        }
        else {
            if (current1 == nullptr){
                current1 = new Node(current2->data);
                current2 = current2->next;
            }
            current1 = current1->next;
        }
    }
    return *this;
}

bool Polynomial::operator==(Polynomial& poly){
    Node* temp = coefficients;
    Node* temp2 = poly.coefficients;
    if (degree != poly.degree) {
        return false;
    }
    for (int i = 0; i < degree; ++i) {
        if (!temp || !temp2){ return true; }
        if (temp->data == temp2->data) {
            temp = temp2->next;
            temp2 = temp2->next;
        }
    }
    return (temp->next == nullptr && temp2->next == nullptr && temp->data == temp2->data);}

bool Polynomial::operator!=(Polynomial& poly){return !(Polynomial::operator==(poly))}

Polynomial operator+(Polynomial& poly1, Polynomial& poly2) {
    Polynomial result((poly1));
    return (result += poly2);
}







