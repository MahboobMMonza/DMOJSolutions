import java.io.*;
import java.util.*;

public class Hearth {

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
        int N = nextInt(), T = nextInt();
        String[] cur, com = new String[3];
        Set<String> coms = new TreeSet<>();
        ArrayList<String[]> f = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            cur = readLine().split(" ");
            if (Integer.parseInt(cur[1]) < T - 2) {
                f.add(cur);
            }
        }
        for (int i = 0; i < f.size(); i++) {
            for (int j = 0; j < f.size(); j++) {
                for (int k = 0; k < f.size(); k++) {
                    if (k != j && j != i && k != i && Integer.parseInt(f.get(i)[1]) + Integer.parseInt(f.get(j)[1]) + Integer.parseInt(f.get(k)[1]) <= T) {
                        com[0] = f.get(i)[0];
                        com[1] = f.get(j)[0];
                        com[2] = f.get(k)[0];
                        Arrays.sort(com);
                        coms.add(String.format("%s %s %s", com[0], com[1], com[2]));
                    }
                }
            }
        }
        for (String s : coms) {
            System.out.println(s);
        }
    }
}