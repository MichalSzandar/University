import java.util.Scanner;

public class Cli <T extends Comparable<T>>
{
    private BST<T> tree;
    private Parser<T> parser;
    private Scanner scanner;
    private CommandMap<T> commands;

    public Cli(Parser<T> parser)
    {
        this.parser = parser;
        commands = new CommandMap<>();
        scanner = new Scanner(System.in);
        tree = new BST<T>();
        run();
    }

    private void run()
    {
        System.out.println("list of commands:\n (p) - print\n (i) - insert\n (s) - search\n (d) - delete\n (q) - quit\n");
        while (true) {
            System.out.print("Enter command: ");
            String input = scanner.nextLine();
            String[] commandParts = input.split(" ");

            if (commandParts.length < 1) {
                System.out.println("Invalid input. Please enter a valid command.");
                continue;
            }

            String command = commandParts[0];
            if (!commands.isValidCommand(command)) {
                System.out.println("Invalid command. Please enter a valid command.");
                continue;
            }

            T value = null;
            if (commandParts.length > 1) {
                try {
                    value = parser.parse(commandParts[1]);
                } catch (Exception e) {
                    System.out.println("Invalid value. Please enter a valid value.");
                    continue;
                }
            }

            try
            {
                commands.getCommand(command).execute(value, tree);
            }catch(NullPointerException e)
            {
                System.out.println("Not enough parameters to run this command");
                continue;
            }
                
        }
    }
}
