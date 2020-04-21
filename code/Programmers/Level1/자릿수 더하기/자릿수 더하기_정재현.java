import java.util.*;

public class Solution {
    public int solution(int n) {
        int sum =0;
        String[] s = Integer.toString(n).split("");
        for(int i= 0; i<s.length; i++){
            sum+=Integer.parseInt(s[i]);
        }
        return sum;
    }
}