import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Sum {
    public static void main(String args[]) {
        // open the file
        FileReader reader;
        try {
            reader = new FileReader("data.txt");
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
            return;
        }

        // make a scanner from it
        Scanner in = new Scanner(reader);

        // read all the numbers
        int sum = 0;
        while (in.hasNext()) {
            try {
                sum += in.nextInt();
            } catch (InputMismatchException e) {
                String line = in.nextLine();
            }
        }

        // print the sum
        System.out.println("Sum is " + sum + ".");
    }
}
