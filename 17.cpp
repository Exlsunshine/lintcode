#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector< vector<int> > subsets(vector<int> &nums) {
        vector<int> v;
        vector< vector<int> > ret;

        if (nums.size() == 0)
        {
            // set only got zero element
            ret.push_back(nums);
        }
        else if (nums.size() == 1)
        {
            // set only got one element
            ret.push_back(nums);
            ret.push_back(v);
        }
        else
        {
            vector<int> in;
            vector< vector<int> > out;

            for (int j = 1; j < nums.size(); j++)
                in.push_back(nums[j]);

            out = subsets(in);

            // save subsets
            for (int j = 0; j < out.size(); j++)
                ret.push_back(out[j]);

            // save i + subsets
            for (int j = 0; j < out.size(); j++)
            {
                out[j].push_back(nums[0]);
                ret.push_back(out[j]);
                sort(ret[ret.size() - 1].begin(), ret[ret.size() - 1].end());
            }
        }

        return ret;
    }


    void printVector(vector<int> v)
    {
        for (int j = 0; j < v.size(); j++)
            cout << v[j] << " ";
        cout << endl;
    }
};


int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector< vector<int> > vOut;

    vOut = solution.subsets(v);
    for (int i = 0; i < vOut.size(); i++)
    {
        for (int j = 0; j < vOut[i].size(); j++)
            cout << vOut[i][j] << " ";
        cout << endl;
    }

    return 0;
}

/*
Description
Given a set of distinct integers, return all possible subsets.

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Have you met this question in a real interview?  
Example
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Challenge
Can you do it in both recursively and iteratively?
*/
