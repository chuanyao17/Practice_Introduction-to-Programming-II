#include <iostream>
#include <string.h>
#include <stdio.h>
#include "11020.h"
using namespace std;

void BSTManipulator(BST& bstobj1,BST& bstobj2, char cmd ){
    int n;
    if (cmd == 'I') {
        cin >> n;
        bstobj1.insert(n);
        bstobj2.insert(n);
    }else if (cmd == 'S'){
        cin >> n;
        if (bstobj1.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

        if (bstobj2.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

    }else if (cmd == 'H'){
        cout << bstobj1.height() << endl;;
        cout << bstobj2.height() << endl;;

    }else if (cmd == 'P'){
        bstobj1.print();
        cout << endl;
        bstobj2.print();
        cout << endl;
    }
}
int main(){
    Array_BST A_bst;
    List_BST B_bst;
    char cmd;

    while (cin >> cmd)
        BSTManipulator(A_bst, B_bst, cmd);

    return 0;
}
Array_BST::Array_BST(){
    int i=0;
    for(i=0;i<1025;i++){
        array[i]=0;
    }
}
void Array_BST::insert(const int &data){
    int h=1;
    if(array[1]==0){
        array[1]=data;
        Height=1;
    }
    else{
        int i=1;
        while(array[i]!=0){
            if(data==array[i])break;
            else if(data<array[i]){
                i=2*i;
                h++;
            }
            else if(data>array[i]){
                i=2*i+1;
                h++;
            }
        }
        array[i]=data;
        if(h>Height)Height=h;
    }
}
bool Array_BST::search(const int &data)const{
    if(array[1]==0)return false;
    int i=1;
    while(array[i]!=0){
        if(data==array[i])return true;
        else if(data<array[i])i=2*i;
        else i=i*2+1;
    }
    return false;
}
List_BST::List_BST(){
    root=nullptr;
}
void List_BST::insert(const int &data){
    int h=1;
    ListNode *p=createLeaf(data);
    if(root==nullptr){
        root=p;
        Height=1;
    }
    else{
        ListNode* temp=root;
        while(temp!=nullptr){
            if(data==temp->key) break;
            else if(data<temp->key && temp->left==nullptr){
                temp->left=p;
                h++;
                break;
            }
            else if(data>temp->key && temp->right==nullptr){
                temp->right=p;
                h++;
                break;
            }
            else if(data<temp->key){
                temp=temp->left;
                h++;
            }
            else if(data>temp->key){
                temp=temp->right;
                h++;
            }
        }
        if(h>Height){
            Height=h;
        }
    }
}
bool List_BST::search(const int &data)const{
    if(root==nullptr)return false;
    ListNode *temp=root;
    while(temp!=nullptr){
        if(data==temp->key)return true;
        else if(data<temp->key)temp=temp->left;
        else if(data>temp->key)temp=temp->right;
    }
    return false;
}
ListNode* List_BST::createLeaf(int key) const{
    ListNode* p=new ListNode(key);
    return p;
}
void List_BST::deleteTree(ListNode *root){
    if(root!=nullptr){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root=nullptr;
    }
}
