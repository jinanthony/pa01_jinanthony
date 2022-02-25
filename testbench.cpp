#include <iostream>
#include "cards.h"
using namespace std;


int main() {
    BST hand1;
    BST hand2;
    Card c1("h", 7);
    Card c2("h", 6);
    Card c3("h", 8);
    
    if (c3>c1){
        cout << "c3>c1";
    }
    if (c2 >= c1){
        cout << "c2 >= c1";
    }
    if (c3 == c2){
        cout << "c3 == c2";
    }

    hand1.insert(c1);
    hand1.insert(c2);
    hand1.insert(c3);
    hand2.insert(c1);
    hand1.gameTurnMin(hand2).print();

    hand1.printInOrder();
    hand2.printInOrder();

    return 0;

}
