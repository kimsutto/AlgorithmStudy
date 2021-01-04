import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        
        Scanner in = new Scanner(System.in);
        
        int T = in.nextInt();
        
        for(int i= 0; i<T; i++){
            int H = in.nextInt();
            int W = in.nextInt();
            int N = in.nextInt();
            int floor = N%H, room = N/H+1;
            if(N%H==0){
                floor=H;
                room=N/H;    
            }
            System.out.println(floor*100 + room);
        }
    }
}