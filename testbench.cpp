#include <iostream>
#include "cards.h"
using namespace std;


int main() {
    BST hand1;
    BST hand2;
    Card c1("c", 7);
    Card c2("c", 6);
    Card c3("c", 8);
    hand1.insert(c1);
    hand1.insert(c2);
    hand1.insert(c3);
    hand2.insert(c1);
    hand1.gameTurnMin(hand2).print();

    hand1.printInOrder();
    hand2.printInOrder();

    return 0;

}
