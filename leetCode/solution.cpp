/**

 Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples: 
 */


class Solution {
public:
    typedef struct strInfo{
        int repeat = 0;
        int order = -1;
    }strInfo_t;
    
    int firstUniqChar(string s) {
        
                if(s.length() == 0){
            return -1;
        }
        
        strInfo_t countArr['z' - 'a' + 1];
        
        int order = 0;
        for(int i = 0; i < s.length(); i++){
            char relativeIndex = s[i] - 'a';
            if(countArr[relativeIndex].repeat == 0){
                countArr[relativeIndex].repeat = i+1;
                countArr[relativeIndex].order = order;
                order++;
            }
            else if(countArr[relativeIndex].repeat > 0){
                countArr[relativeIndex].repeat = -1;
                countArr[relativeIndex].order = -1;
                
            }
        }
        int lowestOrder = 'z' - 'a' + 1;
        int index = -1;
        for(int i = 0; i < 'z' - 'a' + 1; i++){
            if(countArr[i].order >= 0 && countArr[i].order < lowestOrder){
                index = countArr[i].repeat-1;
                lowestOrder = countArr[i].order;
            }
        }
        
        return index;
        
        
      
    }
};
