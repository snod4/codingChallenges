/**
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
 */


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        
        if(coordinates.size() == 2){
            return true;
        }
        
        
        int xVec = coordinates[1][0] - coordinates[0][0]; 
        int yVec = coordinates[1][1] - coordinates[0][1];
        int zVec = 0;
        for(int i = 1; i < coordinates.size() - 1; i++){
            int oxVec = coordinates[i+1][0] - coordinates[i][0];
            int oyVec = coordinates[i+1][1] - coordinates[i][1];
            int ozVec = 0;
            
         //   cout << yVec*ozVec - zVec*oyVec << " " << xVec*ozVec-zVec*oxVec << " " << xVec*oyVec - yVec*oxVec << endl;
            if(yVec*ozVec - zVec*oyVec != 0 || xVec*ozVec-zVec*oxVec != 0 || xVec*oyVec - yVec*oxVec != 0)
                    return false;
        }
        return true;
        
    }
};
