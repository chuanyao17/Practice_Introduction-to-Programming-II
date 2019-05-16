#include <iostream>
#include <string.h>
#include "12259.h"
#include <stdio.h>
using namespace std;

void BSTManipulator(BST& bstobj2, char cmd ){
    int n;
    if (cmd == 'I') {
        cin >> n;
        bstobj2.insert(n);
    }else if (cmd == 'S'){
        cin >> n;
        if (bstobj2.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

    }else if (cmd == 'H'){
        cout << bstobj2.height2() << endl;;

    }else if (cmd == 'P'){
        bstobj2.print();
        cout << endl;
    }else if (cmd == 'R'){
        cin >> n;
        bstobj2.remove(n);
    }
}
int main(){
    List_BST B_bst;
    char cmd;

    while (cin >> cmd)
        BSTManipulator(B_bst, cmd);

    return 0;
}
List_BST::List_BST(){
    root=nullptr;
}
void List_BST::insert(const int &data){
    ListNode *p=createLeaf(data);
    if(root==nullptr){
        root=p;
    }
    else{
        ListNode* temp=root;
        while(temp!=nullptr){
            if(data==temp->key) break;
            else if(data<temp->key && temp->left==nullptr){
                temp->left=p;
                break;
            }
            else if(data>temp->key && temp->right==nullptr){
                temp->right=p;
                break;
            }
            else if(data<temp->key){
                temp=temp->left;
            }
            else if(data>temp->key){
                temp=temp->right;
            }
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
void List_BST::remove(const int &data){
    if(root==nullptr)return;
    ListNode *temp=root;
    ListNode *parent=root;
    ListNode *mini=nullptr;
    while(temp!=nullptr){
        if(data==temp->key){
            break;
        }
        else if(data<temp->key){
            parent=temp;
            temp=temp->left;
        }
        else if(data>temp->key){
            parent=temp;
            temp=temp->right;
        }
    }
    if(temp==nullptr)return;
    if(temp->left==nullptr && temp->right==nullptr){
        if(parent->right!=nullptr && parent->right->key==temp->key){
            parent->right=nullptr;
            delete temp;
            temp=nullptr;
        }
        else if(parent->left!=nullptr && parent->left->key==temp->key){
            parent->left=nullptr;
            delete temp;
            temp=nullptr;
        }
    }
    else if(temp->left!=nullptr && temp->right!=nullptr){
        mini=temp->right;
        if(mini->left==nullptr){
            temp->key=mini->key;
            temp->right=mini->right;
        }
        else{
            while(mini->left!=nullptr){
                parent=mini;
                mini=mini->left;
            }
            temp->key=mini->key;
            if(mini->right!=nullptr){
                parent->left=mini->right;
                delete mini;
                mini=nullptr;
            }
            else{
                parent->left=nullptr;
                delete mini;
                mini=nullptr;
            }
        }

    }
    else if(temp->left!=nullptr){
        if(parent->left!=nullptr && parent->left->key==temp->key){
            parent->left=temp->left;
        }
        else if(parent->right!=nullptr && parent->right->key==temp->key){
            parent->right=temp->left;
        }
        delete temp;
        temp=nullptr;
    }
    else{
        if(parent->left!=nullptr &&temp->key==parent->left->key){
            parent->left=temp->right;
        }
        else if(parent->right!=nullptr &&parent->right->key==temp->key){
            parent->right=temp->right;
        }
        delete temp;
        temp=nullptr;
    }
}
