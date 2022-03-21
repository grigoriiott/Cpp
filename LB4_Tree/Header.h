//
//  Header.h
//  LB4_Tree
//
//  Created by Григорий Отт on 22.05.2021.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;


class Tree {
public:
    Tree ();
    ~Tree();
private:
    int size;
   // vector<bool> visited;
    int maxlvl = 0;
    vector <int> spisochek;
    struct Node{
        int Data;
        Node* LeftNode;
        Node* RightNode;
        int Level=0;
    };
    Node* Root=nullptr;
public:
    void Add(int Data);
    void GetTree(Node* Current);
    void DFS(Node* Current);
    void GetSpisochek ();
    void Delete(Node* Current);
    Node* GetHead();
    void Max();
};
