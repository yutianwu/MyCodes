package strings;

/**
 * Created by wuzhenxing on 2014/8/3.
 */
public class KMP {
    private String pat;
    private int[] pi;

    public KMP(String pat) {
        this.pat = pat;
        int M = pat.length();
        pi = new int[M];

        pi[0] = 0;
        int k = 0;

        for (int i = 1; i < M; i++) {
            while (k > 0 && pat.charAt(k) != pat.charAt(i))
                k = pi[k-1];

            if (pat.charAt(k) == pat.charAt(i))
                k = k + 1;

            pi[i] = k;
        }
    }

    public void search(String txt) {
        int N = txt.length();
        int M = pat.length();

        int q = 0;
        for (int i = 0; i < N; i++) {
            while (q > 0 && pat.charAt(q) != txt.charAt(i))
                q = pi[q-1];

            if (pat.charAt(q) == txt.charAt(i))
               q = q + 1;

            if (q == M) {
                System.out.println("pattern occurs with shift " + (i - M + 1));
                q = pi[q-1];
            }
        }
    }

    public static void main(String[] args) {
        String pat = "a";
        String txt = "aaaaa";
        KMP kmp = new KMP(pat);
        kmp.search(txt);
    }
}