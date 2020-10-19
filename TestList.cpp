/*
 _ _    _  _________
| \ \  | ||___   ___|
| |\ \ | |    | |      Nathan Tate, 
| | \ \| |    | |      IU Southeast, 2023
| |  \ \ |    | |      https://github.com/ntate01
|_|   \__|    |_|
*/
#include "List.hpp"
using namespace std;

int main(){
    List<int> list1;
    List<int> list2; 

    cout << "main() method OUTPUT\n";
    cout << "\n---------------TESTING addRightFront---------------\n";
    int x = 1;
    cout << "Adding 1 to right front of list1 \n";
    list1.addRightFront(x);
    list1.outputList(); cout <<"\n";
    x = 3;
    cout << "Adding 3 to right front of list1 \n";
    list1.addRightFront(x);
    list1.outputList(); cout <<"\n";
    cout << "\n---------------TESTING outputList---------------\n";
    cout << "list 1 = "; list1.outputList(); cout << "\n";


    cout << "\n---------------TESTING removeRightFront---------------\n";
    x = 5; 
    cout << "Adding 5 to right front  of list1\n";
    list1.addRightFront(x);
    list1.outputList(); cout << "\n";
    cout << "Removing 5 from right front of list\n";
    list1.removeRightFront(x);
    list1.outputList(); cout << "\n";

    cout << "\n---------------TESTING rightFront---------------\n";
    cout << "list 1 = "; list1.outputList(); cout << "\n";
    cout << "rightFront of list1 is " << list1.rightFront(); cout << "\n";

    cout << "\n--------------- TESTING rightLength and leftLength because they are so similar---------------\n";
    cout << "list1 = "; list1.outputList(); cout << "\n";
    cout << "Adding 5 to frontRight\n";
    list1.addRightFront(x);
    list1.outputList(); cout << "\n";
    list1.advance();
    list1.outputList(); cout << "\n";
    list1.advance();
    cout << "Advanced fence post twice\n";
    cout << "Now list1 = "; list1.outputList(); cout << "\n";
    cout << "leftLength is " << list1.leftLength(); cout << "\n";
    cout << "rightLength is " << list1.rightLength(); cout << "\n";

    cout << "\n---------------TESTING swapRights---------------\n";
    cout << "list1 = "; list1.outputList(); cout << "\n";
    int y = 2; 
    list2.addRightFront(y);
    y = 4;
    list2.addRightFront(y);
    cout << "list2 = "; list2.outputList(); cout << "\n";
    list1.swapRights(list2);
    cout << "list1 = "; list1.outputList(); cout << "\n";
    cout << "list2 = "; list2.outputList(); cout << "\n";

    cout << "\n---------------TESTING advance---------------\n";
    cout << "list1 = "; list1.outputList(); cout << "\n";
    list1.advance(); cout << "advance()\n";
    cout << "list1 = "; list1.outputList(); cout << "\n";
    list1.advance(); cout << "advance()\n";
    cout << "list1 = "; list1.outputList(); cout << "\n";

    cout << "\n---------------TESTING moveToStart---------------\n";
    list1.clear();
    x = 1;
    list1.addRightFront(x);
    //x = 2; 
    //list1.addRightFront(x);
    cout << "list1 = "; list1.outputList(); cout << "\n";
    cout << "Advance()\n";
    list1.advance();
    cout << "list1 = "; list1.outputList(); cout << "\n";
    cout << "Move back to start";
    list1.moveToStart();
    cout << "list1 = "; list1.outputList(); cout << "\n";
    
    cout << "\n---------------TESTING moveToFinish---------------\n";
    cout << "list1 = "; list1.outputList(); cout << "\n";
    list1.moveToFinish();
    cout << "Move to Finish\n";
    cout << "list1 = "; list1.outputList(); cout << "\n";

    cout << "\n---------------TESTING transferFrom---------------\n";
    list1.clear(); list2.clear();
    x = 1; list1.addRightFront(x); x = 2; list1.addRightFront(x); x = 3; list1.addRightFront(x);
    list1.advance();
    list1.advance();
    cout << "list1 = "; list1.outputList(); cout << "\n";
    x = 6; list2.addRightFront(x); x = 7; list2.addRightFront(x); x = 8; list2.addRightFront(x);
    list2.advance();
    cout << "list2 = "; list2.outputList(); cout << "\n";
    cout << "Transfer contents from list1 to list2\n";
    list2.transferFrom(list1);
    cout << "list1 = "; list1.outputList(); cout << "\n";
    cout << "list2 = "; list2.outputList(); cout << "\n";

    cout << "\n---------------TESTING operator=---------------\n";
    list1.clear();
    list2.clear();
    x = 1; list1.addRightFront(x); x = 2; list1.addRightFront(x); x = 3; list1.addRightFront(x);
    cout << "list1 = "; list1.outputList(); cout << "\n";
    x = 6; list2.addRightFront(x); x = 7; list2.addRightFront(x); x = 8; list2.addRightFront(x);
    cout << "list2 = "; list2.outputList(); cout << "\n";
    list2 = list1;
    cout << "list2 = list1\n";
    cout << "list1 = "; list1.outputList(); cout << "\n";
    cout << "list2 = "; list2.outputList(); cout << "\n";
    list2.clear();
    
    cout << "\n---------------TESTING replaceRightFront---------------\n";
    cout << "list1 = "; list1.outputList(); cout << "\n";
    int num = 100;
    cout << "Replace Right Front with num = 100\n";
    list1.replaceRightFront(num);
    cout << "list1 = "; list1.outputList(); cout << "\n";

    return 0; 
}// main