package fundamentals;
import java.util.Iterator;

/**
 * Created by wuzhenxing on 2014/7/24.
 */
public class Stack<Item> implements Iterable<Item> {
    private Node first;
    private int N;

    private class Node {
        Item item;
        Node next;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public int size() {
        return N;
    }

    public void push(Item item) {
        Node oldfirst = first;
        first = new Node();
        first.item = item;
        first.next = oldfirst;
        N++;
    }

    public Item pop() {
        Item item = first.item;
        first = first.next;
        N--;
        return item;
    }

    public Iterator<Item> iterator() {
        return new ListIterator(first);
    }

    private class ListIterator implements Iterator<Item> {
        private Node current;

        public ListIterator(Node first) {
            current = first;
        }
        public boolean hasNext()  { return current != null;                     }

        public void remove()      { }

        public Item next() {
            if (!hasNext()) return null;
            Item item = current.item;
            current = current.next;
            return item;
        }
    }
}
