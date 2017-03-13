#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point
{
    int x;
    int y;

	bool operator <(Point &p) {
		return x < p.x || (x == p.x && y < p.y);
	}
};

int data_number;

double is_clockwise(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void readFile(vector<Point> &points)
{
    data_number = 0;
    ifstream inFile("Convex_Hull_Data.txt");
    while (inFile >> points[data_number].x >> points[data_number].y) ++data_number;
    inFile.close();
}

int main()
{
    vector<Point> points(1000);
    vector<Point> hull(1000);
    int k = 0;

    readFile(points);

    points.resize(data_number);
    sort(points.begin(), points.end());

    for (int i = 0; i < data_number; ++i) {
        cout << points[i].x << " " << points[i].y << endl;
    }

//     =========================================================================
//     Convex hull, Monotone chain
//
//     lower hull
    for (int i = 0; i < data_number; ++i) {
        while (k >= 2 && is_clockwise(hull[k - 2], hull[k - 1], points[i]) <= 0) {
//            cout << "i: " << i << ", " << "k: " << k << " | " << "hull[k - 2]: " << "(" << hull[k - 2].x << "," << hull[k - 2].y << "), "
//                 << "hull[k - 1]: " << "(" << hull[k - 1].x << "," << hull[k - 1].y << "), "
//                 << "points[i]: " << "(" << points[i].x << "," << points[i].y << "), "
//                 << "area: " << is_clockwise(hull[k - 2], hull[k - 1], points[i]) << endl;
            --k;
        }
        hull[k] = points[i];
        k++;
    }

//     upper hull
    for (int j = data_number - 2, t = k + 1; j >= 0; --j) {
        while (k >= t && is_clockwise(hull[k - 2], hull[k - 1], points[j]) <= 0) {
//            cout << "j: " << j << ", " << "k: " << k << " | " << "hull[k - 2]: " << "(" << hull[k - 2].x << "," << hull[k - 2].y << "), "
//                 << "hull[k - 1]: " << "(" << hull[k - 1].x << "," << hull[k - 1].y << "), "
//                 << "points[i]: " << "(" << points[j].x << "," << points[j].y << "), "
//                 << "area: " << is_clockwise(hull[k - 2], hull[k - 1], points[j]) << endl;
            --k;
        }
        hull[k] = points[j];
        k++;
    }
//
//     =========================================================================

    cout << "-----------" << endl;
    cout << "Convex Hull" << endl;
    cout << "-----------" << endl;
    hull.resize(k - 1);
    for (int i = 0; i < hull.size(); ++i) {
        cout << hull[i].x << " " << hull[i].y << endl;
    }


    cout << "\n" << is_clockwise({2,3}, {7,3}, {8,7});


}