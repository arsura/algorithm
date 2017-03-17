#include <iostream>
#include <map>

using namespace std;

int Max(int *a, int left, int right)
{
    if (right - left == 0) {
        return a[right];
    }
    if (right - left == 1) {
        return a[left] < a[right] ? a[right] : a[left];
    }

    int mid = (left + right) / 2;
    int left_Max = Max(a, left, mid);
    int right_Max = Max(a, mid + 1, right);

    return left_Max < right_Max ? right_Max : left_Max;

}

int Max1(int *a, int right)
{
    int max1, max2;
    if (right == 1) return a[right];

    if (a[right - 1] < a[right]) {
        max1 = a[right];
    }
    else {
        max1 = a[right - 1];
    }

    if (right > 2) {
        max2 = Max1(a, right - 2);
        max1 = (max1 < max2) ? max2 : max1;
    }
    return max1;

}

int main()
{
    int a[] = {100000, 10, 100, 100, 5, 1000};
    cout << Max(a, 0, 5) << endl;
    cout << Max1(a, 5) << endl;


}
