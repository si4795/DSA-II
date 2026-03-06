#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n;
    cout<<"Enter the number of applicants: ";
    cin>>n;

    int m;
    cout<<"Enter the number of available apartments: ";
    cin>>m;

    int k;
    cout<<"The maximum allowed difference between the desired size of the apartment and the size of the available apartment: ";
    cin>>k;

    int a[n];
    cout<<"Enter the desired size of apartments of the applicants: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int b[m];
    cout<<"Enter the size of the available apartments: ";
    for(int i=0; i<m; i++){
        cin>>b[i];
    }

    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    
    for(int i = 0; i < m - 1; i++){
        int min = i;
        for(int j = i + 1; j < m; j++){
            if(b[j] < b[min]){
                min = j;
            }
        }
        int temp = b[i];
        b[i] = b[min];
        b[min] = temp;
    }
    int count = 0;
    int j = 0;
    
    for(int i = 0; i < n; i++){
        while(j < m && b[j] < a[i] - k){
            j++;
        }
        if(j < m && b[j] <= a[i] + k){
            count++;
            j++;
        }
    }
    
    cout << "The Number of applicants who will  get an apartment: " << count << endl;




}