import java.io.*;
import java.util.*;

public class DiabloBotSoln {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return (int) nextLong();
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static String rl() throws IOException {
        return br.readLine().trim();
    }

    static char readChar() throws IOException {
        return next().charAt(0);
    }

    public static void main(String[] args) throws IOException {
        int n = nextInt();
        String[] l;
        for (int i = 0; i < n; i++) {
            l = rl().toLowerCase().split(" ");
            if (l[0].endsWith("'s")) {
                System.out.println("Set");
            } else if (l[0].equals("damaged")) {
                System.out.println("Normal");
            } else if (l.length > 2 && l.length <= 4 && l[l.length - 2].equals("of")) {
                System.out.println("Magic");
            } else if (l.length == 2 && !l[0].equals("of")) {
                System.out.println("Not sure, take anyways");
            } else if (l.length == 2) {
                System.out.println("Rare");
            } else {
                System.out.println("Normal");
            }
        }
    }
}