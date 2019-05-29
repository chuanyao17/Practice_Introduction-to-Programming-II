#include <iostream>
#include <string>

using namespace std;
class Node{
public:
    char c;
    Node* left;
    Node* right;
    Node(const char &alph): c(alph),left(nullptr),right(nullptr){};
};
class alph{
public:
    Node *ptr;
    char c;
    int alphaCount;
};
class input{
public:
    int array[26];
    int count;
    string output[26];
    string s;
    alph bag[60];
    input(){
        int i;
        for(i=0;i<26;i++){
            array[i]=0;
        }
        count=0;
    }
    void save(string s){
        for(auto c:s){
            if(isalpha(c)){
                if(array[c-'a']==0){
                    bag[count++].c=c;
                }
                array[c-'a']++;
            }
        }
    }
    void insertionSort(){
        bag[0].alphaCount=array[bag[0].c-'a'];
        bag[0].ptr=new Node(bag[0].c);
        int i;
        for(i=1;i<count;i++){
            bag[i].alphaCount=array[bag[i].c-'a'];
            int tempC=bag[i].alphaCount;
            char tempA=bag[i].c;
            bag[i].ptr=new Node(tempA);
            Node* tempP=bag[i].ptr;
            insertion(tempC,tempA,tempP,i-1);
        }
    }
    void insertion(int temp,char a,Node* p, int j){
        while(j>=0){
            if(temp>=bag[j].alphaCount)break;
            else{
                bag[j+1].alphaCount=bag[j].alphaCount;
                bag[j+1].c=bag[j].c;
                bag[j+1].ptr=bag[j].ptr;
            }
            j--;
        }
        bag[j+1].alphaCount=temp;
        bag[j+1].c=a;
        bag[j+1].ptr=p;
    }
    Node* createTree(){
        int index=0;
        int total=(count-2)*2+3;
        while(index<=total-3){
            Node* c=new Node('#');
            c->left=bag[index].ptr;
            c->right=bag[index+1].ptr;
            int cplus=bag[index].alphaCount+bag[index+1].alphaCount;
            insertion(cplus,'#',c,count-1);
            count++;
            index+=2;
        }
        return bag[count-1].ptr;
    }
    void check(Node* temp){
        if(temp!=nullptr){
            if(isalpha(temp->c)){
                output[temp->c-'a']=s;
                return;
            }
            s.push_back('0');
            check(temp->left);
            s.pop_back();
            s.push_back('1');
            check(temp->right);
            s.pop_back();
        }
    }
    void printOutput(string s){
        for(auto c:s){
            cout<<output[c-'a'];
        }
    }
};

int main()
{
    int n;
    char coma;
    string word;
    string text;
    cin>>n>>coma>>word;
    cin.ignore();
    input a;
    for(int i=0;i<n;i++){
        getline(cin,text);
        a.save(text);
    }
    a.insertionSort();
    Node* root=a.createTree();
    a.check(root);
    a.printOutput(word);
    cout<<endl;
    return 0;
}
