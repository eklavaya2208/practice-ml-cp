#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int MaxPairwiseProduct(long long int num[]){
    return num[0]*num[1];
}

int main() {
    int n;
    cin >> n;
    long long int numbers[n];
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    sort(numbers,numbers+n,greater<int>());
    long long int a = MaxPairwiseProduct(numbers);
    cout << a << "\n";
    return 0;
}

