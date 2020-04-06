import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
               
        HashMap<String, Integer> m = new HashMap<String, Integer>();
        for(int i=0; i<clothes.length; i++){
            if(!m.containsKey(clothes[i][1])){
                m.put(clothes[i][1],1);
            }else {
                m.put(clothes[i][1],m.get(clothes[i][1])+1);
            }
        }
        int answer = 1;
        for (Integer i : m.values()) {
            answer = answer *(i+1);
        }
        return answer -1;
    }
}