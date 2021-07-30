import java.io.*;
import java.util.*;

public class Hitchhiking {

    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static char readChar() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
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

    static int N;

    public static void main(String[] args) throws IOException {
        N = nextInt();
        final int M = nextInt();
        City[] map = new City[N + 1];
        for (int i = 1; i <= N; i++) {
            map[i] = new City(i);
        }
        for (int m = 0; m < M; m++) {
            int a = nextInt(), b = nextInt(), c = nextInt();
            Road road = new Road(Integer.min(a, b), Integer.max(a, b), c);
            map[a].addRoad(road);
            map[b].addRoad(road);
        }
        PriorityQueue<City> pq = new PriorityQueue<>();
        map[1].updateDist(0, 0);
        pq.add(map[1]);
        while (!pq.isEmpty()) {
            City cur = pq.remove();
            if (cur.n == N) {
                System.out.println(cur.dc + " " + cur.d);
                return;
            }
            cur.vis = true;
            while (!cur.getAdj().isEmpty()) {
                Road route = cur.getAdj().remove();
                if (!map[route.getOther(cur.n)].vis) {
                    map[route.getOther(cur.n)].updateDist(cur.d + 1, cur.dc + route.d);
                    pq.add(map[route.getOther(cur.n)]);
                }
            }
        }
        System.out.println(-1);
    }

    static class Road implements Comparable<Road> {
        private int a, b, d;

        public Road(int a, int b, int d) {
            this.a = a;
            this.b = b;
            this.d = d;
        }

        public int getOther(int v) {
            if (v == this.a) return b;
            return this.a;
        }

        @Override
        public int compareTo(Road o) {
            return this.d - o.d;
        }
    }

    static class City implements Comparable<City> {
        private int n, d = Integer.MAX_VALUE, dc = Integer.MAX_VALUE;
        private PriorityQueue<Road> adj;
        private boolean vis = false;

        public City(int n) {
            this.n = n;
            adj = new PriorityQueue<>();
        }
        
        private void updateDist(int di, int dc) {
            if (this.dc >= dc) {
                if (this.dc > dc) {
                    this.d = di;
                } else {
                    this.d = Integer.min(this.d, di);
                }
                this.dc = dc;
            }
        }

        public PriorityQueue<Road> getAdj() {
            return adj;
        }

        private void addRoad(Road r) {
            this.adj.add(r);
        }

        @Override
        public int compareTo(City o) {
            if (this.dc == o.dc) return this.d - o.d;
            return this.dc - o.dc;
        }
    }
}