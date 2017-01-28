#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
char characterDecrypted(char character, int increment)
{
  char decryptedCharacter = character + increment; // changes the encryped character 
  return decryptedCharacter; // return the decrypted character


}

void stringDecrypted(string& line, int increment)
{
  for(size_t index = 0;index < line.size(); ++index){ // go over every char in the string
    if(line[index] >= 'a' and line[index] <= 'z'){
      line[index] = characterDecrypted(line[index], increment); // decrypted the lowercase leaving the upper case and white space

    } 
  }


}

*/

int main(){

  ifstream file;
  int increment;
  string line;

  file.open(/Users/mosesxie/Google Drive/CS 1124/hw1/encrypted.txt); // how to read lines in a file

  getline(file, increment);

  /* for(getline(file,line)){
    stringDecrypted(line, increment);

    }

  */

  cout << line << endl;
  

  return 0;
  
  
  

}

main()
