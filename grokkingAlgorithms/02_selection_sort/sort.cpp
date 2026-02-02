#include <bits/stdc++.h>

using namespace std;

int lower(vector<int> &list, int begin){
    int indexLower = begin;
    
    for(int i = begin; i < list.size(); i++){
        if(list[i] < list[indexLower])
            indexLower = i;
    }

    return indexLower;
}

void selectionSort(vector<int> &list){
    int temp;

    for(int i = 0; i < list.size(); i++){
        int indexLower = lower(list, i);
        
        temp = list[i];
        list[i] = list[indexLower];
        list[indexLower] = temp;
    }
}

int main(){

    vector<int> list = {3, 6, 2, 8, 4, 10};
    cout << "\nBEFORE: ";
    for(int x : list)
        cout << x << " ";
    
    selectionSort(list);
    
    cout << "\n\nAFTER: ";
    for(int x : list)
        cout << x << " ";

    cout << "\n\n\n";

    return 0;
}