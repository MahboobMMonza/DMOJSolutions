import java.io.*;
import java.util.*;

public class SimpleEncryption {

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
        String e = readLine().replaceAll("[\\W]", "");
        int x;
        for (int i = 0; i < e.length(); i++) {
           x = e.charAt(i) - 'A' + s.charAt(i % s.length());
           if (x > 90) x -= 26;
            System.out.print((char)(x));
        }
    }
}