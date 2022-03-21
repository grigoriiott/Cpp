//
//  Metodi.cpp
//  LB4_Tree
//
//  Created by Григорий Отт on 22.05.2021.
//

#include "Header.h"
Tree:: Tree() {
    
}
Tree::~Tree(){
    Node* Current=Root;
    Delete(Current);
}
void Tree::Add(int Data){
    bool flag = 0; // 1 is for right, 0 is for left
    int lvl=0;
    Node* Current= Root;
    if (Current==nullptr){
        Current=new Node;
        Root=Current;
        Current->LeftNode=nullptr;
        Current->RightNode=nullptr;
        Current->Data=Data;
        Current->Level=0;
    }
    else {
        while (1){
            lvl++;
        if (Current->Data<=Data){
            if (Current->RightNode==nullptr){
                flag = 1;
                break;
            }
            Current=Current->RightNode;
        }
        else {
            if (Current->LeftNode==nullptr){
                flag = 0;
                break;
            }
            Current=Current->LeftNode;
        }
        }
        Node* newNode = new Node;
        newNode->LeftNode=nullptr;
        newNode->RightNode=nullptr;
        newNode->Data=Data;
        newNode->Level=lvl;
        if (newNode->Level>maxlvl){
            maxlvl=newNode->Level;
        }
        if (flag==0) {
            Current->LeftNode=newNode;
        }
        else {
            Current->RightNode=newNode;
        }
    }
    size++;
}
void Tree::GetTree(Node* Current){
    if (Current!=nullptr){
        GetTree(Current->RightNode);
        for (int i=0; i<Current->Level;i++){
            cout <<"   ";
        }
            cout << Current->Data<< endl;
            GetTree(Current->LeftNode);
        
    }
}
void Tree::DFS(Node* Current) {
    if (Current != nullptr){
    DFS(Current->LeftNode);
    spisochek.push_back(Current->Data);
    DFS(Current->RightNode);
    }
}
void Tree::GetSpisochek(){
    for (int i=0; i<spisochek.size();i++){
        cout.width(5);
        cout << spisochek[i];
    }
}
void Tree::Delete(Node* Current){
    if (Current != nullptr){
    Delete(Current->LeftNode);
        delete Current;
    Delete(Current->RightNode);
    }
}
Tree::Node* Tree::GetHead(){
    Node* Current=Root;
    return Current;
}
void Tree::Max(){
    Node* Current=Root;
    while (Current->RightNode!= nullptr){
        Current=Current->RightNode;
    }
    cout << Current->Data;
}
