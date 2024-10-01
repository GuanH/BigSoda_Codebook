inline Pt intersect(const Line &a, const Line &b) {
  ld f1 = a.v ^ (b.s - a.s),f2 = a.v ^ (a.s - b.e), f;
  return b.s * (f2 / f) + b.e * (f1 / f);
}

Pt get_o(const Pt &a, const Pt &b, const Pt &c) {
  if (a == b && b == c) return a;
  if (a == b) return (a + c)/2;
  if (a == c) return (b + c)/2;
  if (b == c) return (a + b)/2;
  Line pab((a + b)/2), pbc((b + c)/2);
  pab.v = r90(b - a), pbc.v = r90(c - a);
  pab.e = pab.s + pab.v, pbc.e = pbc.s + pbc.e;
  return intersect(pab, pbc);
}

pair<ld, Pt> encircle(const vector<Pt> &p) {
  random_shuffle(p.begin(), p.end());
  int n = p.size();
  ld r = 0;
  Pt o = p[0];
  for (int i = 0; i < n; i++) {
    if (len(o - p[i]) < r || sign(len(o - p[i]) - r)) continue;
    o.x = (p[i].x + p[1].x) / 2;
    o.y = (p[i].y + p[1].y) / 2;
    r = len(p[i] - p[1]) / 2;
    for (int j = 1; j < i; j++) {
      if (len(o - p[j]) < r || sign(len(o - p[j]) - r)) continue;
      o.x = (p[i].x + p[j].x) / 2;
      o.y = (p[i].y + p[j].y) / 2;
      r = len(p[i] - p[j]) / 2;
      for (int k = 0; k < j; k++) {
        if (len(o - p[k]) < r || sign(len(o - p[k]) - r)) continue;
        o = get_o(p[i], p[j], p[k]);
        r = len(o - p[i]);
      }
    }
  }
  return {r, o};
}
