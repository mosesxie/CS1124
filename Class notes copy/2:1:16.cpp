#include <iostream>
#include <string>
#include <vector>
#include <ifstream>
using namespace std;


/*
int main(){

  string s2 = "Twas brilling";
  for (char c : s2){
    cout << c+1 < ' '; // out puts a int because when compared it 'promotes it' to an int
    char d = c + 1; // fixes this
    cout << d << ' ';
    
    
  }
  cout << endl;
  return 0;
}
*/

struct Sandwich{
  int slices;
  // int slices = 2; you could not give a value of it when you create the struct until c++ 11
  string type;
  
  

};

void fillSandwiches(ifstream ifs, vector<Sandwich>& s){

  

}

void displaySanwich(const Sandwich&  s){
  cout << s.type << ", " << s.slices << endl;
  

}

int main(){

  Sandwich blt;
  cout << sizeof(blt) << endl;
  cout << blt.slices << endl; // if varibles or memory are not specifically assigned we dont know what we will get
  blt.type = "bacon lettuce and tomato";

  displaySandwich(blt);
  
  vector<Sandwich> vs;
  vs.push_back(blt); // push back makes a copy so when slices is changed to 10 blt is changed not vs[0]
  displaySandwich(vs[0]);

  blt.slices = 10;
  displaySandwich(vs[0]); // will still display 3 slices

  ifstream sandwichStream("sandwiches");
  if(!sandwichStream){
    cerr << "some error message" << endl;
    exit(1);
    
  }

  string theType;
  int numSlices;
  while(sandwichStream >> theType >> numSlices){// assumes the name has no white spaces and the type and slices are separted by white space
    Sandwich aSandwich;
    aSandwich.type = theType;
    aSandwich.slices = numSlices;
    vs.push_back(aSandwich);
  }

  sandwichStream.close();

  for(const Sandwich& s : vs){
    displaySandwich(s);
    
  }
  
  

}
