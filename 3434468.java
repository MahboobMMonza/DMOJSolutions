import java.util.*;
import java.io.*;
public class homework {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), sum = 0, a[] = new int[n];
		for(int i=0; i<n; i++) {
			a[i] = readInt(); sum += a[i];
		}
		int half = sum / 2; boolean dp[] = new boolean[half + 1];
		dp[0] = true;
		for(int i=0; i<n; i++) {
			for(int j=half; j>=a[i]; j--)
				if(!dp[j]) dp[j] = dp[j-a[i]];
		}
		int max = 0;
		for(int i=half; i>=0; i--) {
			if(dp[i]) { max = i; break; }
		}
		System.out.println(sum - 2*max);
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}