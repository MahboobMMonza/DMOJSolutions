import java.io.*;
import java.util.*;

public class SteamArithmetic {

    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static char readChar() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
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

    public static void main(String[] args) throws IOException {
        String[] in;
        for (int t = 0; t < 10; t++) {
            in = readLine().replaceAll("[()]", "").split(" ");
            Stack<Integer> c = new Stack<>();
            for (int i = in.length - 1; i >= 0; i--) {
                if (in[i].matches("[\\d]")) {
                    c.push(Integer.parseInt(in[i]));
                } else {
                    switch (in[i].charAt(0)) {
                        case '+':
                            c.push(c.pop() + c.pop());
                            break;
                        case '-':
                            c.push(c.pop() - c.pop());
                            break;
                        case 'q':
                            c.push(c.pop() / c.pop());
                            break;
                        case 'r':
                            c.push(c.pop() % c.pop());
                            break;
                        case '*':
                            c.push(c.pop() * c.pop());
                            break;
                    }
                }
            }
            System.out.println(c.pop());
        }
    }
}