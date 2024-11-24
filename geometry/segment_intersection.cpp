inline int ori(const Pt &o, const Pt &a, const Pt &b) {
  return sign((a - o) ^ (b - o)); }
// 0:out, 1:ontop, 2:in
inline int btw(const Pt &a, const Pt &b, const Pt &c) {
  if (ori(a, b, c)) return 0;
  int s = sign((c - a) * (c - b));
  return (s < 0) + (s <= 0); }
// 0:no, 1:1pt(parallel), -1:1pt, 2:inf pt
int banana(const Pt &p1, const Pt &p2,
           const Pt &p3, const Pt &p4) {
  int a123 = ori(p1, p2, p3);
  int a124 = ori(p1, p2, p4);
  int a341 = ori(p3, p4, p1);
  int a342 = ori(p3, p4, p2);
  if (a123 == 0 && a124 == 0) {
    return btw(p1, p2, p3) + btw(p1, p2, p4) +
           btw(p3, p4, p1) + btw(p3, p4, p2) >> 1; 
  }
  return -(a123 * a124 <= 0 && a341 * a342 <= 0);
}
pair<int, Pt> S_intersect(const Pt &p1, const Pt &p2,
                        const Pt &p3, const Pt &p4) {
    int b = banana(p1, p2, p3, p4);
    if (b != -1) return {b, btw(p1, p2, p3) ? p3 : p4};
    ld a123 = (p2 - p1) ^ (p3 - p1);
    ld a124 = (p2 - p1) ^ (p4 - p1);
    return {1, (p4 * a123 - p3 * a124) / (a123 - a124)};
}
