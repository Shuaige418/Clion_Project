#include <iostream>
using namespace std;

const int N = 10010;
int a[N];
void shellSort(int n) {
    for (int d = n / 2; d >= 1; d /= 2) {
        for (int i = d; i < n; ++i) {
            int temp = a[i];
            int j = i;
            while (j >= d && temp < a[j - d]) {
                a[j] = a[j - d];
                j -= d;
            }
            a[j] = temp;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    shellSort(n);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    return 0;
}