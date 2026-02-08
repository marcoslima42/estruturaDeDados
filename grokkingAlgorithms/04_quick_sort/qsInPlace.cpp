#include <bits/stdc++.h>

using namespace std;

void quickSort(vector<int> &list, int begin, int end){
    int pivot;
    int j = begin;
    int i = begin - 1;

    if(begin < i || end == begin){ //base case
        return;
    }
    else{ //recursive case, breaking the problem
        pivot = list[0];
        
        for(j; j < end; j++){
            
            if(list[j] <= pivot){
                i++;

                if(j > i){
                    swap(list[i], list[j]);
                }
            }
        }

        quickSort(list, 0, i-1);
        quickSort(list, 0, i+1);
    }
}

int main(){

    vector<int> list = {8, 6, 1, 3, 2};//{3, 2, 0, 1, 5, 4, 22, 11, 7}; //{3, 3, 3, 2, 1};

    cout << "BEFORE QUICKSORT: \n";
    for(int x : list)   cout << x << " ";

    quickSort(list, 0, (list.size()-1));

    cout << "\n\nAFTER QUICKSORT: \n";
    for(int x : list)   cout << x << " ";

    cout << "\n\n";
    return 0;
}