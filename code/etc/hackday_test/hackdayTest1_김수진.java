class Solution {
    public String solution(int n, int[][] delivery) {
        String answer = "";
        char[] a = new char[n]; 
        for(int i=0; i<n;i++){
            a[i]='?';
        }
        
        for(int i=0; i<delivery.length; i++){
            if(delivery[i][2]==1){
                int first = delivery[i][0];
                a[first-1]= 'O';
                int second = delivery[i][1];
                a[second-1]= 'O';
            }
        }
        for(int j=0; j<delivery.length; j++){
            if(delivery[j][2]==0){
                int first = delivery[j][0];
                int second = delivery[j][1];
                
                if(a[first-1]=='O'){
                    a[second-1]='X';
                }else if(a[second-1]=='O'){
                    a[first-1]='X';
                }else{
                    if(a[first-1]!='X'){
                        a[first-1]='?';
                    }
                    if(a[second-1]!='X'){
                         a[second-1]='?';
                    }
                }
            }
        }
        
        for(int aa=0; aa<n;aa++){
            answer+= a[aa];
        }
        return answer;
    }
}
