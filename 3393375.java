import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 1 ^ 6, 2 ^ 6, 3 ^, ... 21 ^ 6
        int a = sc.nextInt(), b = sc.nextInt(), count = 0;
        for (int i = 1; i < 22; i++) {
            int pow6 = i * i * i * i * i * i;
            if (pow6 <= b && pow6 >= a) {
                count++;
            }
        }
        System.out.println(count);
    }
}