/**
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.


 */

class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {
        cout << nums.size() <<endl;
        int lIndex = 0;
        int rIndex = nums.size()-1;
        int prevRIndex = nums.size() - 1;
        if(lIndex == rIndex){
            return nums[0];
        }
        if(nums[rIndex] != nums[rIndex-1]){
            return nums[rIndex];
        }
        if( nums[lIndex] != nums[lIndex+1])
        {
            return nums[lIndex];
        }
        
        while(true){
            rIndex = (rIndex-lIndex)/2 + lIndex;
           // cout<< rIndex << endl;
            if((rIndex == nums.size() - 1 && nums[rIndex] != nums[rIndex-1])
               || (rIndex < nums.size() - 1 && nums[rIndex] != nums[rIndex+1] && nums[rIndex] != nums[rIndex-1])){
                    return nums[rIndex];
            }
            if((lIndex == 0 && nums[lIndex] != nums[lIndex+1])
               || (lIndex > 0 && nums[lIndex] != nums[lIndex-1] && nums[lIndex] != nums[lIndex+1]))
            {
                return nums[lIndex];
            }
            
            
            if((rIndex + 1 - lIndex)%2 == 1){
               // cout<< "Odd" << endl;
               if(nums[rIndex] == nums[rIndex+1]){
                   if(nums[lIndex] == nums[lIndex+1]){
                        lIndex = rIndex;
                        rIndex = prevRIndex;
                   }
                   else{
                       prevRIndex = rIndex;
                   }
                }
                else{
                    if(nums[lIndex] != nums[lIndex+1]){
                        lIndex = rIndex;
                           rIndex = prevRIndex;
                    }
                    else{
                     prevRIndex = rIndex;
                    }
                }                  
                
            }   
            else{
              //   cout<< "Even" << endl;
                if(nums[rIndex] != nums[rIndex+1]){
                    if(nums[lIndex] == nums[lIndex+1]){
                        lIndex = rIndex;
                        rIndex = prevRIndex;
                    }
                    else{
                        prevRIndex = rIndex;
                    }
                }
                else{
                    if(nums[lIndex] != nums[lIndex+1]){
                        lIndex = rIndex;
                        rIndex = prevRIndex;
                    }
                    else{
                        prevRIndex = rIndex;
                    }
                }
            }
        }
        return 0;
    }
};
