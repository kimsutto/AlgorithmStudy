import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x = Integer.parseInt(br.readLine());
        
        int sum = factorial(x);
        System.out.println(sum);
        
    }
    
    public static int factorial(int x){
        if(x<=1) return 1;
        
        return x * factorial(x-1);
    }
}