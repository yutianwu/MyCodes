package strings;

/**
 * Created by wuzhenxing on 2014/8/3.
 */
public class BruteForce {
    public static int search1(String pat, String txt) {
        int M = pat.length();
        int N = pat.length();
        for (int i = 0; i < N - M; i++) {
            int j;
            for (j = 0; j < M; j++) {
                if (txt.charAt(i) != pat.charAt(j))
                    break;
            }
            //注意是 j==M，而不是j == M - 1
            if (j == M)
                return i;
        }

        return N;
    }

    public static int search2(String pat, String txt) {
        int j, M = pat.length();
        int i, N = txt.length();
        for (i = 0, j = 0; i < N && j < M; i++) {
            if (txt.charAt(i) == pat.charAt(j)) {
                j++;
            } else {
                i -= j;
                j = 0;
            }
        }

        if (j == M)
            return i - M;
        else
            return N;
    }
}
