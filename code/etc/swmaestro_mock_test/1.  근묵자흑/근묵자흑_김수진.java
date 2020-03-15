import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String firstLine = br.readLine();
		//String secondLine = br.readLine();
		
		String[] nk = firstLine.split(" ");
		int n = Integer.parseInt(nk[0]);   
		int k = Integer.parseInt(nk[1]);    

		int ans= 1;
		n-=k;
		while(n>=k){
			n-=(n+1)-k;
			ans++;
		}
		System.out.println(count);
	}
}