/*
 _ _    _  _________
| \ \  | ||___   ___|
| |\ \ | |    | |      Nathan Tate, 
| | \ \| |    | |      IU Southeast, 2023
| |  \ \ |    | |      https://github.com/ntate01
|_|   \__|    |_|
*/
#pragma once 
#include "List.h"
#include <iostream>
using namespace std; 

template <class T>
List<T>::List(){
}// List Constructor

template <class T>
List<T>::~List(){
}// List Deconstructor

template <class T>
void List<T>::clear(void){
    left.clear();
    right.clear();
}// clear

template <class T>
void List<T>::outputList(){
    cout << "(";
    left.outputSequence();
    cout << "|";
    right.outputSequence();
    cout << ")";
}

template <class T>
void List<T>::transferFrom (List& source){
    left.transferFrom(source.left);
    right.transferFrom(source.right);
    source.clear();
}// transferFrom

template <class T>
List<T>& List<T>::operator= (List& rhs){
    left.operator = (rhs.left);
    right.operator = (rhs.right);
    return (*this);
}// operator = 

template <class T>
void List<T>::moveToStart (void){
    // Takes all entries from left and appends to beginning of right intput (<1,2,3>|<4,5,6>) output (<>|<1,2,3,4,5,6>)
    for(int i = 0; i < left.length(); i++){
        right.add(left.entry(i), i);
        left.remove(left.entry(i), i);
    }// for
}// moveToStart

template <class T>
void List<T>::moveToFinish (void){
    for(int i = 0; i < right.length(); i++){
        left.add(right.entry(i),left.length());
        right.remove(right.entry(i),i);
    } // for 
}// moveToFinish

template <class T>
void List<T>::advance (void){
    if (right.length() == 0) {
        cout << "Right is empty\n";
    }// if 
    else {
        int x = right.entry(0);
        right.remove(x, 0);
        left.add(x, left.length());
    }//ELSE STATMENT
}// advance

template <class T>
void List<T>::addRightFront (T& x){
    right.add(x, 0);
}// addRightFront

template <class T>
void List<T>::removeRightFront (T& x){
    right.remove(x, 0);
}// removeRightFront

template <class T>
T& List<T>::rightFront (void){
    return right.entry(0);
}// rightFront

template <class T>
void List<T>::replaceRightFront (T& x){
    if (right.length() != 0) {
        T temp = x;
        right.remove(x, 0);
        right.add(temp, 0);
    }//IF STATEMENT
}// replaceRightFront

template <class T>
void List<T>::swapRights (List& otherS){
    Sequence<T> temp;
    temp = right;
    right = otherS.right;
    otherS.right = temp;
    temp.clear();
}// swapRights

template <class T>
int List<T>::leftLength (void){
    return left.length();
}// leftLength

template <class T>
int List<T>::rightLength (void){
    return right.length();
}// rightLength