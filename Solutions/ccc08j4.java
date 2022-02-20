import java.io.*;
import java.util.*;

public class PrePo {

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
        String s = readLine();
        Stack<String> n;
        String op1, op2;
        do {
            n = new Stack<>();
            for (int i = s.length() - 1; i >= 0; i--) {
                if (s.charAt(i) == '+' || s.charAt(i) == '-') {
                    op1 = n.pop();
                    op2 = n.pop();
                    n.push(op1 + " " + op2 + " " + s.charAt(i));
                } else if (s.charAt(i) != ' '){
                    n.push(s.charAt(i) + "");
                }
            }
            System.out.println(n.pop());
            s = readLine();
        } while (!s.equals("0"));
    }
}