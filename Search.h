#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename flexibleType> // ???
void printArray(flexibleType arr[], int n) {
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    if(end == start){
        if(arr[start]==target){
            return true;
        }
        return false;
    }
    for(int i = 0; i < end+1; i++){
        if(arr[i] == target){
            return true;
        }
        else{
            continue;
        }
    }
    return false;
}

// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
    int start = 0;
    int end = n - 1;
    if(arr[start] == arr[end]){
        if(arr[start] == target){
            return true;
        }
        return false;
    }
    int mid = n/2;
    if (arr[mid] == target){
        return true;
    }
    if(arr[mid] < target){
        start = mid + 1;
        for(int i = 0; i < n; i++){
            if(arr[i] == target){
                return true;
            }
            else{
                continue;
            }
        }
    }
    if(arr[mid] > target){
        end = mid - 1;
        for(int i = 0; i < mid; i++){
            if(arr[i] == target){
                return true;
            }
            else{
                continue;
            }
        }
    }

    return false;	
}

// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
    int mid = n/2;
    if(charray[mid]==target){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(charray[0] >= charray[n-1]){
        return false;
    }
    // else if(charray[0] == charray[n-1]){
    //     if(charray[0] == target){
    //         return true;
    //     }
    //     return false;
    // }
    //general case
    
    if(charray[mid] < target){
        char *start = &charray[mid+1];
        return binSearchR(target, start, n/2);
    }
    else if (charray[mid] > target){
        return binSearchR(target, charray, n/2);
    }
    return false;
}

// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

void swap(double darray[], int index1, int index2) {
    double temp = darray[index2];
    darray[index2] = darray[index1];
    darray[index1] = temp;
}

int minFind(double darray[], int n) {
    double min = darray[0];
    int index = 0;
    int i = 0;
    while(i < n){
        if( darray[i] < min){
            min = darray[i];
            index = i;
        }
        else{
            i++;
        }

    }
    return index;
}

void newSort(double darray[], int n) {
    for(int j = 0; j < n-1; j++){
        for(int i = 0; i+1 < n; i++) {
            if(darray[i] < darray[i+1]) {
            }
            else{
                swap(darray, i, i+1);
            }
        }
    }
}
