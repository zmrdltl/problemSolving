
class Solution {
     
    public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> rslt = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for(int p = 0 ; p < nums.length ; p++){ 
            if(p > 0 && nums[p-1] == nums[p]) continue;
            int l = p+1;
            int r = nums.length - 1;
            int sum = nums[p] * -1;
            while(l < r){
                if(nums[l] + nums[r] == sum){
                    rslt.add(Arrays.asList(nums[p], nums[l], nums[r]));
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }else if(nums[l] + nums[r] < sum){
                    l++;
                }else{
                    r--;
                }
            }
        }
         
        return rslt;
    }
}