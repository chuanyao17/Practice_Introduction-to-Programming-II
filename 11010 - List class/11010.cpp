#include <iostream>
#include <string>
#include <stdio.h>
#include "11010.h"
using namespace std;
int main()
{
    TWList integerList;
    int command;
    int value; // store node value

    while (cin >> command)
    {
        switch(command)
        {
        case 1: // insert at beginning
            cin >> value;
            integerList.insertAtFront(value);
            break;
        case 2: // insert at end
            cin >> value;
            integerList.insertAtBack(value);
            break;
        case 3: // remove from beginning
            integerList.removeFromFront();
            break;
        case 4: // remove from end
            integerList.removeFromBack();
            break;
        }
    }
    integerList.print();
    cout<<endl;
}
OWList::OWList(){
    firstPtr=nullptr;
    lastPtr=nullptr;
}
OWList::~OWList(){
    ListNode *temp=nullptr;
    while(firstPtr!=nullptr){
        temp=firstPtr;
        firstPtr=firstPtr->nextPtr;
        delete temp;
        temp=nullptr;
    }
}
void OWList::insertAtFront( const int &value ){
    ListNode *p=new ListNode(value);
    if(firstPtr==nullptr){
        firstPtr=p;
        lastPtr=p;
    }
    else{
        p->nextPtr=firstPtr;
        firstPtr=p;
    }
}
void OWList::removeFromFront(){
    if(firstPtr==nullptr);
    else if(firstPtr==lastPtr){
        delete firstPtr;
        firstPtr=nullptr;
        lastPtr=nullptr;
    }
    else{
        ListNode *temp=nullptr;
        temp=firstPtr;
        firstPtr=firstPtr->nextPtr;
        delete temp;
        temp=nullptr;
    }
}
bool OWList::isEmpty() const{
    if(firstPtr==nullptr)return true;
    else return false;
}
void OWList::print() const{
    if(firstPtr==nullptr)return;
    ListNode *temp=nullptr;
    temp=firstPtr;
    while(temp->nextPtr!=nullptr){
        cout<< temp->data <<" ";
        temp=temp->nextPtr;
    }
    cout << temp->data;
}
void TWList::insertAtBack( const int &value ){
    ListNode *p=new ListNode(value);
    if(firstPtr==nullptr){
        firstPtr=p;
        lastPtr=p;
    }
    else{
        lastPtr->nextPtr=p;
        lastPtr=p;
    }
}
void TWList::removeFromBack(){
    if(firstPtr==nullptr);
    else if(firstPtr==lastPtr){
        delete lastPtr;
        firstPtr=nullptr;
        lastPtr=nullptr;
    }
    else{
        ListNode *temp=nullptr;
        temp=firstPtr;
        while(temp->nextPtr!=lastPtr){
            temp=temp->nextPtr;
        }
        delete temp->nextPtr;
        temp->nextPtr=nullptr;
        lastPtr=temp;
    }
}
