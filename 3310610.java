import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int i = s.nextInt(), left = 0, right = 0, count = 0;
        if (i > 5) {
            right = 5;
            left = i - 5;
        } else {
            right = i;
        }
        while (right >= left) {
            count = count + 1;
            right -= 1; // right--
            left += 1; // left++
        }
        System.out.println(count);
    }
}