import java.io.*;
import java.util.*;

public class CountTheTriplets {

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
        final int N = nextInt();
        int[] arr = new int[N];
        HashSet<Integer> u = new HashSet<>(), c = new HashSet<>();
        for (int i = 0; i < N; i++) {
            arr[i] = nextInt();
            u.add(arr[i]);
        }
        Arrays.sort(arr);
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                if (u.contains(arr[j] + arr[i])) {
                    c.add((arr[i] + arr[j]) * arr[j]);
                }
            }
        }
        System.out.println((c.size() == 0) ? -1 : c.size());
    }
}