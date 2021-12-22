#include <iostream>
#include <iostream>
using namespace std;


class LinkedList;
class SuffixTrieNode{
private:
    char key;
    int index;
    LinkedList *children;


public:
    SuffixTrieNode();
    SuffixTrieNode(char c); // Paramtrized constructor
    void setKey(char c); // set key of a node
    char getKey()const; // get the key of a node
    SuffixTrieNode *createNode(char c); // create suffix trie node
    LinkedList* getChildren();


};

SuffixTrieNode::SuffixTrieNode(char c) {
    this->key = c;
    this->children = nullptr;
    //index = 0;
}

void SuffixTrieNode::setKey(char c) {
    this->key = c;
}

char  SuffixTrieNode::getKey() const {
    return this->key;
}
SuffixTrieNode* SuffixTrieNode::createNode(char c) {
    SuffixTrieNode *newNode = new SuffixTrieNode(c);
    return  newNode;
}

LinkedList* SuffixTrieNode::getChildren()
{
    return children;
}

class Node{
public:
    SuffixTrieNode *key;
    Node *next;
    Node(){
        key = nullptr;
        next = nullptr;
    }
    Node(char c)
    {
        this->key = new SuffixTrieNode(c) ;
    }
};


//struct Node{
//
//
//};

class LinkedList{
private:
    Node* head ,* tail;

public:
    LinkedList()
    {
        this->head=nullptr;
        this->tail=nullptr;
    }



    void push_back(char c)
    {
        Node*tmp=new Node();
        tmp->key = new SuffixTrieNode(c);
        tmp->next=nullptr;
        if(this->head==nullptr)
        {
            this->head=tmp;
            this->tail=tmp;
            tmp=nullptr;
        }
        else
        {
            this->tail->next=tmp;
            this->tail=tmp;
        }

    }
    void printList()
    {
        Node *tmp= this->head;
        while (tmp != this->tail)
        {
            cout<<tmp->key->getKey();
            tmp=tmp->next;
        }
        cout<<tmp->key->getKey();
        cout<<endl;
    }
};

//class trieNode
//{
//public:
//    LinkedList *list;
//    int index;
//
//    trieNode()
//    {
//        list=new LinkedList();
//        index = 0;
//    }
//
//};





int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
