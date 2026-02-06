#include <bits/stdc++.h>

using namespace std;

vector<int> quickSort(vector<int> &list){
    vector<int> less;
    vector<int> greater;
    int pivot;

    if(list.size() < 2){ //base case
        return list;
    }
    else{ //recursive case, breaking the problem
        pivot = list[0];
        
        for(int x : list)
            if(x < pivot)   less.push_back(x);
        
        for(int x : list)
            if(x > pivot)   greater.push_back(x);

        less = quickSort(less);
        greater = quickSort(greater);

        less.push_back(pivot);
        less.insert(less.end(), greater.begin(), greater.end());
        
        return less;
    }
}

int main(){

    vector<int> list = {3, 2, 0, 1, 5, 4, 22, 11, 7};

    cout << "BEFORE QUICKSORT: \n";
    for(int x : list)   cout << x << " ";

    list = quickSort(list);

    cout << "\n\nAFTER QUICKSORT: \n";
    for(int x : list)   cout << x << " ";

    return 0;
}