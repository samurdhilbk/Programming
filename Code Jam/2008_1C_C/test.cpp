#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

#define MAXN (1<<20)

using namespace std;
int sum_bit[MAXN];

int sum_bit_get(int x)
{
  int ret = 0;
  for(int i = x | MAXN; i < 2 * MAXN; i += i & -i)
    ret = (ret + sum_bit[i ^ MAXN]) % 1000000007;
  return ret;
}

void sum_bit_add(int x, int v)
{
  for(int i = x | MAXN; i; i &= i - 1)
    sum_bit[i ^ MAXN] = (sum_bit[i ^ MAXN] + v) % 1000000007;
}

int S[1000000];
int S2[1000000];

int main()
{
  int T; cin >> T;
  long long X, Y, Z, A[100];
  for(int t = 1; t <= T; t++) {
    int n, m; cin >> n >> m >> X >> Y >> Z;
    for(int i = 0; i < m; i++) cin >> A[i];

    // Generate S
    for(int i = 0; i < n; i++) {
      S[i] = A[i % m];
      A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
    }

    // Normalize S
    memcpy(S2, S, sizeof(S));
    sort(S2, S2+n);
    for(int i = 0; i < n; i++)
      S[i] = lower_bound(S2, S2+n, S[i]) - S2;

    // Calculate f(i) and sum them in to result.
    int result = 0;
    memset(sum_bit, 0, sizeof(sum_bit));
    for(int i = n - 1; i >= 0; i--) {
      int add = 1 + sum_bit_get(S[i] + 1);
      sum_bit_add(S[i], add);
      result = (result + add) % 1000000007;
    }
    
    cout << "Case #" << t << ": " << result << endl;
  }
  return 0;
}