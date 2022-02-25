nclude <iostream>
#include "cards.h"
using namespace std;

int main() {
/*
    CardsBST Alice, Bob;
    Cards d5('d', "5");
    Cards s10('s', "10");
    Cards c7('c', "7");
    Cards c9('c', "9");
    Cards d2('d', "2");
    Cards h2('h', "2");
    Cards cK('c', "K");
    Cards cJ('c', "J");

    Cards empty('z', "0");

    Alice.insert(d5);
    Alice.insert(s10);
    Alice.insert(c7);
    Alice.insert(h2);
    Alice.insert(cK);
    Bob.insert(c9);
    Bob.insert(d2);
    Bob.insert(h2);
    Bob.insert(d5);
    Bob.insert(cJ);

    cout << "Testing In Order" << endl;
    cout << "Alice's Hand: " << endl;
    Alice.printInOrder();
    cout << "Bob's Hand: " << endl;
    Bob.printInOrder();

    cout << "Successors / Predecessors Test" << endl;
    Cards p = Alice.getPredecessor(cJ);
    cout << "Predecessor: " << p.getSuit() << " " << p.getVal() << endl;
    cout << "Predecessor: " << Bob.getPredecessor(d2).getSuit() << " " << Bob.getPredecessor(d2).getVal() << endl;
    cout << "Successor: " << Alice.getSuccessor(c6).getSuit() << " " << Alice.getSuccessor(c6).getVal() << endl;
    cout << "Successor: " << Bob.getSuccessor(c9).getSuit() << " " << Bob.getSuccessor(c9).getVal() << endl;

    cout << "Max / Min Test" << endl;
    cout << "Alice's Max: " << Alice.findMax().getSuit() << " " << Alice.findMax().getVal() << endl;
    cout << "Alice's Min: " << Alice.findMin().getSuit() << " " << Alice.findMin().getVal() << endl;
    cout << "Bob's Max: " << Bob.findMax().getSuit() << " " << Bob.findMax().getVal() << endl;
    cout << "Bob's Min: " << Bob.findMin().getSuit() << " " << Bob.findMin().getVal() << endl;

    Cards aMax = Alice.findMin();
    Cards bMin = Bob.findMax();

    while (!(aMax == nullCard) & !(bMin == nullCard))
    {
        cout << " ALICE CARDS " << endl;
        Alice.printInOrder();
        cout << " BOB CARDS " << endl;
        Bob.printInOrder();
        if (Bob.contains(aMax))
        {
            cout << "bob contains alice." << endl;
            Bob.remove(aMax);
            // cout << "successfully removed in BOB" << endl;
        }
        Cards a = Alice.getSuccessor(aMax);
        // cout << "successor got ";
        Alice.remove(aMax);
        aMax = a;
    }
    cout << "Alice's cards: \n";
    Alice.printInOrder();
    cout << "Bob's cards: \n";
    Bob.printInOrder();

    return 0;
/*
}
