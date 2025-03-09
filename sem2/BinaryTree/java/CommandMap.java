import java.util.HashMap;

public class CommandMap<T extends Comparable<T>> 
{
    public CommandMap()
    {
        commandMap = new HashMap<>();
        configure();
    }

    private HashMap<String, Command<T>> commandMap;
    public Command<T> getCommand(String input){return commandMap.get(input);}
    public void addCommand(String input, Command<T> command){commandMap.put(input, command);}

    public void configure()
    {
        commandMap.put("i", new CommandInsert<T>());
        commandMap.put("s", new CommandSearch<T>());
        commandMap.put("p", new CommandPrint<T>());
        commandMap.put("q", new CommandQuit<T>());
        commandMap.put("d", new CommandDelete<T>());
    }

    public boolean isValidCommand(String input)
    {
        if(commandMap.containsKey(input)) return true;

        return false;
    }

}
