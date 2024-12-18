int dp[MXN_LEN][PRE_NUM][LIMIT][F0];
int DP(const string &s, int i = 0, int pre = 0, bool lim = 1, bool f0 = 1) {
  if (dp[i][pre][lim][f0]) return dp[i][pre][lim][f0];
  if (i == s.size()) return dp[i][pre][lim][f0] = 1;
  int res = 0, h = lim ? s[i] - '0' : 9;
  for (int j = 0; j <= h; j++)
    if (abs(j - pre) >= 2 || f0)
      res += DP(s, i + 1, j, j == h && lim, f0 && !j);
  return dp[i][pre][lim][f0] = res;
}