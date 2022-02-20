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
        int r = nextInt(), c = nextInt(), n;
        int col = 0;
        int[][] s = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                s[i][j] = nextInt();
            }
        }
        n = nextInt();
        for (int i = 0; i < n; i++) {
            col = nextInt();
            int finalc = col - 1;
            Arrays.sort(s, Comparator.comparingInt(o -> o[finalc]));
        }
        for (int i = 0; i < r; i++) {
            System.out.print(s[i][0]);
            for (int j = 1; j < c; j++) {
                System.out.print(" " + s[i][j]);
            }
            System.out.println();
        }
    }
}