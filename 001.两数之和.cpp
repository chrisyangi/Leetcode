/*
* ------------------------------------------------------
* Origin Link: https://leetcode-cn.com/problems/two-sum/
* About this solution , You will learn: 
* unordered_map -> find() , iterator (Using auto will better than iterator) , pointer to second
* vector        -> push_back() , Output can be substitude as { }
* hash content  -> By unordered_map , key is the input arrays's values , value is the input arrays's indexs
* time complexity : O(n)     space complexity : O(n)  
* ------------------------------------------------------
*/

#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

vector<int> getTargetCombine(vector<int> & nums , int target)
{
    // Key : nums value   Value : nums index
    unordered_map<int, int> hashTable;
    for(int i = 0 ; i < nums.size() ; ++i)
    {
        // Find the another part of "two sum"
        unordered_map<int, int>::iterator another_side = hashTable.find(target - nums[i]);
        // another_side will pointer to last element in unordered_map if it is not been found.
        if (another_side != hashTable.end())
        {
            // another_side->second will less than i because we set the value of i as key in hashTable at first.
            return {another_side->second , i};
        }
        hashTable[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> vec ;
    int target;             // target output of two sum.
    int len;                // input lens of vector
    cin >> len;
    int tmp;
    while(len--)
    {
        cin>>tmp;           // Adding the value into vector
        vec.push_back(tmp);
    }
    cin >> target;
    vector<int> out = getTargetCombine(vec , target);
    cout << '{'<<out[0] << ',' << out[1] << '}' << endl;
    cin.get();
    return 0;
}
