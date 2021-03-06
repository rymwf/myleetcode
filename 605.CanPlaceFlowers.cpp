/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

 

Constraints:

    1 <= flowerbed.length <= 2 * 104
    flowerbed[i] is 0 or 1.
    There are no two adjacent flowers in flowerbed.
    0 <= n <= flowerbed.length
*/
#include "common.h"

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int ret{};
        if (flowerbed[0] == 0)
        {
            flowerbed[0] = 1;
            ret++;
        }
        for (size_t i = 1, len = flowerbed.size(); i < len; ++i)
        {
            //            if (flowerbed[i - 1] == 0)
            //            {
            //                if (flowerbed[i] == 0)
            //                {
            //                    flowerbed[i] = 1;
            //                    ret++;
            //                }
            //            }
            //            else if (flowerbed[i] == 1)
            //            {
            //                ret--;
            //            }
            int a = flowerbed[i - 1] + flowerbed[i];
            if (a == 0)
            {
                flowerbed[i] = 1;
                ret++;
            }
            else if (a == 2)
                ret--;
        }
        return ret >= n;
    }
    bool canPlaceFlowers2(vector<int> &flowerbed, int n){
        int count{};
        int len = flowerbed.size() - 1, i = 0;
        while(i < len)
        {
            if (flowerbed[i] == 1)
            {
                i += 2;
            }
            else if (flowerbed[i + 1] == 0)
            {
                count++;
                i += 2;
            }
            else
            {
                i += 3;
            }
        }
        if (i == len && flowerbed[len] == 0)
            count++;
        return count >= n;
    }
};

int main()
{

    vector<int> a = {1, 0, 0, 0, 1, 0, 0};
    int n = 2;
    Solution s;
    s.canPlaceFlowers2(a, n);
}
