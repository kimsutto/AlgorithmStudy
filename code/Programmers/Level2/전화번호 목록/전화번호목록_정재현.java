class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        String temp = "";
        
        for(int i=0; i<phone_book.length; i++){
            if(answer){
                for(int j=0; j<phone_book.length; j++){
                    if(i!=j && phone_book[i].length() <= phone_book[j].length()){
                        if(phone_book[i].equals(phone_book[j].substring(0,phone_book[i].length()))){
                            answer=false;
                            break;
                        }      
                    }
                }
            }
            else break;
        }
        return answer;
    }
}