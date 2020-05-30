/**
Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.
 */
class Solution {
public:
     void printArray(int arr[]){
        for(int i =31; i >= 0; i--){
            cout << arr[i];
            
        }   
        cout << "\n";
    }
    int findComplement(int num) {
        
      //  cout << "Num: " << num << endl;
        int firstOneIndex = -1;
        int bitArr[32] = {0};
        for(int i = 31; i >= 0; i--){
            unsigned int power = 1U << i;  
            //cout << num << ", Power: " << power << "first INd: " << firstOneIndex <<  endl;
            if(num >= power){
                bitArr[i] = 0;
                num -= power;
                if(firstOneIndex == -1){
                    firstOneIndex = i;
                }
                
            }
            else{
                bitArr[i] = 1;
            }
           // printArray(bitArr);
            
        }
        
        int val = 0;
        for(int i = 0; i <= firstOneIndex; i++){
            int base = i;
            if(bitArr[i] == 1){
            int temp = 1 << base;
            val+= temp;
            }
        }
        
        return val;
    
    }
};
