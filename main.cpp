#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
    
  BST hand1;
  BST hand2;
  string s, v;
  int value;

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    s = line.substr(0, 1);
    v = line.substr(2);

    if (v == "a"){
        value = 1;
    }
    else if (v == "j"){
        value = 11;
    }
    else if (v == "q"){
        value = 12;
    }
    else if (v == "k"){
        value = 13;
    }
    else{
        value = stoi(v);
    }

    Card c(s, value);
    hand1.insert(c);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    s = line.substr(0, 1);
    v = line.substr(2);
    
    if (v == "a"){
        value = 1;
    }
    else if (v == "j"){
        value = 11;
    }
    else if (v == "q"){
        value = 12;
    }
    else if (v == "k"){
        value = 13;
    }
    else{
        value = stoi(v);
    }
                  
    Card c(s, value);
    hand2.insert(c);
  }
  cardFile2.close();
  
  bool playing = true;
  Card c1, c2;

  while (playing){

          c1 = hand1.gameTurnMin(hand2);
          if (c1.getI()!=0){
              cout << "Alice picked matching card ";
              c1.print();
          }
      
     
          c2 = hand2.gameTurnMax(hand1);
          if (c2.getI() != 0){
              cout << "Bob picked matching card ";
              c2.print();
          }
    
      
      if (c1.getI() == 0 && c2.getI() == 0){
          playing = false;
      }
  }
  
  cout << endl;
  cout << "Alice's cards: " << endl;
  hand1.printInOrder();
  cout << endl;

  cout << "Bob's cards: " << endl;
  hand2.printInOrder();

  return 0;
}
