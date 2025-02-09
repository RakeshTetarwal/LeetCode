#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n1 = nums1.size(), n2 = nums2.size();
        int l = 0, r = n1 - 1;
        int low = (n1 + n2 - 1) >> 1;
        while (l <= r)
        {
            int m1 = (l+r)>>1;
            int m2 = (n1+n2)>>1 - m -2;
            int l1 = (m1>=0)? nums1[m1]: INT_MIN;
            int l2 = (m2>=0)? nums2[m2]: INT_MIN;
            int r1 = (m1 + 1 < n1)? nums1[m1 + 1]: INT_MAX;
            int r2 = (m2 + 1 < n2)? nums1[m2 + 1]: INT_MAX;
            if (l1 <= r2 && l2 <= r1) {
                return ((n1 + n2) & 1) ? (min(r1, r2))
                                       : (max(l1, l2) + min(r1, r2)) / 2.00;
            } else if (l1 > r2) {
                r = m1 - 1;
            } else {
                l = m1 + 1;
            }
              /*
                                        Ex: n2=10, n1=4 m1=2 m2=5
                                            n2=10, n1=5 m1=2 m2=5
                                            n2=11, n1=4 m1=1 m2=6
                                            n2=11, n1=5 m1=2 m2=6
                                     */
        }
    }
};

int main()
{
    int n, m;
}
