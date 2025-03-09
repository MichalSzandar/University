public class CommandInsert<T extends Comparable<T>> implements Command<T>{
    @Override
    public void execute(T val, BST<T> tree) {
        tree.insert(val);
        System.out.println("Element inserted");
    }
}
