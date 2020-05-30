/**
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomCount['z' - 'a' + 1] = {0};
        int magCount['z' - 'a' + 1] = {0};
        
        for(int i = 0; i < ransomNote.length(); i++){
            ransomCount[ransomNote[i] - 'a']++;
        }
        for(int i = 0; i < magazine.length(); i++){
            magCount[magazine[i] - 'a']++;
        }
        
        for(int i = 0; i < 'z' - 'a' + 1; i++){
            if(ransomCount[i] > magCount[i])
                return false;
        }     
        
        return true;
        
        
    }
};
