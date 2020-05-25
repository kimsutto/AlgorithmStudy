import java.util.*;
class Solution {
    public int solution(String arrangement) {
        int answer = 0;
        String copy = arrangement.replace("()","0");
        
        ArrayList<Character> copy2 = new ArrayList<Character>();
        
        for(int i=0; i<copy.length(); i++){
            copy2.add(copy.charAt(i));
        }
        ArrayList<Character> stack = new ArrayList<Character>();
        
        for(int i=0; i<copy2.size();i++){
            if(copy2.get(i)=='('){
                stack.add(copy2.get(i));
            }
            else if(copy2.get(i)==')'){
                stack.remove(stack.size()-1);
                answer+=1;
            }
            else if(copy2.get(i)=='0'){
                answer+=stack.size();
            }
        }
        return answer;
    }
}