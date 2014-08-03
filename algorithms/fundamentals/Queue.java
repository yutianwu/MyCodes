package fundamentals;

import java.util.Iterator;

/**
 * Created by wuzhenxing on 2014/7/24.
 */
public class Queue<Item> implements Iterable<Item> {
    private Node first;
    private Node last;
    private int N;

    private class Node {
        Node next;
        Item item;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public int size() {
        return N;
    }

    public void enqueue(Item item) {
        Node oldlast = last;
        last = new Node();
        last.item = item;
        last.next = null;

        if (isEmpty()) {
            first = last;
        } else {
            oldlast.next = last;
        }
        N++;
    }

    public Item dequeue() {
        Item item = first.item;
        first = first.next;
        if(isEmpty()) {
            last = null;
        }
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
