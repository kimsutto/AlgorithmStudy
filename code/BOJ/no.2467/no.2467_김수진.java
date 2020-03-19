import java.io.*;
import java.util.StringTokenizer;


class Main {

	static int n, l, r;


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = stoi(st.nextToken());
		int[] kr = new int[n];

		for(int i=0; i<n; i++) {
			kr[i] = n;
		}
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			kr.put(stoi(st.nextToken()));
		}

		System.out.println(less());
	}

	private static String less() {
		int min = Integer.MAX_VALUE;
		int left = 0, right = kr.size - 1;
		while (left < right) {
			int mixture = Math.abs(kr.get(left) + kr.get(right));
			if (mixture < min) {
				min = mixture;
				l = kr[left];
				r = kr[right];
			}

			if ((kr[left]+kr[right])>0) {
				right--;
			} else {
				left++;
			}
		}
		return l + " " + r;
	}

	private static int stoi(String input) {
		return Integer.parseInt(input);
	}



}
