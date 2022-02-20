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
        LinkedList<Character> playlist = new LinkedList<>(Arrays.asList('A', 'B', 'C', 'D', 'E'));
        int b, n;
        while (true) {
            b = nextInt();
            n = nextInt();
            if (b == 4 && n == 1) {
                break;
            }
            switch (b) {
                case 1:
                    for (int i = 0; i < n; i++) {
                        playlist.addLast(playlist.removeFirst());
                    }
                    break;
                case 2:
                    for (int i = 0; i < n; i++) {
                        playlist.addFirst(playlist.removeLast());
                    }
                    break;
                case 3:
                    if (n % 2 == 1) {
                        char a = playlist.removeFirst(), c = playlist.removeFirst();
                        playlist.addFirst(a);
                        playlist.addFirst(c);
                    }
                    break;
            }
        }
        while (!playlist.isEmpty()) {
            System.out.print(playlist.removeFirst() + " ");
        }
    }
}