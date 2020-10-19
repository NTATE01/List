/*
 _ _    _  _________
| \ \  | ||___   ___|
| |\ \ | |    | |      Nathan Tate, 
| | \ \| |    | |      IU Southeast, 2023
| |  \ \ |    | |      https://github.com/ntate01
|_|   \__|    |_|
*/
#pragma once
#include <iostream>
#include "Sequence.h"
using namespace std;

template <class T>
Sequence<T>::Sequence()
{
    head = NULL;
    size = 0;
}// Sequence

template <class T>
Sequence<T>::~Sequence()
{
    reclaimAllNodes(head);
}    // ~Sequence

template <class T>
void Sequence<T>::clear(void)
{
    reclaimAllNodes(head);
    head = NULL;
    size = 0;
} // clear

template <class T>
void Sequence<T>::reclaimAllNodes(NodeRecord*& initialP)
// requires: Null(initialP)  or  Alive(initialP)
//  ensures: all nodes in linked list beginning with initialP are reclaimed
{
    if (initialP != NULL) {
        reclaimAllNodes(initialP->next);
        delete (initialP);
    } // end if
} // reclaimAllNodes

// You are required to implement add, remove, entry, length, and outputSequence functions here.
template <class T>
void Sequence<T> ::add(T& x, int pos) {
    //cout << "\n entering add function";
    if (pos > size)
        cout << "\nInvalid position entered \n";
    else {
        if (pos == 0) {
            NodeRecord* temp = new NodeRecord;
            temp->next = head;
            head = temp;
            head->value = x;
        }//If Statement
        else {
            NodeRecord* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }//For Statement
            NodeRecord* var = new NodeRecord;
            var->next = current->next;
            current->next = var;
            var->value = x;
        }// else
    size++;
    }// else
}// add


template <class T>
void Sequence<T>::remove(T& x, int pos) {
    if (pos >= size) {
        cout << "Enter valid position, position " << pos << " is invalid";
    }// if
    else {
        if (pos == 0) {
            NodeRecord* temp = head;
            head = head->next;
        }// if
        else {
            NodeRecord* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }// for 
            NodeRecord* temp = current->next;
            current->next = temp->next;
            x = temp->value;
            delete temp;
        }// else
        size--;
    }//else
}// remove


template <class T>
T& Sequence<T>::entry(int pos) {
    if (pos >= size) {
        T x;
        return x;
    }// if
    else {
        NodeRecord* current = head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }// for
        return current->value;
    }// else
}// entry

template <class T>
int Sequence<T>::length(void) {
    return size;
}// length 

template <class T>
void Sequence <T> ::outputSequence(void) {
    if (size == 0) {
        cout << "<>";
    }//if 
    else {
        NodeRecord* current = head;
        cout << "<";
        while (current != NULL) {
            if(current->next == NULL){
                cout << current->value;
                current = current->next;
            }
            else{
            cout << current->value;
            cout << ",";
            current = current->next;
            }// else
        }// while
    cout << ">";
    }// else
}// outputSequence

template <class T>
void Sequence<T>::transferFrom(Sequence& source) {
    T temp;
    clear(); //clears self
    for (int i = 0; i < source.length(); i++)//traverses source
    {
        temp = source.entry(i);
        add(temp, length());//adds source elements to self
    }
    source.clear();//clears source
}// transferFrom 

template <class T>
Sequence<T>& Sequence<T>::operator=(Sequence& rhs) {
    clear();//clears self
    for (int i = 0; i < rhs.length(); i++)//traverses ehs
    {
        add(rhs.entry(i), length());//adds elements from rhs to self
    }
    return (*this);//returns self = rhs
}// operator =
