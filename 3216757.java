import java.io.*;
import java.util.*;

public class Spirals {

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
        int s = nextInt(), e = nextInt(), inc = 1, x = 4, y = 4;
        int[][] nums = new int[11][11];
        nums[x][y] = s++;
        while (s <= e) {
            for (int i = 0; i < inc; i++) {
                nums[++x][y] = s++;
                if (s > e) {
                    break;
                }
            }
            if (s > e) {
                break;
            }
            for (int i = 0; i < inc; i++) {
                nums[x][++y] = s++;
                if (s > e) {
                    break;
                }
            }
            if (s > e) {
                break;
            }
            inc++;
            for (int i = 0; i < inc; i++) {
                nums[--x][y] = s++;
                if (s > e) {
                    break;
                }
            }
            if (s > e) {
                break;
            }
            for (int i = 0; i < inc; i++) {
                nums[x][--y] = s++;
                if (s > e) {
                    break;
                }
            }
            if (s > e) {
                break;
            }
            inc++;
        }
        for (int i = 9; i > -1; i--) {
            for (int j = 9; j > -1; j--) {
                if (nums[i][j] == 0 && nums[i][j + 1] != 0 && nums[i + 1][j] != 0) nums[i][j] = -1;
            }
        }
        StringBuilder line;
        for (int i = 0; i < 11; i++) {
            line = new StringBuilder();
            for (int j = 0; j < 11; j++) {
                if (nums[i][j] == -1) {
                    line.append("   ");
                } else if (nums[i][j] != 0) {
                    if (nums[i][j] < 10) line.append(" ").append(nums[i][j]);
                    else line.append(nums[i][j]);
                    if (j + 1 != 11 && nums[i][j + 1] != 0) line.append(" ");
                }
            }
            if (line.length() != 0) System.out.println(line.toString());
        }
    }
}