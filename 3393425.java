import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt(), count = 0;
        for (int i = a; i <= b; i++) {
            if (Math.sqrt(i) == (int) Math.sqrt(i) && Math.cbrt(i) == (int) Math.cbrt(i)) {
                count++;
            }
        }
        System.out.println(count);
    }
}