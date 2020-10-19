import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int sugar = in.nextInt();
        int five = 0;
        int three = 0;
        
        while(sugar%5!=0 && sugar>=0){
            sugar-=3;
            three++;
        }
        if(sugar<0){
            System.out.println(-1);
        }
        else{
            five = sugar/5;
            System.out.println(five+three);        
        }
    }
}