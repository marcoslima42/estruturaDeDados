#include <bits/stdc++.h>

using namespace std;

int fat(int x){
    
    if(x == 1){
        return 1; 
    }
    else{
        return x * fat(x-1);
    }
}

int main(){
    
    cout << fat(5) << endl;
    cout << fat(4) << endl;
    cout << fat(2) << endl;
    cout << fat(3) << endl;
    cout << fat(1) << endl;


    return 0;
}