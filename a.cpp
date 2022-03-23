#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio();
  int t, n, inp;
  cin >> t;
  while (t--) {
    multiset<int> positives;
    multiset<int, greater<int>> negatives;
    int zeros = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> inp;
      if (inp > 0) {
        positives.insert(inp);
      } else if (inp < 0) {
        negatives.insert(inp);
      } else
        ++zeros;
    }
    if (positives.size() == 0) {
      if (zeros == 0) {
        cout << accumulate(negatives.begin(), next(negatives.begin(), 5), 1ll,
                           multiplies<long long>())
             << '\n';
      } else {
        cout << "0\n";
      }
    } else if (positives.size() + negatives.size() / 2 * 2 < 5) {
      cout << "0\n";
    } else {
      long long ans = 1;
      int cnt = 0;
      while (cnt != 5) {
        if (positives.size() >= 2 && negatives.size() >= 2 && cnt <= 3) {
          auto n1 = next(negatives.end(), -1), n2 = next(negatives.end(), -2);
          auto p1 = next(positives.end(), -1), p2 = next(positives.end(), -2);
          long long m1 = *n1 * *n2, m2 = *p1 * *p2;
          if (m1 >= m2) {
            ans *= m1;
            negatives.erase(n1);
            negatives.erase(n2);
          } else {
            ans *= m2;
            positives.erase(p1);
            positives.erase(p2);
          }
          cnt += 2;
        } else {
          auto p = next(positives.end(), -1);
          ans *= *p;
          positives.erase(p);
        }
      }
      cout << ans << '\n';
    }
  }
}
