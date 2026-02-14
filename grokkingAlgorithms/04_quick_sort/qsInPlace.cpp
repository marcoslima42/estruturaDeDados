#include <bits/stdc++.h>

using namespace std;

void quickSort(vector<int> &list, int begin, int end){
    int pivot;
    int j = begin;
    int i = begin - 1;

    if(begin >= end){ //base case
        return;
    }
    else{ //recursive case, breaking the problem
        pivot = end;
        
        for(j; j <= end; j++){
            
            if(list[j] <= list[pivot]){
                i++;

                if(j > i){
                    swap(list[i], list[j]);
                }
            }
        }

        quickSort(list, begin, i-1); // left
        quickSort(list, i+1, end);  // right
    }
}

int main(){

    vector<int> list = {3, 3, 3, 2, 1}; //{8, 6, 1, 3, 2};//{3, 2, 0, 1, 5, 4, 22, 11, 7}; 

    cout << "BEFORE QUICKSORT: \n";
    for(int x : list)   cout << x << " ";

    quickSort(list, 0, (list.size()-1));

    cout << "\n\nAFTER QUICKSORT: \n";
    for(int x : list)   cout << x << " ";

    cout << "\n\n";
    return 0;
}