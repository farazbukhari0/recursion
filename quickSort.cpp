#include <bits/stdc++.h> 

void swap(vector<int> &arr, int i, int j){
    int temp = arr[i];
    arr[i]= arr[j];
    arr[j]= temp;
}

int placePivot(vector<int> &arr, int low, int high ){
    //cout<<"\n placePivot called from "<<low<<" to "<<high<<"\n";
    int pivot = low;
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=arr[pivot] && i<= high-1) // pay attention on equal to sign, it might lead to wrong solution or TLE
            i++;
        while(arr[j]>arr[pivot] && j>=low+1)
            j--;
        if(i<j)
        swap(arr, i, j);
        /*cout<<"array now looks as:\n";
        for(int k=0;k<=arr.size()-1;k++)
        cout<<arr[k]<<" ";
        cout<<"\n";*/
    }
    swap(arr, pivot, j);
    /*cout<<"array from low to high now looks as:\n";
    for(int k=low;k<=high;k++)
    cout<<arr[k]<<" ";
    cout<<"\n";*/
    return j;
}

void QS(vector<int> &arr, int low, int high ){
    if(low<high){
        int partitionIndex =  placePivot(arr, low, high);
        /*cout<<"paritionIndex is "<<partitionIndex<<"\n";
        cout<<"array now looks as:\n";
        for(int k=0;k<=arr.size()-1;k++)
        cout<<arr[k]<<" ";
        cout<<"\n";*/
        QS(arr, low, partitionIndex-1);
        QS(arr, partitionIndex+1, high);
    }

}

vector<int> quickSort(vector<int> arr)
{
    int n = arr.size();
    QS(arr,0, n-1);
    return arr;
}
