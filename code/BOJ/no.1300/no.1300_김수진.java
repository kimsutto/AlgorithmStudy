import java.io.*;


class Main {



	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int k = Integer.parseInt(br.readLine());

		int result = sort(n,k);
		System.out.println(result);
	}
	
	private int sort(int n, int k) {
		int i = 1;
		int kk = k;
		while(i<=kk){
			int mid = (i+kk) / 2;
			int cnt= 0;		
			for(int j=1; j<=n;j++){
				cnt += Math.min(mid/j, n);
			}
			if(cnt>=k){
				kk=mid -1 ;
				result = mid;
			}else{
				i = mid + 1;
			}
		}
		return result;
	}


}