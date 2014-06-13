public class MergeBU {
	private static Comparable[] aux;

	//compare
	private static boolean less(Comparable v, Comparable w) {
		return v.compareTo(w) < 0;
	}

	public static boolean isSorted(Comparable[] a) {
		for (int i = 1; i < a.length; i++) {
			if (less(a[i], a[i-1])) 
				return false;
		}
		return true;
	}

	private static void show(Comparable[] a) {
		for (int i = 0; i < a.length; i++) {
			System.out.println(a[i]);
		}
	}

	public static void merge(Comparable[] a, int lo, int mid, int hi) {
		int i = lo, j = mid + 1;

		for (int k = lo; k <= hi; k++) 
			aux[k] = a[k];

		for (int k = lo; k <= hi; k++) {
			if (i > mid)	
				a[k] = aux[j++];
			else if (j > hi) 
				a[k] = aux[i++];
			else if (less(aux[i], aux[j])) 
				a[k] = aux[i++];
			else
				a[k] = aux[j++];
		}
	}

	public static void main(String[] args) {
		String[] a = StdIn.readAllStrings();
		int N = a.length;
		aux = new Comparable[N];
		for (int sz = 1; sz < N; sz += sz) {
			for (int lo = 0; lo < N - sz; lo += (sz + sz))
				merge(a, lo, lo + sz - 1, Math.min(lo + sz + sz - 1, N));
		}
		assert isSorted(a);
		show(a);
	}
}