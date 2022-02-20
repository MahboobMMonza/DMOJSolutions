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
        int n = nextInt(), m = nextInt(), count = 0;
        HashSet<String> items = new HashSet<>();
        for (int i = 0; i < n; i++) {
            items.add(readLine());
        }
        for (int i = 0; i < m; i++) {
            int s = nextInt();
            boolean flag = true;
            for (int j = 0; j < s; j++) {
                if (!items.contains(readLine())) {
                    flag = false;
                }
            }
            if (flag) count++;
        }
        System.out.println(count);
    }
}