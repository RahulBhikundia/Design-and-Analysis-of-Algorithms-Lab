#include <iostream>
#include <chrono>
using namespace std;

void swap(int arr[],int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void merge(int arr[],int first, int mid, int last){
    int m = mid-first+1;
    int n = last-mid;
    int *A = new int[m];
    int *B = new int[n];
    
    for(int i=0;i<m;i++){
        A[i] = arr[first+i];
    }

    for(int i=0;i<n;i++){
        B[i] = arr[mid+1+i];
    }
    
    int i=0,j=0,k=first;

    while(i<m && j<n){
        if(A[i]<=B[j]){
            arr[k] = A[i];
            i++;
        }
        else{
            arr[k] = B[j];
            j++;
        }
        k++;
    }

    while(i<m){
        arr[k] = A[i];
        i++;
        k++;
    }

    while(j<n){
        arr[k] = B[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int first, int last){
    if(first<last){
        int mid = (first + last)/2;
        MergeSort(arr,first,mid);
        MergeSort(arr,mid+1,last);
        merge(arr,first,mid,last);
    }
}

int main(){
    int arr[10];

    for (int i=0;i<10;i++)
    {
        arr[i] = rand()%10;
    }

    cout<<"The random Numbers before sorting are:";
    for(int i=0; i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    auto start = chrono::high_resolution_clock::now();
    MergeSort(arr,0,10);
    auto end = chrono::high_resolution_clock::now();

    cout<<"The random Numbers after sorting are:";
    for(int i=0; i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Runtime: " << duration.count() << " nanoseconds" << endl;

    return 0;
}