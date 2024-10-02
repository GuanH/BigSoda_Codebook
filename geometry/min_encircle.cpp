// remember to shuffle!!!
Circle encircle(const vector<Pt> &pts) {
  Circle ans(Pt(), 0);
  for (int i = 0; i < pts.size(); ++i) {
    if (ans.contain(pts[i])) continue;
    ans = {pts[i], 0};
    for (int j = 0; j < i; ++j) {
      if (ans.contain(pts[j])) continue;
      ans = {pts[i], pts[j]};
      for (int k = 0; k < j; ++k) {
        if (ans.contain(pts[k])) continue;
        ans = {pts[i], pts[j], pts[k]}; } } }
  return ans;
}