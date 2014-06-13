public class Merge {
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

	public static void sort(Comparable[] a) {
		aux = new Comparable[a.length];
		sort(a, 0, a.length - 1);
	}

	public static void sort(Comparable[] a, int lo, int hi) {
		if (lo >= hi) return;

		int mid = lo + (hi - lo)/2;
		sort(a, lo, mid);
		sort(a, mid + 1, hi);
		merge(a, lo, mid, hi);
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
		sort(a);
		assert isSorted(a);
		show(a);
	}
}