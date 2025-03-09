public class CommandSearch<T extends Comparable<T>> implements Command<T> {

    @Override
    public void execute(T val, BST<T> tree) {
        boolean exists = tree.search(val);
        if(exists)
            System.out.println("Element found");
        else
            System.out.println("Element not found");
    }
    
}
