#include <iostream>
#include <vector>

using namespace std;

int min(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}

int swap(int arr[],int i){
    int temp = arr[i];
    arr[i]=min(arr[2*i],arr[2*i+1]);
    if(arr[i]==arr[2*i]){
        arr[2*i]=temp;
        return 2*i;
    }
    else{
        arr[2*i+1]=temp;
        return 2*i+1;
    }
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    int count=0;
    int count2=0;
    vector<pair<int,int>> a;
    for(int i=1;i<n+1;i++){
        cin>>arr[i];
    }
    do{
        count2=count;
    for(int i=1;i<n+1;i++){
        if(2*i<n+1 && 2*i+1<n+1){
            if(arr[i]>arr[2*i] || arr[i]>arr[2*i+1]){
                a.push_back(make_pair(i,swap(arr,i)));
                count++;
            }
        }
        else if(2*i<n+1){
            if(arr[i]>arr[2*i]){
                swap(arr+i,arr+2*i);
                a.push_back(make_pair(i, 2*i));
                count++;
            }
        }
        else if(2*i+1<n+1){
            if(arr[i]>arr[2*i+1]){
                swap(arr+i,arr+2*i+1);
                a.push_back(make_pair(i,2*i+1));
                count++;
            }
        }
      }
    }while(count2-count!=0);
    cout<<count<<endl;
    for(auto i=a.begin();i<a.end();i++){
        cout<<(i->first)-1<<" "<<(i->second)-1<<endl;
    }
}
