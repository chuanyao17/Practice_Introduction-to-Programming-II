
#ifndef function_h
#define function_h

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class ListNode{
    friend class List_BST; //make List_BST a friend

public:
    ListNode(const int &info):key( info ),left( NULL ),right( NULL ) //constructor
    {
    }//end ListNode constructor

private:
    int key;
    ListNode *left;
    ListNode *right;
};

class BST{
public:
    BST():Height(0){}
    virtual ~BST() {}
    virtual void insert(const int &) = 0;
    virtual void remove(const int &) = 0;
    virtual bool search(const int &) const = 0;
    virtual void print()  = 0;
    virtual int height2() = 0;
    //virtual int height() const { return Height; }// An empty tree has height of 0. A tree with only root node has height of 1.

    int Height;
};

//end class ListNode

class List_BST : public BST{
public:
    List_BST();
    virtual ~List_BST()
    {
        deleteTree(root);
    }
    virtual void insert(const int &) override;
    virtual void remove(const int &) override;
    virtual bool search(const int &) const override;
    virtual void print() override{
        int i;
        Height = calculateH(root);
        //printf("h=%d\n",Height);
        for(i = 1; i <= Height; i++){
            printGivenLevel(root, i);
        }
    }
    virtual int height2() {
        Height = calculateH(root);
        return Height;
    }

private:
    ListNode *root;
    // private member functions
    ListNode* createLeaf(int key) const; //new a ListNode and return its address
    /* clean a tree.*/
    void deleteTree(ListNode *root){};

    void printGivenLevel(ListNode* Ptr, int level) const {
        if (Ptr == NULL)
            return;
        if (level == 1)
            cout << Ptr->key << " ";
        else if (level > 1)
        {
            printGivenLevel(Ptr->left, level-1);
            printGivenLevel(Ptr->right, level-1);
        }
    }
    int calculateH(ListNode* root)const{
        if (root==nullptr){
            return 0;
        }
        else{
            //printf("root=%d\n",root->key);
            int ldepth = calculateH(root->left);
            int rdepth = calculateH(root->right);
            if(ldepth>rdepth) return(ldepth+1);
            else return(rdepth+1);
        }
    }
};

#endif /* function_h */
