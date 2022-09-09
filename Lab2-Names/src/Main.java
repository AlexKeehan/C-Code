import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String args[]) {
        ArrayList<String> names = new ArrayList<>();
        Scanner in = new Scanner(System.in);
        boolean out = false;
        while(!out) {
            System.out.println("Please enter a string: ");
            String name = in.nextLine();
            if (name.equals("")) {
                out = true;
            } else {
                names.add(name);
            }
        }

        Collections.sort(names, String.CASE_INSENSITIVE_ORDER);

        for (int i = 0; i < names.size(); i++) {
            String getName = names.get(i);
            int comma = getName.indexOf(",");
            String lastName = getName.substring(0, comma);
            String firstName = getName.substring(comma+1);
            getName = firstName + " " +  lastName;
            names.set(i, getName);
        }
        int count = 1;
        for (String s : names) {
            System.out.println(count + ". " +  s);
            count++;
        }
    }
}
