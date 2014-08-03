package graphs;

/**
 * Created by wuzhenxing on 2014/7/25.
 */
public class DirectedDFS {
    private boolean[] marked;

    public DirectedDFS (Digraph G, int s) {
        marked = new boolean[G.V()];
        dfs(G, s);
    }

    private void dfs(Digraph G, int s) {
        marked[s] = true;
        for (int w : G.adj(s)) {
            if (!marked[w]) {
                dfs(G, w);
            }
        }
    }

    public boolean marked(int v) {
        return marked[v];
    }
}
