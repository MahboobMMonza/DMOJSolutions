import java.io.*;
import java.util.*;

public class Rovarspraket {

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
        String user = readLine().toLowerCase();
        int underscores = user.replaceAll("[^_]", "").length();
        String[] name = user.split("_");
        StringBuilder sb = new StringBuilder();
        for (String s : name) {
            sb.append(s);
        }
        if ((sb.toString()).equals("darcyliu")) {
            if (underscores == 1) System.out.println("real");
            else System.out.println("fake");
        } else System.out.println("other user");
    }
}