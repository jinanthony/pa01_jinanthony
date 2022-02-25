//cards.cpp
//Authors: ANTHONY JIN
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>
using namespace std;

//c is card
//s is suit

bool Card::operator>(Card c){
    
    //suit char that will be compared to each other
    string s1;
    string s2;

    //every character representation of suit is in order from least to greatest ASCII value other than h
    //we set h to equal t (t > s) so that when compared they remain in order 
    if (s == "h") {
        s1 = "t";
    }
    else{
        s1 = s;
    }
    if (c.s == "h"){
        s2 = "t";
    }
    else{
        s2 = c.s;
    }

    //card comparison
    if (s1 > s2){
        return true;
    }
    else if (s1 == s2 && i > c.i){
        return true;
    }
    else{
        return false;
    }
}

bool Card::operator==(Card c){
    //same first part as above

    string s1;
    string s2;

    if (s == "h"){
        s1 = "t";
    }
    else{
        s1 = s;
    }
    if (c.s == "h"){
        s2 = "t";
    }
    else{
        s2 = c.s;
    }

    //card comparison
    if (s1 == s2 && i == c.i){
        return true;
    }
    return false;
}

bool Card::operator>=(Card c){
    //if == is true or > is true then >= must be true
    if (this>c || this==c){
        return true;
    }
    return false;
}
        
//BST functions
BST::BST():root(nullptr){
}

void BST::clear(Node*n){
    if (n){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

void BST::insert(Card c){
    Node* insert = new Node(c);
    if (!root) {
        root = insert;
        return;
    }
    Node* n = root;
    while (n) {
        if (n->c >= c){
            if (n->left == nullptr){
                n->left = insert;
                insert->parent = n;
                return;
            }
            else{
                n = n->left;
            }
        }
        else{
            if (n->right == nullptr){
                n->right = insert;
                insert->parent = n;
                return;
            }
            else{
                n = n->right;
            }
        }
    }
}

void BST::printInOrderNode(Node* n){
    if (!n){
        return;
    }
    printInOrderNode(n->left);
    n->c.print();
    printInOrderNode(n->right);
}

void BST::printInOrder(){
    printInOrderNode(root);
}

BST::Node* BST::findNode(Card c, Node* n){
    if (!n){
        return nullptr;
    }
    else if (n->c == c){
        return n;
    }
    else if (n->c >= c){
        return findNode(c, n->left);
    }
    else{
        return findNode(c, n->right);
    }
}

bool BST::cardExists(Card c){
    if (findNode(c, root) == nullptr){
        return false;
    }
    return true;
}


BST::Node* BST::predecessorNode(Card c){
    Node *n = findNode(c, root);
    if (!n){
        return nullptr;
    }
    if (n->left){
        n = n->left;
        while (n->right){
            n = n->right;
        }
        return n;
    }
    else{
        while (n->parent && n->c >= c){
            n = n->parent;
        }
        if (n == root && n->c >= c){
            return nullptr;
        }
        return n;
    }
}

Card BST::predecessor(Card c){
    Node *n = predecessorNode(c);
    if (!n){
        return Card();
    }
    else{
        return n->c;
    }
}

BST::Node* BST::successorNode(Card c){
    Node* n = findNode(c, root);
    if (n->right){
        n = n->right;
        while (n->left){
            n = n->left;
        }
        return n;
    }
    else{
        while (n->parent && !(n->c > c)){
            n = n->parent;
        }
        if (n == root && !(n->c > c)){
            return nullptr;
        }
        return n;
    }
}

Card BST::successor(Card c){
    Node *n = successorNode(c);
    if (!n){
        return Card();
    }
    else{
        return n->c;
    }
}

void BST::remove(Card c){
    Node* n = findNode(c, root);
    if (n == nullptr){
        return;
    }
    if (n->left == nullptr && n->right == nullptr){
        if (n->parent){
            if (n->parent->left == n){
                n->parent->left = nullptr;
                delete n;
            }
            else {
                n->parent->right = nullptr;
                delete n;
            }
        }
        else {
            delete n;
            root = nullptr;
        }
        return;
    }
    else if (n->left && !n->right) {
        if (!n->parent) {
            root = n->left;
            root->parent = nullptr;
            delete n;
        }
        else if (n->parent->left == n) {
            n->parent->left = n->left;
            n->left->parent = n->parent;
            delete n;
        }
        else {
            n->parent->right = n->left;
            n->left->parent = n->parent;
            delete n;
        }
        return;
    }
    else if (n->right && !n->left) {
        if (!n->parent) {
            root = n->right;
            root->parent = nullptr;
            delete n;
        }
        else if (n->parent->left == n) {
            n->parent->left = n->right;
            n->right->parent = n->parent;
            delete n;
        }
        else {
            n->parent->right = n->right;
            n->right->parent = n->parent;
            delete n;
        }
        return;
    }
    else {
        Node* p = successorNode(c);
        n->c = p->c;
        if (!p->left && !p->right) {
            if (p->parent->right == p) {
                p->parent->right = nullptr;
            }
            else {
                p->parent->left = nullptr;
            }
            delete p;
        }
        else if (!p->left && p->right) {
            if (p->parent->right == p) {
                p->parent->right = p->right;
                p->right->parent = p->parent;
            }
            else {
                p->parent->left = p->right;
                p->right->parent = p->parent;
            }
            delete p;
        }
    return;
    }
}

Card BST::gameTurnMin(BST& hand2) {
    Node* n = root;
    Card c;
    Card empty;
    if (!n){
        return empty;
    }
    while (n->left) {
        n = n->left;
    }
    while (n) {
        c = n->c;
        if (hand2.cardExists(c)) {
            hand2.remove(c);
            this->remove(c);
            return c;
        }
    
        n = this->successorNode(c);
    }
    return empty;
}

Card BST::gameTurnMax(BST& hand2) {
        Node* n = root;
            Card c;
                Card empty;
    if (!n){
        return empty;
    }
    while (n->right) {
        n = n->right;
    }
    while (n) {
        c = n->c;
        if (hand2.cardExists(c)) {
            hand2.remove(c);
            this->remove(c);
            return c;
        }
        n = this->predecessorNode(c);
    }
    return empty;
}



    




            
