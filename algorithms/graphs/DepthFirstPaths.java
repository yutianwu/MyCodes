package graphs;
import fundamentals.Stack;

/**
 * Created by wuzhenxing on 2014/7/24.
 */
public class DepthFirstPaths {
    private boolean[] marked;
    private int[] edgeTo;
    private final int s;

    public DepthFirstPaths(Graph G, int s) {
        this.s = s;
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        dfs(G, s);
    }

    private void dfs(Graph G, int s) {
        marked[s] = true;
        for (int w : G.adj(s)) {
            if (!marked[w]) {
                dfs(G, w);
                edgeTo[w] = s;
            }
        }
    }

    public boolean hasPathTo(int v) {
        return marked[v];
    }

   public Iterable<Integer> pathTo(int v) {
       if (!hasPathTo(v)) return null;

       Stack<Integer> path =  new Stack<Integer>();
       for (int x = v; x != s; x = edgeTo[x]) {
           path.push(x);
       }

       return path;
   }
}