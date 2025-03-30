import java.util.*;
class Solution {
    public int solution(int[] nums) {
        Map<Integer,Integer>map = new HashMap<>();
        for(int now : nums){
            map.put(now,0);
        }
        int answer = 0;
        if(map.size()>nums.length/2){
            answer = nums.length/2;
        }else{
            answer = map.size();
        }
        
        return answer;
    }
}