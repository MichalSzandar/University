public interface Command<T extends Comparable<T>>{
    public void execute(T val, BST<T> tree);
}
