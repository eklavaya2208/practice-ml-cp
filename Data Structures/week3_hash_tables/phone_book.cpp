#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<int, string> umap;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        vector<string> str2 = {"add","find","del"};
        if(str==str2[0]){
            string str3;
            int a;
            cin>>a>>str3;
            umap[a]=str3;
        }
        else if(str==str2[1]){
            int a;
            cin>>a;
            if(!umap.empty()){
                if(umap.find(a)==umap.end()){
                    cout<<"not found"<<endl;
                }
                else
                    cout<<umap.at(a)<<endl;
            }
            else
                cout<<"not found"<<endl;
        }
        else if(str==str2[2]){
            int a;
            cin>>a;
            umap.erase(a);
        }
    }
}

