#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>
#define nl '\n'
#define all(v) (v).begin(), (v).end()

class Solution
{
public:
    int neg = -1, pos = -1;
    void binarySearch(vector<int> nums, int s, int e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] < 0)
        {
            s = mid + 1;
            neg = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        if (s > e)
            return;
        binarySearch(nums, s, e);
    }
    void binarySearch2(vector<int> nums, int s, int e)
    {
        int mid = s + (e - s) / 2;
        //  cout<<s<<" "<<e<<" "<<mid<<endl;
        if (nums[mid] > 0)
        {
            e = mid - 1;
            pos = mid;
        }
        else
        {
            s = mid + 1;
        }

        if (s > e)
            return;
        binarySearch2(nums, s, e);
    }
    int maximumCount(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        binarySearch(nums, s, e);
        binarySearch2(nums, s, e);
        int t_neg, t_pos;
        if (neg == -1)
            t_neg = 0;
        else
            t_neg = neg;
        if (pos == -1)
            t_pos = 0;
        else
            t_pos = nums.size() - pos;

        return max(t_neg, t_pos);
    }
};

int main()
{
    int c;
    
}