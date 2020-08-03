class Solution {
public:
    int findKth(vector<int>& nums1, vector<int>& nums2, int st1, int st2, int kth) {
      if (st1 >= nums1.size()) return nums2[st2 + kth - 1];
      if (st2 >= nums2.size()) return nums1[st1 + kth - 1];
      if (kth == 1) return min(nums1[st1], nums2[st2]);

      int count = kth >> 1;
      int val[2]{nums1.back(), nums2.back()};
      int move[2]{count, count};

      if (st1 + count - 1 < nums1.size()) val[0] = nums1[st1 + count - 1];
      else move[0] = nums1.size() - st1;

      if (st2 + count - 1 < nums2.size()) val[1] = nums2[st2 + count - 1];
      else move[1] = nums2.size() - st2;

      if (val[0] < val[1]) return findKth(nums1, nums2, st1 + count, st2, kth - move[0]);
      else return findKth(nums1, nums2, st1, st2 + count, kth - move[1]);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int n = nums1.size();
      int m = nums2.size();
      int tot = n + m;
      int idx[2]{(tot+1)/2, (tot+2)/2};
      int val[2]{0,0};
      val[0] = findKth(nums1, nums2, 0, 0, idx[0]);
      val[1] = findKth(nums1, nums2, 0, 0, idx[1]);
      return 1. * (val[0] + val[1]) / 2;
    }
};
