import java.util.*;

public class ColdCompress_Question4 {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int temp = -1; // This variable is to help me track the last time a new character was used, almost like a counter
        int numberOfLines = Integer.parseInt(input.nextLine());
        String[] sequences = new String[numberOfLines];

        for (int i = 0; i < numberOfLines; i++) {
            sequences[i] = input.nextLine();
        }
        for (int i = 0; i < numberOfLines; i++) {
            for (int j = 0; j < sequences[i].length(); j++) {

                if (j < (sequences[i].length() - 1)) {
                    if (sequences[i].charAt(j) != sequences[i].charAt(j + 1)) {
                        System.out.print(j - temp + " " + sequences[i].charAt(j) + " ");
                        temp = j;
                    }
                } else {
                    System.out.print(j - temp + " " + sequences[i].charAt(j));
                }

            }
            System.out.println();
            temp = -1; // Reset counter for next string
        }
    }
}