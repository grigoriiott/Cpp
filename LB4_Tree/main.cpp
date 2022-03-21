//
//  main.cpp
//  LB4_Tree
//
//  Created by Григорий Отт on 22.05.2021.
//

#include "Header.h"
int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    Tree* derevo = new Tree;
    for (int i=0; i<10;i++){
        derevo->Add(rand()%10+1);
        //derevo->Add(i);
    }
    derevo->GetTree(derevo->GetHead());
    derevo->DFS(derevo->GetHead());
    cout << endl<<endl;
    derevo->GetSpisochek();
    derevo->Max();
    delete derevo;
    cout << endl;
    return 0;
}
