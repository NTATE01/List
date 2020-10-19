/*
 _ _    _  _________
| \ \  | ||___   ___|
| |\ \ | |    | |      Nathan Tate, 
| | \ \| |    | |      IU Southeast, 2023
| |  \ \ |    | |      https://github.com/ntate01
|_|   \__|    |_|
*/
#pragma once
#include "Sequence.hpp"
using namespace std;

template <class T>
class List{
//! is modeled by (
//! left: string of T
//! right: string of T
//! )
//! exemplar self
public:
// Standard Operations
List();
//! replaces self
//! ensures: self = (<>,<>)
// IMPLEMENTED IN LIST.HPP
// TESTED IN TESTLIST.CPP
~List();
void outputList(void);
// restores: self
// IMPLEMENTED IN LIST.HPP
void clear (void);
//! clears self
// IMPLEMENTED IN LIST.HPP
void transferFrom (List& source);
//! replaces self
//! clears source
//! ensures: self = #source
// IMPLEMENTED IN LIST.HPP
List& operator = (List& rhs);
//! replaces self
//! restores rhs
//! ensures: self = rhs
// List Specific Operations
// IMPLEMENTED IN LIST.HPP
void moveToStart (void);
//! updates self
//! ensures: self = (<>,#self.left * #self.right)
// IMPLEMENTED IN LIST.HPP
void moveToFinish (void);
//! updates self
//! ensures: self = (#self.left * #self.right,<>)
// IMPLEMENTED IN LIST.HPP
void advance (void);
//! updates self
//! requires: self.right /= <>
//! ensures: self.left * self.right = #self.left *
//! #self.right and |self.left| = |#self.left| + 1
// IMPLEMENTED IN LIST.HPP
void addRightFront (T& x);
//! updates self.right
//! clears x
//! ensures: self = (#self.left,<#x> * #self.right)
// IMPLEMENTED IN LIST.HPP
// TESTED IN TESTLIST.CPP
void removeRightFront (T& x);
//! updates self.right
//! replaces x
//! requires: self.right /= <>
//! ensures: <x> is prefix of #self.right and
//! self = (#self.left,#self.right[1,|#self.right|))
// IMPLEMENTED IN LIST.HPP
// TESTED IN TESTLIST.CPP
T& rightFront (void);
//! restores self
//! requires: self.right /= <>
//! ensures: <rightFront> is prefix of self.right
// IMPLEMENTED IN LIST.HPP
// TESTED IN TESTLIST.CPP
void replaceRightFront (T& x);
//! updates self.right, x
//! requires: self.right /= <>
//! ensures: <x> is prefix of #self.right and
//! self = (#self.left,<#x> * #self.right[1,|#self.right|))
// IMPLEMENTED IN LIST.HPP
void swapRights (List& otherS);
//! updates self.right, otherS.right
//! ensures: self = (#self.left,#otherS.right) and
//! otherS = (#otherS.left,#self.right)
// IMPLEMENTED IN LIST.HPP
// TESTED IN TESTLIST.CPP
int leftLength (void);
//! restores self
//! ensures: leftLength = |self.left|
// IMPLEMENTED IN LIST.HPP
// TESTED IN TESTLIST.CPPw
int rightLength (void);
//! restores self
//! ensures: rightLength = |self.right|
// IMPLEMENTED IN LIST.HPP
// TESTED IN TESTLIST.CPP
private: // representation
    Sequence<T> left, right;
    int size = 0;
};