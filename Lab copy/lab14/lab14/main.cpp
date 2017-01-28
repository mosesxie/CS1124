//
//  main.cpp
//  lab14
//
//  Created by Moses Xie on 5/6/16.
//  Copyright © 2016 Moses Xie. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <string>
#include <map>
using namespace std;

void task8(const list<int>& li){
    for (list<int>::const_iterator iter = li.begin(); iter != li.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

void task9(list<int> list){
    for(int i :list){
        cout << i << " ";
    }
    cout << endl;
    
}

list<int>::const_iterator task11(const list<int> li, int target){
    for (auto iter = li.begin(); iter != li.end(); iter++){
        if(*iter == target){
            return iter;
        }
    }
    return li.end();
}

list<int>::const_iterator task12(const list<int> li, int target){
    for (list<int>::const_iterator iter = li.begin(); iter != li.end(); iter++){
        if(*iter == target){
            return iter;
        }
    }
    return li.end();
}

vector<int>::iterator task17(vector<int>::iterator start, vector<int>::iterator stop, int target) {
    for (vector<int>::iterator p = start; p != stop; ++p) {
        if (target == *p){
            cout << &p;
            return p;
        }
    }
    
    return stop;
}

//auto task18(auto start, auto stop,auto target) {
//    for (auto p = start; p != stop; ++p) {
//        if (target == *p){
//            cout << &p;
//            return p;
//        }
//    }
//    
//    return stop;
//}



int main() {

// Task 1
    vector<int> task1;
    task1.push_back(3);
    task1.push_back(9);
    task1.push_back(1);
    task1.push_back(8);
    
    for(int x : task1){
        cout << x << " ";
    }
    cout << endl;
    
// Task 2
    list<int> task2;
    task2.push_back(3);
    task2.push_back(9);
    task2.push_back(1);
    task2.push_back(8);
    for (list<int>::iterator iter = task2.begin(); iter != task2.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    
// Task 3
    sort(task1.begin(), task1.end());
    for(int x : task1){
        cout << x << " ";
    }
    cout << endl;
    
// Task 4
    for (size_t i = 0; i < task1.size(); i += 2){
        cout << task1[i] << " ";
    }
    cout << endl;
    
// Task 5
    task2.sort();
    
// Task 6
    for (vector<int>::iterator iter = task1.begin(); iter != task1.end(); iter++,iter++){
        cout << *iter << " ";
    }
    cout << endl;
    
// Task 7
    for (list<int>::iterator iter = task2.begin(); iter != task2.end(); iter++,iter++){
        cout << *iter << " ";
    }
    cout << endl;
    
// Task 8
    task8(task2);
    
// Task 9
    task9(task2);
    
// Task 10
    for (auto iter = task1.begin(); iter != task1.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    
// Task 11
    task11(task2, 3);
    
// Task 12
    task12(task2, 3);
    
// Task 13
    find(task2.begin(),task2.end(), 4);
    
// Task 15
    cout << *find_if(task2.begin(), task2.end(),
                     [] (int n) { return n % 2 == 0; } // lambda expression
                     ) << endl;
    
// Task 16
    int arr[4];
    copy(task1.begin(),task1.end(), arr);
    for(int i = 0; i < 4; i++){ cout << arr[i] << " ";}
    cout << endl;

// Task 17
    task17(task1.begin(), task1.end(), 3);
    cout << endl;

// Task 18
    // task18(task1.begin(), task1.end(), 8);
    cout << endl;
    
// Task 19
    ifstream file;
    string word;
    vector<string> listofwords;
    file.open("/Users/mosesxie/Google Drive/CS 1124/Lab/lab14/lab14/pooh-nopunc.txt");
    while(file >> word){
        auto x = find(listofwords.begin(),listofwords.end(), word);
        if(x == listofwords.end()){
            listofwords.push_back(word);
            
        }
    }
    
    for (auto x = listofwords.begin(); x != listofwords.end(); x++){
        cout << *x << " ";
        
    }
    
// Task 20
    file.close();
    file.open("/Users/mosesxie/Google Drive/CS 1124/Lab/lab14/lab14/pooh-nopunc.txt");
    set<string> task20;
    while(file >> word){
        task20.insert(word);
    }
    
    for (auto x = task20.begin(); x != task20.end(); x++){
        cout << *x << " ";
    }

// Task 21
    file.close();
    file.open("/Users/mosesxie/Google Drive/CS 1124/Lab/lab14/lab14/pooh-nopunc.txt");
    int values=0;
    map<string, vector<int>> mapofwords;
    while(file >> word){

        mapofwords[word].push_back(values++);
    }
    
    for (const auto& x : mapofwords){
        
        cout << x.first << " ";
        
        for(auto y : x.second){
        cout << y << " ";
        }
        
    }
    
}




