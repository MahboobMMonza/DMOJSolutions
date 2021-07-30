import java.io.*;
import java.util.*;

public class Flipper_Question5 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String line = input.next();
        int[][] grid = {{1, 2}, {3, 4}};
        for (int i = 0; i < line.length(); i++) {
            if (line.charAt(i) == 'H') {
                horizontal(grid);
            } else {
                vertical(grid);
            }
        }
        for (int[] i : grid) {
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.println("");
        }

    }

    public static void horizontal(int[][] grid) {
        int[] temp = grid[0];
        grid[0] = grid[1];
        grid[1] = temp;

    }

    public static void vertical(int[][] grid) {
        int[] temp1 = {grid[0][1], grid[0][0]};
        int[] temp2 = {grid[1][1], grid[1][0]};
        grid[0] = temp1;
        grid[1] = temp2;

    }

}