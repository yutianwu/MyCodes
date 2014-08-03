package strings;

import fundamentals.Queue;

/**
 * Created by wuzhenxing on 2014/7/31.
 */
public class TrieST<Value> {
    private static int R = 256;
    private Node root;

    private static class Node {
        private Object val;
        private Node[] next = new Node[R];
    }

    public Value get(String key) {
        Node x = get(root, key, 0);
        if (x == null) return null;
        return (Value) x.val;
    }

    public int size() {
        return size(root);
    }

    public Iterable<String> keys() {
        return keysWithPrefix("");
    }

    public Iterable<String> keysWithPrefix(String pre) {
        Queue<String> q = new Queue<String>();
        collect(get(root, pre, 0), pre, q);
        return q;
    }

    private void collect(Node x, String pre, Queue<String> q) {
        if (x == null)
            return;

        if (x.val != null)
            q.enqueue(pre);

        for (char c = 0; c < R; c++)
            collect(x.next[c], pre + c, q);
    }

    private int size(Node x) {
        if (x == null)
            return 0;

        int cnt = 0;
        if (x.val != null)
            cnt++;

        for (char c = 0; c < R; c++)
            cnt += size(x.next[c]);

        return cnt;
    }

    private Node get(Node x, String key, int d) {
        //如果碰到节点为空，即没找到，返回null
        if (x == null)
            return null;

        //如果已经找完了key的最后一个字符，然后就返回该节点
        if (d == key.length())
            return x;
        char c = key.charAt(d);
        return get(x.next[c], key, d+1);
    }

    public void put(String key, Value val) {
        root = put(root, key, val, 0);
    }

    private Node put(Node x, String key, Value val, int d) {
        if (x == null)
            x = new Node();

        if (d == key.length()) {
            x.val = val;
            return x;
        }

        char c = key.charAt(d);
        x.next[c] = put(x.next[c], key, val, d + 1);
        return x;
    }

    public Iterable<String> keysThatMatch(String pat) {
        Queue<String> q = new Queue<String>();
        collect(root, "", pat, q);
        return q;
    }

    //使用pre来记录现在已经查找到第几个字符了
    public void collect(Node x, String pre, String pat, Queue<String> q) {
        int d = pre.length();
        if (x == null)
            return;

        if (d == pat.length() && x.val != null)
            q.enqueue(pre);

        if (d == pat.length()) return;

        char next = pat.charAt(d);
        for (char c = 0; c < R; c++) {
            if (next == '.' || next == c)
                collect(x.next[c], pre + c, pat, q);
        }
    }

    public String longestPrefixOf(String s) {
        int length = search(root, s, 0, 0);
        return s.substring(0, length);
    }

    private int search(Node x, String s, int d, int length) {
        if (x == null)
            return length;

        if (x.val != null)
            length = d;

        if (d == s.length())
            return length;

        char c = s.charAt(d);
        return search(x.next[c], s, d+1, length);
    }

    public void delete(String key) {
        root = delete(root, key, 0);
    }

    private Node delete(Node x, String key, int d) {
        if (x == null)
            return null;

        //判断是否是最后一个字符，如果是，设置val为null
        //否则递归
        if (d == key.length()) {
            x.val = null;
        } else {
            char c = key.charAt(d);
            x.next[c] = delete(x.next[c], key, d+1);
        }

        //如果该节点有值，直接返回
        if (x.val != null)
            return x;

        //如果该节点没有值，判断是否有链接指向下一个节点，如果没有，返回空，
        for (char c = 0; c < R; c++) {
            if (x.next[c] != null)
                return x;
        }

        return null;
    }
}