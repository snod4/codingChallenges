/**
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

class Solution {
public:
    struct valInfo{
        int val;
        int count = 0;
    }typedef valInfo_t;
    
    valInfo_t * find(int &val, vector<valInfo_t> &vec){
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].val == val){
                return &vec[i];
            }
        }
        return nullptr;
    }
    int majorityElement(vector<int>& nums) {
        int limit = nums.size()/2;
        
//Attempt 1
        // unordered_map<int, short> map;
        // for(int i = 0; i < nums.size(); i++){
        //     auto count = map.find(nums[i]);
        //     if(count != map.end()){
        //         map[nums[i]]+=1;
        //         if(map[nums[i]] > limit){
        //             return nums[i];
        //         }
        //     }
        //     else if(count == map.end()){
        //         map[nums[i]] = 1;
        //         if(map[nums[i]] > limit){
        //             return nums[i];
        //         }
        //     }
        // }
        // return 0;
        
//Attempt 2
        vector<valInfo_t> info;
        for(int i = 0; i < nums.size(); i++){
            valInfo_t * item = find(nums[i], info);
            if(item == nullptr){
                valInfo_t temp;
                temp.val = nums[i];
                temp.count+=1;
                info.push_back(temp);
            }
            else{
                item->count+=1;
            }
            
        }
        
        for(int i =0; i < info.size(); i++){
            if(info[i].count > limit){
                return info[i].val;
            }
        }
        

        
        return 0;
        
    }
};
