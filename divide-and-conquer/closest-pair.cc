#include <bits/stdc++.h>
using namespace std;

/* Before call the closest pair function, confirm that points are sorted by x */

namespace closest_point {
struct point {
  int id;
  double x, y;
  friend ostream& operator<<(ostream& out, const point& p);
};

bool point_compare_by_x(const point& a, const point& b) {
  if (a.x == b.x)
    return a.y < b.y;
  return a.x < b.x;
}
bool point_compare_by_y(const point& a, const point& b) {
  if (a.y == b.y)
    return a.x < b.x;
  return a.y < b.y;
}

/* Data */
double min_pair_distance = 1e9;  // replace to max distance
std::vector<point> points, strip;
int a_id, b_id, sz;

void init(int n) {
  points.resize(n);
  strip.resize(n);
  sz = n;
}

void update_answer(const point& a, const point& b) {
  double dist = sqrt(pow(a.x - b.x, 2) + pow(b.y - a.y, 2));
  if (dist < min_pair_distance) {
    a_id = a.id;
    b_id = b.id;
    min_pair_distance = dist;
  }
}
/* [0, N - 1]- range */
void closest_pair(int l, int r) {
  if (r - l <= 3) {  // base case
    for (int i = l; i < r; i++)
      for (int j = i + 1; j <= r; j++)
        update_answer(points[i], points[j]);
    sort(points.begin() + l, points.begin() + r + 1);
    return;
  }
  int mid = (l + r) >> 1;
  int mid_x = points[mid].x;

  closest_pair(l, mid);
  closest_pair(mid, r);

  std::inplace_merge(points.begin() + l, points.begin() + mid, points.begin() + r + 1, point_compare_by_y);
  int strip_size = 0;
  for (int i = l; i <= r; i++) {
    if (fabs(points[i].x - mid_x) < min_pair_distance) {
      for (int j = strip_size - 1, k = 0; j >= 0 && points[i].y - strip[j].y < min_pair_distance && k < 6; --j, ++k) {
        update_answer(points[i], strip[j]);
      }
      strip[strip_size++] = points[i];
    }
  }
}

double get_answer() {
  return min_pair_distance;
}

pair<int, int> get_closest_points() {
  return {a_id, b_id};
}

ostream& operator<<(ostream& out, const point& p) {
  out << "(" << p.id << ", [" << p.x << "," << p.y << "])";
  return out;
}
};  // namespace closest_point