class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        for(int i=0; i+1phone_book.length;i++){
            for(int j=i+1; jphone_book.length;j++){
                contains쓰면 시간 초과로 실패됨 
                if(phone_book[j].indexOf(phone_book[i])==0){
                    return false;
                }
                if(phone_book[i].indexOf(phone_book[j])==0){
                    return false;
                }
                
            }
            
        }
        
        return answer;
    }
}