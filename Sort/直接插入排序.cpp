#include <iostream>
using namespace std;

const int N = 10010;
int a[N];

void insertSort(int n) {

    for (int i = 1; i < n; ++i) {
        int temp = a[i];
        int j = i - 1;

        while (j >= 0 && temp < a[j]) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = temp;
    }
}

int main() {
    int n; cin>>n;

    for (int i = 0; i < n; ++i) cin>>a[i];
    insertSort(n);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}