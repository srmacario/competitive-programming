    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;

    #define endl '\n'
    #define double long double
    #define int long long

    const double EPS = 1e-10;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    tuple<int, double, double, double, double> circle_intersec(double x1, double y1, double r1, double x2, double y2, double r2) {
        double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if(d > r1 + r2 || d < abs(r1 - r2)) {
            return {0, 0, 0, 0, 0};
        }
        double a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
        double h = sqrt(r1 * r1 - a * a);
        double x3 = x1 + a * (x2 - x1) / d;
        double y3 = y1 + a * (y2 - y1) / d;
        double x4 = x3 + h * (y2 - y1) / d;
        double y4 = y3 - h * (x2 - x1) / d;
        double x5 = x3 - h * (y2 - y1) / d;
        double y5 = y3 + h * (x2 - x1) / d;
        return {2, x4, y4, x5, y5};
    }

    main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        double r;
        cin >> r;
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double r1 = sqrt(x1 * x1 + y1 * y1);
        double r2 = sqrt(x2 * x2 + y2 * y2);
        auto e = circle_intersec(x1, y1, r1, x2, y2, r2);
        double left = 0, right = min({r, r1, r2});
        r = right;
        double start = right;
        while(right - left > EPS) {
            double mid = (left + right) / 2;
            auto e = circle_intersec(0, 0, r - mid, x1, y1, r1 - mid);
            if(get<0>(e) == 0) {
                right = mid;
            } else {
                // need to check if one of points is inside other circle
                double dist1 = sqrt((get<1>(e) - x2) * (get<1>(e) - x2) + (get<2>(e) - y2) * (get<2>(e) - y2));
                double dist2 = sqrt((get<3>(e) - x2) * (get<3>(e) - x2) + (get<4>(e) - y2) * (get<4>(e) - y2));
                if(dist1 <= r2 - mid || dist2 <= r2 - mid) {
                    // can decrease even further
                    left = mid;
                } else {
                    auto e2 = circle_intersec(0, 0, r - mid, x2, y2, r2 - mid);
                    if(get<0>(e2) == 0) {
                        right = mid;
                    } else {
                        double dist1 = sqrt((get<1>(e2) - x1) * (get<1>(e2) - x1) + (get<2>(e2) - y1) * (get<2>(e2) - y1));
                        double dist2 = sqrt((get<3>(e2) - x1) * (get<3>(e2) - x1) + (get<4>(e2) - y1) * (get<4>(e2) - y1));
                        if(dist1 <= r1 - mid || dist2 <= r1 - mid) {
                            left = mid;
                        } else {
                            auto e3 = circle_intersec(x1, y1, r1 - mid, x2, y2, r2 - mid);
                            if(get<0>(e3) == 0) {
                                right = mid;
                            } else {
                                double dist1 = sqrt((get<1>(e3) - 0) * (get<1>(e3) - 0) + (get<2>(e3) - 0) * (get<2>(e3) - 0));
                                double dist2 = sqrt((get<3>(e3) - 0) * (get<3>(e3) - 0) + (get<4>(e3) - 0) * (get<4>(e3) - 0));
                                if(dist1 < r - mid + EPS || dist2 < r - mid + EPS) {
                                    left = mid;
                                } else {
                                    right = mid;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << setprecision(15) << fixed << right << endl;
    }