//
//  Polynomial.h
//  hw8
//
//  Created by Moses Xie on 5/6/16.
//  Copyright © 2016 Moses Xie. All rights reserved.
//

#include<string>
#include<vector>
#include<iostream>

#ifndef Polynomial_h
#define Polynomial_h

struct Node{
    Node(int number);// -------

    int data;
    Node* next;
    
};

class Polynomial{
    
    size_t degree;
    Node* coefficients;
public:
    //constructors and deconstructors
    Polynomial(); // -------
    Polynomial(const vector<int>& numbers); // -------
    ~Polynomial(); // -------
    
    // assignment operator
    Polynomial operator=(Polynomial& rhs); // -------
    
    //copy constructor
    Polynomial(const Polynomial& rhs);// -------
    
    Polynomial& operator+=(Polynomial& addon); // -------
    
    bool Polynomial::operator==(Polynomial& poly);
    
    bool Polynomial::operator!=(Polynomial& poly);
    
    
    friend std::ostream& operator<<(std::ostream& cout, Polynomial& poly);
};

std::ostream& operator<<(std::ostream& cout, Polynomial& poly){

}


Polynomial operator+(Polynomial& poly1, Polynomial& poly2);// -------

#endif /* Polynomial_h */
