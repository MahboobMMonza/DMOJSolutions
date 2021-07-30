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
        int n = nextInt();
        boolean[][] cs = new boolean[n][n];
        ArrayList<String> s = new ArrayList<>();
        String l = "";
        String[] pages = new String[n];
        for (int i = 0; i < n; i++) {
            pages[i] = "";
            String ps = "";
            l = readLine();
            if (l.indexOf("http://") == 0 || l.indexOf("url") == 0) {
                ps = l;
                s.add(ps);
            }
            while (!(l = readLine()).equals("</HTML>")) {
                pages[i] += l;
            }
            pages[i] = pages[i].replace("\n", "");
        }
        for (int i = 0; i < n; i++) {
            String ps = s.get(i);
            if (pages[i].contains("A HREF=\"")) {
                while (pages[i].contains("A HREF=\"")) {
                    pages[i] = pages[i].substring(pages[i].indexOf("A HREF=\"") + 8);
                    String link = pages[i].substring(0, pages[i].indexOf("\""));
                    if (s.contains(link)) {
                        cs[s.indexOf(ps)][s.indexOf(link)] = true;
                    }
                    System.out.println("Link from " + ps + " to " + link);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                    if (cs[i][j]) {
                        for (int k = 0; k < n; k++) {
                            if (cs[j][k]) {
                                cs[i][k] = true;
                            }
                        }
                }
            }
        }
        while (!(l = readLine()).equals("The End")) {
            String f = "", t = "";
            f = l;
            t = l = readLine();
            if (cs[s.indexOf(f)][s.indexOf(t)]) {
                System.out.println("Can surf from " + f + " to " + t + ".");
            } else {
                System.out.println("Can't surf from " + f + " to " + t + ".");
            }
        }
    }
}