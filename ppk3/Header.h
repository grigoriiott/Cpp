//
//  Header.h
//  ppk3
//
//  Created by Григорий Отт on 12.05.2021.
//
#include <iostream>
#include <string.h>

using namespace std;

class Container{
protected:
    virtual void Add(int n)=0;
    virtual void GetWhole( )=0;
    virtual void GetOne(int n)=0;
    virtual void Delete(int n)=0;
};
template <typename T>
class Spisok1:public Container
{
public:
    Spisok1(){
        
    }
    ~Spisok1(){
        for (int i=0; i<size;i++){
            Delete(i);
        }
    }
private:
    int size=0;
    struct Node{
        T Data;
        Node* NextNode;
    };
    Node* Head=nullptr;
public:
    void Add(int n) override {
        int i=0;
        T Data;
        size++;
        cin >> Data;
        Node* Current = Head;
        if (Current==nullptr){
            Current=new Node;
            Head= Current;
            Current->NextNode=nullptr;
            Current->Data=Data;
        }
        else {
        while((i<n)&&(Current->NextNode!=nullptr)){
            i++;
            Current=Current->NextNode;
        }
        Node* NewOneEl = new Node;
        NewOneEl->NextNode=Current->NextNode;
        NewOneEl->Data=Data;
        Current->NextNode=NewOneEl;
        }
    }
    void GetWhole() override{
        Node* Current=Head;
        if (Current==nullptr){
            cout << "Spisok pust"<< endl;
        }
        while (Current!=nullptr){
            cout.width(4);
            cout << Current->Data;
            Current=Current->NextNode;
        }
        cout <<endl;
    }
    void GetOne (int n) override{
        if (n>=size){
            cout << "V spiske net stolko"<<endl;
        }
        else {
            int i=0;
            Node* Current = Head;
        while (i!=n){
            Current=Current->NextNode;
            i++;
        }
        cout << Current->Data << endl;
        }
    }
    void Delete (int n) override{
        if (n>=size){
            cout << "Error!" << endl;
        }
        else {
        int i=0;
        bool f= 0;
        Node* Current = Head;
        if (n==0){
            Head=Current->NextNode;
            delete Current;
            size--;
        } else {
        while(!f){
            if (Current->NextNode==nullptr){
                f=1;
            }
            if (i==n-1){
                break;
            }
            Current=Current->NextNode;
            i++;
        }
        Node* deleted = Current->NextNode;
        if (deleted!=nullptr){
            Current->NextNode=deleted->NextNode;
        }
        else {
            Current->NextNode=nullptr;
        }
            delete deleted;
            size--;
    }
    }
    }
};
template <typename T>
class Spisok2:public Container
{
private:
   int size=0;
    struct Node{
    T Data;
    Node* PrewNode;
    Node* NextNode;
    };
    Node* Head=nullptr;
    Node* Tail=nullptr;
public:
    void Add(int n) override
    {
        int i=0;
        T Data;
        cin >> Data;
        size++;
        if (n<=(size)/2){
        //s levoy storoni
        Node* Current = Head;
        if (Head==nullptr){
            Current= new Node;
            Head=Current;
            Tail=Current;
            Current->NextNode=nullptr;
            Current->PrewNode=nullptr;
            Current->Data=Data;
         //   size++;
        }
        else {
        while ((i<n)&&(Current->NextNode!=nullptr)){
            i++;
            Current=Current->NextNode;
        }
        Node* newElem= new Node;
        if (Current->NextNode==nullptr){
            Tail=newElem;
        }
        newElem->NextNode=Current->NextNode;
        newElem->PrewNode=Current;
        newElem->Data=Data;
        Current->NextNode=newElem;
        if(newElem->NextNode!=nullptr){
            newElem->NextNode->PrewNode=newElem;
        }
        }
        }
        else {
            //s provoy stotoni
            n=size-2-n;
            Node* Current = Tail;
            while ((i<n)&&(Current->PrewNode!=nullptr)){
                i++;
                Current=Current->PrewNode;
            }
            Node* newElem= new Node;
            if (Current->NextNode==nullptr){
                Tail=newElem;
            }
            newElem->NextNode=Current->NextNode;
            newElem->PrewNode=Current;
            newElem->Data=Data;
            Current->NextNode=newElem;
            if(newElem->PrewNode!=nullptr){
                newElem->PrewNode->NextNode=newElem;
            }
        }
        
    }
    void GetWhole() override
    {
        Node* Current = Head;
        if (Current==nullptr){
            cout << "Pusto! :( "<<endl;
        }
        else {
            while (Current!=nullptr){
                cout.width(4);
                cout << Current->Data;
                Current=Current->NextNode;
            }
        }
        cout << endl;
    }
    void GetOne (int n) override
    {
        if (n>=size) {
            cout << "Error!" << endl;
        }
        else {
        int i=0;
        if (n<=size/2){
            Node* Current=Head;
            while (i<n){
                Current=Current->NextNode;
                i++;
            }
            cout << Current->Data<<endl;
        }
        else {
            n=size-n-1;
            Node* Current = Tail;
            while (i<n){
                i++;
                Current=Current->PrewNode;
            }
            cout << Current->Data<<endl;
        }
        }
    }
    void Delete (int n) override
    {
        if (n>=size){
            cout << "Error!" << endl;
        }
        else {
       // size--;
        int i=0;
        bool f=0;
        if (n<=size/2){
            Node* Current=Head;
            if (n==0){
                Head =Current->NextNode;
                Head->PrewNode=nullptr;
                delete Current;
                size--;
            } else {
            while (!f){
                if (Current->NextNode==nullptr){
                    f=1;
                }
                if (i==n-1){
                    break;
                }
                Current=Current->NextNode;
                i++;
            }
            Node* deleted = Current->NextNode;
            Current->NextNode=deleted->NextNode;
            if(deleted!=nullptr){
                Current->NextNode->PrewNode=Current;
            }
            delete deleted;
                size--;
            }
        }
        else {
            n=size-n-1;
            Node* Current=Tail;
            if (n==0){
                Tail =Current->PrewNode;
                Tail->NextNode=nullptr;
                delete Current;
                size--;
            } else {
            while (!f){
                if (Current->PrewNode==nullptr){
                    f=1;
                }
                if (i==n-1){
                    break;
                }
                Current=Current->PrewNode;
                i++;
            }
            Node* deleted = Current->PrewNode;
            Current->PrewNode=Current->PrewNode->PrewNode;
            if(deleted!=nullptr){
                Current->PrewNode->NextNode=Current;
            }
            delete deleted;
                size--;
        }
        }
        }
    }
};




