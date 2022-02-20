import java.io.*;
import java.util.*;

public class PoNo {

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
        String[] in = readLine().split(" ");
        Stack<Double> c = new Stack<>();
        double t, op1, op2;
        for (int i = 0; i < in.length; i++) {
            if (!in[i].matches("[+\\-*/%^]")) {
                c.push(Double.parseDouble(in[i]));
            } else {
                op1 = c.pop();
                op2 = c.pop();
                switch (in[i]) {
                    case "+":
                        t = op2 + op1;
                        c.push(t);
                        break;
                    case "-":
                        t = op2 - op1;
                        c.push(t);
                        break;
                    case "*":
                        t = op2 * op1;
                        c.push(t);
                        break;
                    case "/":
                        t = op2 / op1;
                        c.push(t);
                        break;
                    case "%":
                        t = op2 % op1;
                        c.push(t);
                        break;
                    case "^":
                        t = Math.pow(op2, op1);
                        c.push(t);
                        break;
                }
            }
        }
        System.out.printf("%.1f%n", c.pop());
    }
}