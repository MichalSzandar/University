public class BST<T extends Comparable<T>> 
{
    private class Node
    {
        private T value;
        private Node left;
        private Node right;

        public Node(final T value)
        {
            this.value = value;
            right = null;
            left = null;
        }
    }

    Node root;

    public void insert(T val)
    {
        root = ins(val, root);
    }

    private Node ins(T val, Node node)
    {
        if(node == null) return new Node(val);
        if(val.compareTo(node.value) < 0) 
            node.left = ins(val, node.left);
        if(val.compareTo(node.value) > 0)
            node.right = ins(val, node.right);

        return node;
    }

    public boolean search(T val)
    {
        return find(val, root);
    }

    private boolean find(T val, Node node)
    {
        if(node == null) return false;
        if(val.compareTo(node.value) == 0) return true;
        if(val.compareTo(node.value) < 0)
            return find(val, node.left);
        else
            return find(val, node.right);
    }

    public void delete(T val) {
        root = deleteNode(root, val);
    }

    private Node deleteNode(Node node, T val) {
        if (node == null) return null;
        if (val.compareTo(node.value) < 0) {
            node.left = deleteNode(node.left, val);
        } else if (val.compareTo(node.value) > 0) {
            node.right = deleteNode(node.right, val);
        } else {

            if (node.left == null && node.right == null) {
                return null;
            }
            else if (node.left == null) {
                return node.right;
            } else if (node.right == null) {
                return node.left;
            }
            else {
                node.value = findMin(node.right);
                node.right = deleteNode(node.right, node.value);
            }
        }
        return node;
    }

    private T findMin(Node node) {
        while (node.left != null) {
            node = node.left;
        }
        return node.value;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        traverseNodes(sb, "", "", root, false);
        return sb.toString();
    }

    private void traverseNodes(StringBuilder sb, String padding, String pointer, Node node, boolean hasRightSibling) {
        if (node != null) {
            sb.append("\n");
            sb.append(padding);
            sb.append(pointer);
            sb.append(node.value);

            StringBuilder paddingBuilder = new StringBuilder(padding);
            if (hasRightSibling) {
                paddingBuilder.append("│  ");
            } else {
                paddingBuilder.append("   ");
            }

            String paddingForBoth = paddingBuilder.toString();
            String pointerRight = "└──";
            String pointerLeft = (node.right != null) ? "├──" : "└──";

            traverseNodes(sb, paddingForBoth, pointerLeft, node.left, node.right != null);
            traverseNodes(sb, paddingForBoth, pointerRight, node.right, false);
        }
    }

}
