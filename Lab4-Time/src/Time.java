
class Time {
    private int hours;
    private int minutes;
    private int seconds;

    public Time() {
        hours = 00;
        minutes = 00;
        seconds = 00;
    }

    public Time(int hours, int minutes, int seconds) {
        this.seconds = seconds;
        this.minutes = minutes;
        this.hours = hours;
    }

    public int increment(int numSeconds) {
        int time = numSeconds;
        int second = 00;
        while (time >= 0) {
            if (second >= 60) {
                minutes += 1;
                second -= 60;
            }
            if (minutes >= 60) {
                hours += 1;
                minutes -= 60;
            }
            time--;
            second++;
        }
        seconds = (numSeconds / 60) % 60;
        return hours + minutes + seconds;
    }

    public String print(boolean military) {
        if (military) {
            if (seconds == 0) {
                System.out.printf("%s0", hours + ":");
                System.out.printf("%s0", minutes + ":");
                System.out.println(seconds);
            } else {
                System.out.printf("%s0", hours + ":");
                System.out.print(minutes + ":");
                System.out.println(seconds);
            }
        } else {
            if (hours > 12) {
                if (seconds == 0) {
                    System.out.printf("%s0", hours - 12 + ":");
                    System.out.printf("%s0", minutes + ":");
                    System.out.println(seconds + " PM");
                } else {
                    System.out.printf("%s0", hours - 12 + ":");
                    System.out.print(minutes + ":");
                    System.out.println(seconds + " PM");
                }
            } else {
                if (seconds == 0) {
                    System.out.printf("%s0", hours + ":");
                    System.out.printf("%s0", minutes + ":");
                    System.out.println(seconds + " AM");
                } else {
                    System.out.printf("%s0", hours + ":");
                    System.out.print(minutes + ":");
                    System.out.println(seconds + " AM");
                }
            }
        }
        return "Invalid";
    }
}