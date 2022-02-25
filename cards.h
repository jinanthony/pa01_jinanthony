//cards.h
//Authors: ANTHONY JIN
//All class declarations and some functions

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
using namespace std;

class Card {
    private:
        //s is suit
        string s;

        //i is int associated with the card
        int i;

    public:
        
        Card(string suit = "none", int value = 0): s(suit), i(value) {
        }
    
        string getS() const {
            return s;
        }
        
        int getI() const {
            return i;
        }

        void setS(string suit){
            s = suit;
        }

        void setI(int value){
            i = value;
        }

        void print(){
            cout << s << " ";
            if (i == 1){
                cout << "a" << endl;
            }
            else if (i == 11){
                cout << "j" << endl;
            }
            else if (i == 12){
                cout << "q" << endl;
            }
            else if (i == 13){
                cout << "k" << endl;
            }
            else{
                cout << i << endl;
            }
        }

        bool operator>=(Card c);
        
        bool operator>(Card c);
        
        bool operator==(Card c);
};

class BST {
    public:
        BST();
        ~BST();
        void insert(Card c);
        void remove(Card c);
        Card successor(Card c);
        Card predecessor(Card c);
        void printInOrder();
        void printPreOrder();
        bool cardExists(Card c);
        Card gameTurnMin(BST& hand);
        Card gameTurnMax(BST& hand);

    private:
        struct Node {
            Card c;
            Node *left;
            Node *right;
            Node *parent;
            
            Node() {
                c = Card();
                left = nullptr;
                right = nullptr;
                parent = nullptr;
            }

            Node(Card c): c(c), left(nullptr), right(nullptr), parent(nullptr){
            }
        };

        Node *root;

        void clear (Node *n);
        void printInOrderNode(Node *n);
        void printPreOrderNode(Node *n);
        Node* findNode(Card c, Node *n);
        Node* successorNode(Card c);
        Node* predecessorNode(Card c);
};

#endif
