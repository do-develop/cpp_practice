#include <bits/stdc++.h>

using namespace std;

/*two pointer solution
vector<int> twoSum(vector<int>& nums, int target)
{
    int start=0, last=nums.size()-1;
    sort(nums.begin(), nums.end());

    while(start < last)
    {
        int sum = nums[start] + nums[last];
        if(sum == target)
            break;
        else if (sum > target)
            last--;
        else
            start++;
    }
    return {start, last};
}
*/

vector<int> twoSum(vector<int>& nums, int target)
{
    map<int, int> num_map;
    vector<int> pairs;
    for(int i=0; i<nums.size(); ++i)
    {
        int complement = target - nums[i];
        if(num_map.find(complement) != num_map.end())
        {
            pairs.push_back(num_map.find(complement)->second); //matching item's index
            pairs.push_back(i); //current index
            break;
        }
        num_map.insert(pair<int, int>(nums[i], i));
    }
    return pairs;

}
int main()
{
    vector<int> nums = {1, 5, 3, 7, 8, 10, 11};
    vector<int> result = twoSum(nums, 12);
    cout << "Pair indices are: " << result[0] << " " << result[1] << endl;
}
