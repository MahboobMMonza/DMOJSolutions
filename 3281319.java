import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

    static char readChar() throws IOException {
        return next().charAt(0);
    }
    
    public static void main(String[] args) throws IOException {
        final int N;
        N = nextInt();
        for (int n = 0; n < N; n++) {
            char[] s = readLine().toCharArray();
            Stack<Character> st = new Stack<>();
            for (int i = 0; i < s.length; i++) {
                if (s[i] == '(') st.push(s[i]);
                else if (s[i] == ')' && !st.isEmpty()) st.pop();
                else if (s[i] == ')' && st.isEmpty()) {
                    st.push(')');
                    break;
                }
            }
            System.out.printf("%s\n", st.isEmpty() ? "YES" : "NO");
        }
    }
}