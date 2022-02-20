import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class sssp {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static Vertex[] g;

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

    static char readChar() throws IOException {
        return next().charAt(0);
    }

    public static void main(String[] args) throws IOException {
        final int N = nextInt(), M = nextInt();
        int u, v, w;
        g = new Vertex[N + 1];
        HashSet<Integer> vis = new HashSet<>();
        PriorityQueue<Vertex> pq = new PriorityQueue<>();
        for (int i = 1; i <= N; i++) {
            g[i] = new Vertex(i);
        }
        g[1].d = 0;
        for (int i = 0; i < M; i++) {
            u = nextInt();
            v = nextInt();
            w = nextInt();
            g[u].ue(v, w);
            g[v].ue(u, w);
        }
        pq.add(g[1]);
        while (!pq.isEmpty()) {
            Vertex c = pq.remove();
            vis.add(c.num);
            for (Map.Entry<Integer, Integer> e : c.getEdges().entrySet()) {
                if (!vis.contains(e.getKey())) {
                    g[e.getKey()].ud(c.d + e.getValue());
                    pq.remove(g[e.getKey()]);
                    pq.add(g[e.getKey()]);
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            System.out.println((g[i].d == Integer.MAX_VALUE) ? -1 : g[i].d);
        }
    }

    static class Vertex implements Comparable<Vertex> {
        int num, d = Integer.MAX_VALUE;
        HashMap<Integer, Integer> edges = new HashMap<>();

        public Vertex(int num) {
            this.num = num;
        }

        public HashMap<Integer, Integer> getEdges() {
            return edges;
        }
        
        public void ue(int v, int w) {
            if (edges.containsKey(v)) {
                edges.put(v, Integer.min(edges.get(v), w));
            } else {
                edges.put(v, w);
            }
        }
        
        public void ud(int d) {
            this.d = Integer.min(this.d, d);
        }


        @Override
        public int compareTo(Vertex o) {
            return this.d - o.d;
        }
    }
}