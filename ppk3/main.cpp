//
//  main.cpp
//  ppk3
//
//  Created by Григорий Отт on 06.05.2021.
//
#include "Header.h"
int main(int argc, const char * argv[]) {
    Spisok1<int>* spisok1=new Spisok1<int>;
    Spisok2<int>* spisok2=new Spisok2<int>;
    int a=0;
    int n;
    cout << "S kakim spiskom rabotaem? \n 1 - odnosvyaz \n 2 - dvusvyaz" << endl;
    cin >> a;
    if (a==1) {
        cout << "Zapolnim na N el-tov" << endl;
        cout << "N = "; cin >> n;
        for (int i=0; i<n; i++){
            spisok1->Add(i);
        }
        spisok1->GetWhole();
        cout << "Vivod N'togo el-ta" << endl;
        cout << "N = "; cin >> n;
        spisok1->GetOne(n);
        cout << "Udalenie N'togo el-ta" << endl;
        cout << "N = "; cin >> n;
        spisok1->Delete(n); spisok1->GetWhole();
        spisok1->Add(5);
        spisok1->GetWhole();
        
    }
    if (a==2) {
        cout << "Zapolnim na N el-tov" << endl;
        cout << "N = "; cin >> n;
        for (int i=0; i<n; i++){
            spisok2->Add(i);
        }
        spisok2->GetWhole();
        cout << "Vivod N'togo el-ta" << endl;
        cout << "N = "; cin >> n;
        spisok2->GetOne(n);
        cout << "Udalenie N'togo el-ta" << endl;
        cout << "N = "; cin >> n;
        spisok2->Delete(n); spisok2->GetWhole();
    }
    delete spisok2;
    delete spisok1;
return 0;
    
}
