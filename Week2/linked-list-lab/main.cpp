#include <iostream>
#include <string>
#include "linkedList.hpp"

using namespace std;

int main(){
    LinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    list.traverse();
    int pos = list.search(30);
    if (pos == -1) cout << "Target value not found! or List is empty!\n";
    else cout << "\nPosition of Target value is : " << pos << endl;
}
