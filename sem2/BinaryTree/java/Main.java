import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        System.out.println("Choose data type:\n (1) Integer\n (2) Double\n (3) String\n");

        Scanner scanner = new Scanner(System.in);
        int choice = scanner.nextInt();

        switch(choice)
        {
            case 1:
                Parser<Integer> parserInt = new ParserInt();
                new Cli<Integer>(parserInt);
                break;
            case 2:
                Parser<Double> parserDouble = new ParserDouble();
                new Cli<Double>(parserDouble);
                break;
            case 3:
                Parser<String> parserString = new ParserString();
                new Cli<String>(parserString);
                break;
            default:
                System.out.println("Invalid choice. Please enter 1, 2, or 3.");
        }

        scanner.close();
    }
}