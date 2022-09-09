import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Random;

public class Main {

    //Method to get the mean
    public static double calculateMean(ArrayList<Integer> numbers) {
        int sum = 0;

        for (Integer i : numbers) {
            sum += i;
        }

        return sum / numbers.size();
    }
    //Method to get the median
    public static double calculateMedian(ArrayList<Integer> numbers) {
        //sorts the list
        Collections.sort(numbers);
        if (numbers.size() % 2 == 0) {
            //Even length list
            int middle1 = numbers.size() / 2;
            int middle2 = middle1 - 1;
            return (numbers.get(middle1) + numbers.get(middle2)) / 2;

        } else {
            //Odd length list
            int middle = numbers.size() / 2;
            return numbers.get(middle);
        }
    }

    public static void main(String args[]) {
        ArrayList<Integer> numbers = new ArrayList<>();

        Scanner in = new Scanner(System.in);
        System.out.println("How many numbers would you like to enter?\n:");
        int count = in.nextInt();

        for (int i = 0; i < count; i++) {
            System.out.println("Enter next number.\n: ");
            int num = in.nextInt();
            numbers.add(num);
        }

        double mean = calculateMean(numbers);
        System.out.println("Mean " + mean);

    }

}
