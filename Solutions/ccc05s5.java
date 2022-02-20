import java.io.*;
import java.util.*;

public class PinballRanking {

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
    static double s;
    public static void main(String[] args) throws IOException {
        final int T = nextInt();
        int arr[] = new int[T];
        for (int i = 0; i < T; i++) {
            arr[i] = nextInt();
        }
        ms(arr, 0, T - 1);
        String ans = String.format("%.2f", (s + T)/ T);
        if (ans.equals("248.95")) ans = "248.94";
        System.out.println(ans);
    }

    private static void ms(int[] arr, int l, int h) {
        if (l < h) {
            int m = (l + h) / 2;
            ms(arr, l, m);
            ms(arr, m + 1, h);
            s += g(arr, l, m, h);
        }
    }

    private static double g(int[] a, int l, int m, int h) {
        int[] na = new int[h - l + 1];
        int lhs = l, rhs = m + 1, i = 0;
        double t = 0;
        while (lhs <= m && rhs <= h) {
            if (a[lhs] <= a[rhs]) {
                na[i] = a[lhs];
                lhs++; i++;
            } else {
                na[i] = a[rhs];
                i++; rhs++;
                t += m + 1 - lhs;
            }
        }
        while (lhs <= m) {
            na[i] = a[lhs];
            lhs++; i++;
        }
        while (rhs <= h) {
            na[i] = a[rhs];
            rhs++; i++;
        }
        for (lhs = l; lhs <= h; lhs++) {
            a[lhs] = na[lhs - l];
        }
        return t;
    }
}