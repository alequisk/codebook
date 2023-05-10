struct Point {
  double x, y, id;
  Point() : x(0), y(0), id(0) {}
  Point(int x, int y, int id) : x(x), y(y), id(id) {}
};

bool cmp_y(const Point& a, const Point& b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}

bool cmp_x(const Point& a, const Point& b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

int n;
const int MAXN = 50005;
Point points[MAXN], t[MAXN];
double mindist = 1e12;
int bx = 0, by = 1;

void upd_ans(const Point& a, const Point& b) {
  double d = sqrt(pow(a.x - b.x, 2) + pow(b.y - a.y, 2));
  if (d < mindist) {
    mindist = d;
    bx = a.id;
    by = b.id;
  }
}

// range is x-sorted
void closestPair(int l, int r) {
  if (r - l <= 3) {
    for (int i = l; i < r - 1; i++) {
      for (int j = i + 1; j < r; j++) {
        upd_ans(points[i], points[j]);
      }
    }
    sort(points + l, points + r, cmp_y);
    return;
  }
  int m = (r + l) >> 1;
  int midx = points[m].x;

  closestPair(l, m);
  closestPair(m, r);

  inplace_merge(points + l, points + m, points + r, cmp_y);

  int tsz = 0;
  for (int i = l; i < r; ++i) {
    if (fabs(points[i].x - midx) < mindist) {
      for (int j = tsz - 1, k = 0; j >= 0 && points[i].y - t[j].y < mindist && k < 6; --j, ++k)
        upd_ans(points[i], t[j]);
      t[tsz++] = points[i];
    }
  }
}