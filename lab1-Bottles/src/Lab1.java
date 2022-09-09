import java.util.Scanner;

public class Lab1 {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        //Importing Scanner
        System.out.println("How many bottles to start with? ");
        //Asking for number of bottles
        int bottles = in.nextInt();
        //Storing bottles in int bottles
        System.out.println("What is your favorite beverage ");
        //Asking for beverage
        in.nextLine();
        //Clearing the space left by previous next()
        String beverage = in.nextLine();
        //Storing favorite beverage in String beverage
        int num = bottles;
        //Using num as a secondary bottles
        for (int i = bottles; i > 0; i--) {
            //For loop to iterate through the verses
            if (i == 2) {
                //if statement to handle the plurality of bottles/bottle
                System.out.println("2 bottles of " + beverage + " on the wall, 2 bottles of " + beverage + ". ");
                System.out.println("Take one down and pass it around, 1 bottle of " + beverage + " on the wall. ");
                //Handling the plurality of bottle

                System.out.println("1 bottle of " + beverage + " on the wall, 1 bottle of " + beverage + ". ");
                System.out.println("Take one down and pass it around, 0 bottles of " + beverage + " on the wall. ");
                //Handling the plurality of bottle again

                System.out.println("0 bottles of " + beverage + " on the wall, 0 bottles of " + beverage + ". ");
                System.out.println("Go to the store and buy some more, " + bottles + " bottles of " + beverage + " on the wall. ");
                //Final verse, using the original bottles variable
                break;
                //Just so it doesn't print an extra verse
            } else {
                System.out.println(num + " bottles of " + beverage + " on the wall, " + num + " bottles of " + beverage + ". ");
                num--;
                System.out.println("Take one down and pass it around, " + num + " bottles of " + beverage + " on the wall. ");
                //Goes through the rest of the verses without worrying about plurality
            }
        }
    }





}
