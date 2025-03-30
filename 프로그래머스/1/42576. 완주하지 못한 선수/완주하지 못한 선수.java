import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer=null;
        Map<String,Integer>result = new HashMap<>();
        for(String name : participant){
            Integer num = result.get(name);
            if(num == null){
                result.put(name,1);    
            }else{
                result.put(name,1+num);
            }
            
        }
        for(String name : completion){
            result.put(name,result.get(name)-1);
        }
        for(String name : participant){
            int now = result.get(name);
            if(now>0){answer=name;break;}
        }
        return answer;
    }
}