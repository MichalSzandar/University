public class CommandQuit<T extends Comparable<T>> implements Command<T> {

    @Override
    public void execute(T val, BST<T> tree) {
        System.out.println("exiting");
        System.exit(0);
    }
    
}
