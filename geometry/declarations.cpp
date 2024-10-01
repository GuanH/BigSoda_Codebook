typedef long double ld;
const ld eps = 1e-10;
#define sign(x) (((x) > eps) - ((x) < -eps))
#define is_zero(x) (!sign(x))
#define sq(p) ((p)*(p))
#define len(p) (sqrt(sq(p)))
#define r90(p) Pt(-p.y, p.x)

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
    return x < a.x || is_zero(x - a.x) && y < a.y; }
  bool operator == (const Pt &a) const {
    return is_zero(x - a.x) && is_zero(y - a.y); }
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
  Pt o; ld r;
  Circle(Pt o = Pt(), ld r = 0) : o(o), r(r) {}
};