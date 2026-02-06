import java.util.Scanner;

public class MenuProgram {
    public static void main (String [] args ) {
          Scanner sc = new Scanner (System.in ) ;
          int choice;
          
          do {
              //System.out.println ("\n -- Menu --");
              System.out.println ("1. Check Even or Odd ");
              System.out.println ("2. Print Multiplication Table ");
              System.out.println ("3. Check Prime Number ");
              System.out.println ("4. Check Perfect Number ");
              System.out.println ("5. Exit ");
              System.out.println (" Enter Your Choice : ");
              
              choice = sc.nextInt () ;
              if (choice >= 1 && choice <= 4 ) {
                 System.out.println (" Enter your Number:" );
                 int num = sc.nextInt ();

               switch (choice) {
                    case 1:
                        if (num % 2 == 0)
                            System.out.println(num + " is Even");
                        else
                            System.out.println(num + " is Odd");
                        break;

                    case 2:
                        System.out.println("Multiplication Table of " + num);
                        for (int i = 1; i <= 10; i++) {
                            System.out.println(num + " x " + i + " = " + (num * i));
                        }
                        break;

                    case 3:
                        boolean isPrime = true;
                        if (num <= 1) {
                            isPrime = false;
                        } else {
                            for (int i = 2; i <= num / 2; i++) {
                                if (num % i == 0) {
                                    isPrime = false;
                                    break;
                                }
                            }
                        }
                        if (isPrime)
                            System.out.println(num + " is a Prime number");
                        else
                            System.out.println(num + " is NOT a Prime number");
                        break;

                    case 4:
                        int sum = 0;
                        for (int i = 1; i <= num / 2; i++) {
                            if (num % i == 0)
                                sum += i;
                        }
                        if (sum == num)
                            System.out.println(num + " is a Perfect number");
                        else
                            System.out.println(num + " is NOT a Perfect number");
                        break;
                }
            } else if (choice == 5) {
                System.out.println("Exiting program...");
            } else {
                System.out.println("Invalid choice! Try again.");
            }

        } while (choice != 5);

        sc.close();
    }
}

