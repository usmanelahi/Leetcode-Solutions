/*

    Time Complexity : O(N!*KlogK), In worst case when all element of Array(nums) will different then there will
    be N! permutations and N! function calls and for every permutation we have to check in Hash Table(set) for
    inserting which take O(KlogK) time .Where N is the size of the array(nums) and ! stands for factorial. K is
    the worst case size of Array(output). 

    Space Complexity: O(N!*N), In worst case when all element of Array(nums) will different, since we have to
    store all the possible solutions which are N! in size where N is the size of the array and ! stands for
    factorial.

    Solved using Array + BackTracking + Hash Table(set). 

*/


/***************************************** Approach 1 *****************************************/

class Solution {
private: 
    void permuteUnique(vector<int>& nums, set<vector<int>>& set, vector<int> temp, int index){
        if(index == nums.size()){
            set.insert(temp);
            return;
        }
        for(int i=index; i<temp.size(); i++){
            swap(temp[index], temp[i]);
            permuteUnique(nums, set, temp, index+1);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        set<vector<int>> set;
        permuteUnique(nums, set, temp, 0);
        for(auto it : set){
            output.push_back(it);
        }
        return output;
    }
};






/*

    Time Complexity : O(N!*K), In worst case when all element of Array(nums) will different then there will be N!
    permutations and N! function calls and for every permutation we have to check in Array(output) for
    duplicated which take O(K) time .Where N is the size of the array(nums) and ! stands for factorial. K is the
    worst case size of Array(output). 

    Space Complexity: O(N!*N), In worst case when all element of Array(nums) will different, since we have to
    store all the possible solutions which are N! in size where N is the size of the array and ! stands for
    factorial.

    Solved using Array + BackTracking. 

*/


/***************************************** Approach 2 *****************************************/

class Solution {
private: 
    void permuteUnique(vector<int>& nums, vector<vector<int>>& output, vector<int> temp, int index){
        if(index == nums.size()){
            output.push_back(temp);
            return;
        }
        for(int i=index; i<temp.size(); i++){
            swap(temp[index], temp[i]);
            bool isPresent = find(output.begin(), output.end(), temp) != output.end();
            if(isPresent){
                continue;
            }
            permuteUnique(nums, output, temp, index+1);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        permuteUnique(nums, output, temp, 0);
        return output;
    }
};







/*

    Time Complexity : O(N!), In worst case when all element of Array(nums) will different then there will be N!
    permutations and N! function calls. Where N is the size of the array(nums) and ! stands for factorial. 

    Space Complexity: O(N!*N), In worst case when all element of Array(nums) will different, since we have to
    store all the possible solutions which are N! in size where N is the size of the array and ! stands for
    factorial.

    Solved using Array + BackTracking. 

*/


/***************************************** Approach 3 *****************************************/

class Solution {
private: 
    void permuteUnique(vector<int>& nums, vector<vector<int>>& output, vector<int> temp, vector<bool>& visited){
        if(temp.size() == nums.size()){
            output.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(visited[i] || i>0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            permuteUnique(nums, output, temp, visited);
            temp.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        vector<int> temp;
        vector<bool> visited(nums.size(), 0); 
        permuteUnique(nums, output, temp, visited);
        return output;
    }
};
