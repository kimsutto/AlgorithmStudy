import java.util.Scanner;

public class Main{
    
    public static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        
        sb.append((int)(Math.pow(2,N)-1)).append('\n');
        
        Hanoi(N,1,2,3);
        System.out.println(sb);  
    }
    
    public static void Hanoi(int N, int start, int mid, int end){
        if(N==1){
            sb.append(start + " " + end + "\n");
            return;
        }
        //n-1개 start->mid
        Hanoi(N-1, start, end, mid);
        
        //1개 start->end
        Hanoi(1, start, mid, end);
        
        //n-1개 mid->end
        Hanoi(N-1, mid, start, end);
    }
}