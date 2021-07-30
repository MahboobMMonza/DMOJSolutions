import java.io.*;
import java.util.*;

public class Main {
    
    static boolean isPalindrome(String s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) return false;
        }
        return true;
    }
    
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String word = s.nextLine();
        int length = 0;
        for (int i = 0; i < word.length() - 1; i++) {
            for (int j = word.length(); j > i; j--) {
                if (isPalindrome(word.substring(i, j))) {
                    length = Math.max(length, j - i);
                    break;
                }
            }
        }
        System.out.println(length);
    }
}