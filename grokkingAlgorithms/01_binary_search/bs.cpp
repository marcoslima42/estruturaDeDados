#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &list, int guess){
    int low = 0, high = list.size()-1;

    while(low <= high){
        int mid = (low + high)/2;

        if(guess == list[mid]){
            return mid;
        }
        else if(list[mid] < guess){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    //end of file
    vector<int> list{istream_iterator<int>(cin), istream_iterator<int>()};
    int num = 10;

    if(int found = binarySearch(list, num); found != -1)
        cout << "Found! Position: " << found << endl;
    else 
        cout << "Not found!";

    return 0;
}