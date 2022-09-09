public class Student {
    private static int nextID = 999;
    //Static variable
    private String firstName;
    private String lastName;
    private int id;
    private double gpa;
    private int credits;
    //instance variables
    private static int getNextId() {
        //Method to return nextID and then increment it
        nextID++;
        return nextID;
    }
    public Student(String firstName, String lastName) {
        //Constructor with parameters
        this.firstName = firstName;
        this.lastName = lastName;
        this.id = getNextId();
        this.gpa = 0;
        this.credits = 0;

    }

    public int addCourse(int creditsCourse, String grade) {
        double exactGrade = 0;
        //Declaring this for later
        if (grade.equals("A")) {
            exactGrade = 4.00;
        } else if (grade.equals("A-")) {
            exactGrade = 3.70;
        } else if (grade.equals("B+")) {
            exactGrade = 3.30;
        } else if (grade.equals("B")) {
            exactGrade = 3.00;
        } else if (grade.equals("B-")) {
            exactGrade = 2.70;
        } else if (grade.equals("C+")) {
            exactGrade = 2.30;
        } else if (grade.equals("C")) {
            exactGrade = 2.00;
        } else if (grade.equals("C-")) {
            exactGrade = 1.70;
        } else if (grade.equals("D+")) {
            exactGrade = 1.30;
        } else if (grade.equals("D")) {
            exactGrade = 1.00;
        } else if (grade.equals("F")) {
            exactGrade = 0.00;
        }
        //Bunch of if statements to turn letter grade into a double
        gpa = ((gpa * credits) + (exactGrade * creditsCourse)) / (credits + creditsCourse);
        //Calculation to determine gpa
        if (grade != "F") {
            credits = credits + creditsCourse;
            return credits;
            //If they did not fail the course, then add the credits onto their total credits
        } else {
            return credits;
            //If they did fail it, then don't add it on
        }
    }
    public void report() {
        System.out.print(firstName + ", " + lastName + "      " + id + "      ");
        System.out.print(String.format("%.2f", gpa));
        System.out.println("        " + credits);
        //Prints out all the info
        //Formats the gpa answer to two decimal places
    }
    public boolean canGraduate() {
        if (credits >= 120 && gpa >= 2.0) {
            return true;
        } else {
            return false;
        }
        //Method to determine whether they can graduate
    }
}