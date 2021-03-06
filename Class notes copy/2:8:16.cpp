#include <iostream>
#include <string>
using namepspace std;

class Person{ //struct - everything is public by default
  // class is private by default

  Person(const string& theName):name(theName){


  }
  
  void display() const { //method const place when its a method
    cout << "Person: " << name << endl;
    
  }
  //setter / mutator
  void.setName(const string& theName){
    name = theName;
    
  }
  //getter / accessor
  string getName(){
    return name;
    
  }
private:
  string name;
  
};

void displayPerson(const Person& aPerson){ // function
  //cout << "Person: " << aPerson.name << endl;
  aPerson.display();
}

int main(){
  //Person john;
  Person john("john");
  //john.name = "john";
  john.setName("John");
  displayPerson(john); // outside the class
  john.display(); // inside the class
  
}

// passing primitives by constant reference doesnt gain anything
