#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
    void sortLetters(string &chars) {
        int from = 0;
        int end = chars.length() - 1;
        // cout << from << " " << endl;

        while (from < end)
        {
            // cout << from << " " << end << endl;
            while (chars[from] >= 'a' && chars[from] <= 'z' && from < end)
                from++;
            while (chars[end] >= 'A' && chars[end] <= 'Z' && from < end)
                end--;

            char ch = chars[from];
            chars[from] = chars[end];
            chars[end] = ch;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string str = "thisISaTest";
    solution.sortLetters(str);

    return 0;
}

/*
Description
Given a string which contains only letters. Sort it by lower case first and upper case second.
*/
