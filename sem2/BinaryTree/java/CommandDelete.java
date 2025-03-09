public class CommandDelete<T extends Comparable<T>> implements Command<T> {

    @Override
    public void execute(T val, BST<T> tree) {
        tree.delete(val);
        System.out.println("Element deleted");
    }
    
}
