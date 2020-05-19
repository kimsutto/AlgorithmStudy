import java.util.HashMap;
class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        
        HashMap<String, Integer> hm = new HashMap<String, Integer>(); //종류별로 같은 이름의 옷은 없으므로, Hashmap<종류(String), 등장횟수(Integer)>를 이용
        
        for(int i=0; i<clothes.length; i++){
            if(hm.containsKey(clothes[i][1])) 
                hm.replace(clothes[i][1], hm.get(clothes[i][1])+1); //그 이후 등장부터는 기존 값에 1을 더한다.
            else
                hm.put(clothes[i][1],1);  //처음 등장하는 key는 등장 횟수 1로 설정
        }
        
        for(int value : hm.values()) {
            answer*=(value+1); //입을 수 있는 옷 종류의 수는 각 종류별로 선택할지 안할지 여부(+1)을 포함하여  (A종류 옷 가지수+1)*(B종류 옷 가지수+1)*(C종류 옷 가지수+1)-1 ... 로 구현할 수 있다. 
        }
        answer-=1; //마지막의 -1은 아무것도 선택하지 않은 경우는 없어야하므로, 제외
        
        return answer;
    }
}