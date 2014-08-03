package graphs;

/**
 * Created by wuzhenxing on 2014/7/24.
 */
public class DepthFirstSearch {
    private boolean[] marked;   //标记矩阵
    private int count;          //连通分量中节点的个数

    public DepthFirstSearch(Graph G, int s) {
        marked = new boolean[G.V()];
        dfs(G, s);
    }

    private void dfs(Graph G, int s) {
        count++;
        marked[s] = true;
        for (int w : G.adj(s)) {
            if (!marked[w]) {
                dfs(G, w);
            }
        }
    }

    public boolean marked(int w) {
        return marked[w];
    }

    public int count() {
        return count;
    }
}
