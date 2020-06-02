/**
 An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image. 
 */



class Solution {
public:
    struct Pixel{
        int r;
        int c;
    }typedef pixel_t;
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int startColor = image[sr][sc];
        queue<pixel_t> q;
        q.push({sr, sc});
        bool matrix[image.size()][image[0].size()];
        for(int r = 0; r < image.size(); r++){
            for(int c = 0; c < image[0].size(); c++){
                matrix[r][c] = false;
            }
        }
        
        do{
            
            pixel_t pix = q.front();
            int r = pix.r;
            int c = pix.c;
            //cout<< r << ", " << c << endl;
            image[r][c] = newColor;
            q.pop();
            
            if(r+1 < image.size() && matrix[r+1][c] == false && image[r+1][c] == startColor){
             //   cout<< "pushed first" << endl;
                q.push({r+1,c});
                matrix[r+1][c] = true;
             }
            if(r-1 >= 0 && matrix[r-1][c] == false && image[r-1][c] == startColor){
              //  cout<< "pushed second" << endl;
                q.push({r-1,c});
                matrix[r-1][c] = true;
            }
            if(c+1 < image[r].size() && matrix[r][c+1] == false && image[r][c+1] == startColor){
               // cout<< "pushed third" << endl;
                q.push({r,c+1});
                matrix[r][c+1] = true;
            }
            if(c-1 >= 0 && matrix[r][c-1] == false &&image[r][c-1] == startColor){
                //cout<< "pushed foruth" << endl;
                 q.push({r,c-1});
                matrix[r][c-1] = true;
            }
            

        }
        while(!q.empty());
        
        
        return image;
    }
};
