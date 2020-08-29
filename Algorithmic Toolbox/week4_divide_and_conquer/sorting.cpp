#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);
  int i=0,j=0,flag=0,mag=0;
    for(k=l;k<r;k++){
        if(flag==0 && a[k]==a[m]){
            i = k-1;
            flag = 1;
        }
        if(flag==1 && a[k]==a[m] && a[k+1]!=m){
            j = k+1;
            mag = 1;
        }
    }
   /* if(flag==1 && mag==1){
      randomized_quick_sort(a, l, i);
      randomized_quick_sort(a, j, r);
    }*/
    //else{
      randomized_quick_sort(a, l, m-1);
      randomized_quick_sort(a, m+1, r);
   // }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}

