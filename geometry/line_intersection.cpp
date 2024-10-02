pair<int, Pt> L_intersect(const Line &a, const Line &b) {
  ld f1 = a.v ^ (b.s - a.s), f2 = a.v ^ (a.s - b.e), f;
  if(sign(f = f1 + f2) == 0) 
    return sign(f1) ? {0, a.s} : {2, a.s};
  return {1, b.s * (f2 / f) + b.e * (f1 / f)};
}