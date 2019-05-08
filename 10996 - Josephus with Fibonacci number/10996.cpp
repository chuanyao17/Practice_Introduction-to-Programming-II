#include <iostream>
#include<stdio.h>
#include "10996.h"
using namespace std;
int main(){
	int numofpeople;

	while(cin>>numofpeople){
		Josephus Jose(numofpeople);
		int survival = Jose.kill();
		cout<<survival<<endl;
    }
}
Josephus::Josephus(){
    head=nullptr;
    noOfPeople=0;
}
Josephus::~Josephus(){
    Node* temp=nullptr;
    Node* cur=nullptr;
    temp=head->next;
    while(temp!=head){
        cur=temp;
        temp=temp->next;
        delete cur;
        cur=nullptr;
    }
    delete head;
    head=nullptr;
}
Josephus::Josephus(const int &num){
    head=nullptr;
    noOfPeople=num;

}
void Josephus::generatecircularlinkedList(const int &num){
    int Count=1;
    Node* tail=nullptr;
    while(Count<=num){
        if(head==nullptr){
            Node* p=new Node(Count++);
            tail=p;
            head=p;
        }
        else{
            tail->next=new Node(Count++);
            tail=tail->next;
        }
    }
    tail->next=head;
}
int Josephus::kill(){
    Node* temp=nullptr;
    generatecircularlinkedList(noOfPeople);
    generateFib(noOfPeople);
    Node* cur=head;
    int moving;
    int i=0;
    while(noOfPeople>1){
        moving=sequence[i++];
        while(moving>0){
            temp=cur;
            while(cur->next->number==9999){
                cur=cur->next;
            }
            cur=cur->next;

            moving--;
        }
        temp->number=9999;
        noOfPeople--;
    }
    return cur->number;
}
void Josephus::generateFib(const int &num){
    int i;
    sequence[0]=1;
    sequence[1]=1;
    for(i=2;i<=num;i++){
        sequence[i]=sequence[i-2]+sequence[i-1];
    }
}
