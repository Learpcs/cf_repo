#include <bits/stdc++.h>
using namespace std;

int main() {
  const int N = 3;
  int a[N], b[N];
  for (int i = 0; i < N; ++i)
    cin >> a[i];
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if ((a[i] + a[j]) % 2 != 0) {
        cout << -1;
        return 0;
      }
    }
  }
  sort(a, a + N);
  memcpy(b, a, sizeof(b));
  int cnt1 = 0, cnt2 = 0;
  int to_do1 = ;
  cnt1 += (a[2] - a[1]) / 2;
  a[1] += (a[2] - a[1]) / 2;
  a[0] -= (a[2] - a[1]) / 2;
  a[2] -= (a[2] - a[1]) / 2;
  if (a[0] < 0) {
    cnt1 = INT_MAX;
  } else {
    cnt1 += (a[1] - a[0]) / 2;
  }
  cnt
}
