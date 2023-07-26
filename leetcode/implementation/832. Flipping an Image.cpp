class Solution {
public:
    void flipHorizontally(vector<vector<int>> &image){
        for(auto &im : image) {
            reverse(im.begin(),im.end());
        }
    }

    void reverseHorizontally(vector<vector<int>> &image) {
        for(auto &im : image) {
            for(auto &i : im) {
                i = !i;
            }
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        flipHorizontally(image);
        reverseHorizontally(image);
        return image;
    }
};