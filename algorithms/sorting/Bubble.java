package sorting;

/**
 * Created by wuzhenxing on 2014/8/3.
 */
public class Bubble {
    public void sort(Comparable[] a) {
        for (int i = a.length - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (less(a[j + 1], a[j]))
                    exch(a, j + 1, j);
            }
        }
    }

    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    private static void exch(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}
