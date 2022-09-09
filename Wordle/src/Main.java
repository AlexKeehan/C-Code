import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        ArrayList<String> words = new ArrayList<>();
        //Create new ArrayList
        FileInputStream fileIn;
        //Define fileIn before try catch block for scope
        try {
            fileIn = new FileInputStream("words.txt");
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
            return;
        }
        //Try catch block for reading in the file
        Scanner input = new Scanner(fileIn);
        //Creating new scanner

        while (input.hasNextLine()) {
            String lines = input.nextLine();
            words.add(lines);
        }
        //Reading in the file into the ArrayList words
        String keyword = randNumGenerator(words);
        //Calling the randNumGenerator method to get the keyword
        System.out.println("You have six tries to guess a five-letter word.");
        input = new Scanner(System.in);
        int lives = 6;
        //Setting the number of lives user starts with
        while (lives > 0) {
            //While loop where everything happens
            System.out.println("What is your guess?");
            //Asking for user's guess
            String guess = input.nextLine();
            //Setting variable guess equal to user's guess
            System.out.println("Your guess was: " + guess);
            //Letting them know their guess
            if (words.contains(guess)) {
                //If the guess is a valid guess
                if (guess.equals(keyword)) {
                    //If they guess it correctly
                    System.out.println("Congratulations, you got it");
                    break;
                } else {
                    //If they don't guess it correctly
                        for (int i = 0; i < 5;i++) {
                            //For loop to cycle through all chars in guess/keyword
                            char answer = keyword.charAt(i);
                            //Setting variable answer equal to each char in keyword
                            char attempt = guess.charAt(i);
                            //Setting variable attempt equal to each char in guess
                            if (attempt == answer) {
                                //If they guessed a letter right
                                System.out.println(attempt + " is right!");
                            } else if (keyword.indexOf(attempt) != -1) {
                                //If they did not guess the letter right, but the guess letter is in the keyword
                                System.out.println("There is a " + attempt + " but not here.");
                            } else {
                                //If they did not get anything right
                                continue;
                            }
                        }
                    lives --;
                        //Subtracts a life
                    System.out.println("You now have " + lives + " guesses left.");
                    //Lets user know how many lives they have left
                }
            } else {
                //If it is not a valid guess
                System.out.println("Try again");
                continue;
            }
        }
        if (lives == 0) {
            //After the while loop ends, checks to see if they ran out of guesses or not
            System.out.println("Sorry, the word is " + keyword);
            //Prints the correct answer
        }
    }

        public static String randNumGenerator(ArrayList<String> words) {
        //Picks a random number/index to use, then sets keyword equal to the index of random number
        Random random = new Random();
        int rand = random.nextInt(words.size());
        String keyword = words.get(rand);
        return keyword;
    }
}