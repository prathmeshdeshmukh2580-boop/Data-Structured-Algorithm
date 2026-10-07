#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n-1;j++){
            if(arr[j]<arr[mini]){
               min(arr[j],arr[mini]);
            }
        }
        swap(arr[i],arr[mini]);
    }
}
void bubble_sort(int arr[],int n){
    for(int i=n-1;i>=1;i--){
        int sw=0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                sw=1;
            }
        }
        if(sw==0){
            break;
        }
        cout<<"runs"<<endl;
    }
}
void insertion_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0&&arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
        }
    }
}
void merge(int arr[],int low,int mid,int high){
    int left,right;
    left=low;
    right=mid+1;
    vector<int> temp;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergesort(int arr[],int low,int high){
    if(low==high){
        return;
    }
    int mid = low + (high - low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int quick(int arr[],int low,int high){
    int i=low;
    int pivot=arr[low  ];
    int j=high;
    while(i<j){
        while(arr[i]<=pivot &&  i<=high-1){
            i++;   
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
        swap(arr[j],arr[low]);
    }
return j;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int partit=quick(arr,low,high);
        quicksort(arr,low,partit-1);
        quicksort(arr,partit+1,high);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // selection_sort(arr,n);
    // bubble_sort(arr,n)e;
    // insertion_sort(arr,n);
    // mergesort(arr,0,n-1);
    cout<<"function calling"<<endl;
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}