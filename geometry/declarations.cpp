typedef long double ld;
const ld eps = 1e-10;
#define sign(x) (((x) > eps) - ((x) < -eps))
#define sq(p) ((p)*(p))
#define len(p) (sqrt(sq(p)))
#define r90(p) Pt(-(p).y, (p).x)

struct Pt {
  ld x, y;
  Pt(ld x = 0, ld y = 0) : x(x), y(y) {}
  Pt operator + (const Pt &a) const {
    return Pt(x + a.x, y + a.y);  }
  Pt operator - (const Pt &a) const {
    return Pt(x - a.x, y - a.y);  }
  Pt operator * (const ld &a) const {
    return Pt(x * a, y * a);  }
  Pt operator / (const ld &a) const {
    return Pt(x / a, y / a);  }
  ld operator * (const Pt &a) const {
    return x * a.x + y * a.y;  }
  ld operator ^ (const Pt &a) const {
    return x * a.y - y * a.x;  }
  bool operator < (const Pt &a) const {
    return sign(x - a.x) < 0 || sign(x - a.x) == 0 && sign(y - a.y) < 0; }
  bool operator == (const Pt &a) const {
    return sign(x - a.x) == 0 && sign(y - a.y) == 0; }
};

struct Line {
  Pt s, e, v; // start, end, end-start
  ld rad;
  Line(Pt s = Pt(), Pt e = Pt())
    : s(s), e(e), v(e - s), rad(atan2(v.y, v.x)) {}
  bool operator < (const Line &L) const {
    return rad < L.rad;
} };

struct Circle {
  Pt o; ld r2;
  Circle(Pt o = Pt(), ld r = 0) : o(o), r2(sq(r)) {}
  Circle(const Pt &p1, const Pt &p2)
    : o((p1 + p2) / 2), r2(sq(p1 - p2) / 4.0) {}
  Circle(const Pt &p1, const Pt &p2, const Pt &p3) {
    Pt va = r90(p1 - p2), vb = r90(p1 - p3);
    if (sign(va ^ vb) == 0) {
      *this = Circle(p1, p2);
      Circle t(p1, p3);
      if (r2 < t.r2) *this = t;
      t = Circle(p2, p3);
      if (r2 < t.r2) *this = t; }
    else {
      Pt p12 = (p1 + p2) / 2, p13 = (p1 + p3) / 2;
      ld t = ((p13 - p12) * (p1 - p3)) / (va ^ vb);
      o = p12 + va*t;
      r2 = sq(o - p1);
    }
  }
  bool contain(const Pt &a) {
    return sign(sq(a - o) - r2) <= 0; }
};