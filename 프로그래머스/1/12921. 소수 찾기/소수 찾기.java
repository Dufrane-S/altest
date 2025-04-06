import java.util.*;
class Solution {
    public int solution(int n) {
        boolean [] check = new boolean[n+1];
        int answer = 0;
        
        for(int i=2;i<Math.sqrt(n);i++){
            int k=2;
            while(i*k<=n){
                check[i*k]=true;
                k++;
            }
        }
        for(int i=2;i<=n;i++){
            if(!check[i])answer++;
            
        }
        return answer;
    }
}