import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main{
    public static void main(String[] args) throws IOException {
      
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
        int n = Integer.parseInt(br.readLine());
        int result = Fibonacci(n); 
        System.out.println(result);
  }  
    public static int Fibonacci(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
}
