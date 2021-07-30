import java.io.*;
import java.util.*;

public class FourEver {

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

    public static HashMap<String, String> c = new HashMap<>();

    public static void main(String[] args) throws IOException {
        String s = readLine();
        c.put("1", "one");
        c.put("2", "two");
        c.put("3", "three");
        c.put("4", "four");
        c.put("5", "five");
        c.put("6", "six");
        c.put("7", "seven");
        c.put("8", "eight");
        c.put("9", "nine");
        c.put("10", "ten");
        c.put("11", "eleven");
        c.put("12", "twelve");
        c.put("13", "thirteen");
        c.put("14", "fourteen");
        c.put("15", "fifteen");
        c.put("16", "sixteen");
        c.put("17", "seventeen");
        c.put("18", "eighteen");
        c.put("19", "nineteen");
        c.put("20", "twenty");
        c.put("30", "thirty");
        c.put("40", "forty");
        c.put("50", "fifty");
        c.put("60", "sixty");
        c.put("70", "seventy");
        c.put("80", "eighty");
        c.put("90", "ninety");
        printLength(s);
    }

    private static void printLength(String s) {
        boolean[] ph;
        char[] pl;
        int count;
        StringBuilder pr = new StringBuilder(s);
        do {
            if (pr.length() != 10) {
                while (pr.length() < 10) {
                    pr.insert(0, "0");
                }
            }
            ph = new boolean[10];
            pl = pr.toString().toCharArray();
            for (int i = 0; i < pl.length; i++) {
                if (pl[i] != '0') {
                    ph[i] = true;
                }
            }
            pr = new StringBuilder();
            if (ph[0]) {
                pr.append(c.get(pl[0] + ""));
                pr.append("billion");
            }
            if (ph[1]) {
                pr.append(c.get(pl[1] + ""));
                pr.append("hundred");
            }
            if (ph[2]) {
                if (pl[2] == '1') {
                    pr.append(c.get(pl[2] + "" + pl[3]));
                } else {
                    pr.append(c.get(pl[2] + "0"));
                }
            }
            if (ph[3]) {
                if (!(pl[2] == '1')) {
                    pr.append(c.get(pl[3] + ""));
                }
            }
            if (ph[1] || ph[2] || ph[3]) {
                pr.append("million");
            }
            if (ph[4]) {
                pr.append(c.get(pl[4] + ""));
                pr.append("hundred");
            }if (ph[5]) {
                if (pl[5] == '1') {
                    pr.append(c.get(pl[5] + "" + pl[6]));
                } else {
                    pr.append(c.get(pl[5] + "0"));
                }
            }
            if (ph[6]) {
                if (!(pl[5] == '1')) {
                    pr.append(c.get(pl[6] + ""));
                }
            }
            if (ph[4] || ph[5] || ph[6]) {
                pr.append("thousand");
            }
            if (ph[7]) {
                pr.append(c.get(pl[7] + ""));
                pr.append("hundred");
            }
            if (ph[8]) {
                if (pl[8] == '1') {
                    pr.append(c.get(pl[8] + "" +pl[9]));
                } else {
                    pr.append(c.get(pl[8] + "0"));
                }
            }
            if (ph[9] && pl[8] != '1') {
                pr.append(c.get(pl[9] + ""));
            }
            count = pr.length();
            System.out.println(count);
            pr = new StringBuilder();
            pr.append(count);
        } while (count != 4);
    }
}