import java.io.*;
import java.util.*;

public class TruckingTroubles {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        }
        return st.nextToken();
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readChar() throws IOException {
        return next().charAt(0);
    }

    static class City implements Comparable<City> {
        private int n, mw = 0;
        private PriorityQueue<Road> r = new PriorityQueue<>();
        private boolean v = false;

        public City(int n) {
            this.n = n;
        }
        
        @Override
        public int compareTo(City o) {
            return o.mw - this.mw;
        }
        
        public void ar(Road r) {
            this.r.add(r);
        }

        public void sw(int w) {
            this.mw = Integer.max(this.mw, w);
        }
    }

    static class Road implements Comparable<Road> {
        private int f, s, w;

        public Road(int x, int y, int w) {
            f = x;
            s = y;
            this.w = w;
        }

        public int o(int x) {
            if (x == f) return s;
            return f;
        }

        public int compareTo(Road o) {
            return o.w - this.w;
        }
    }

    public static void main(String[] args) throws IOException {
        int c = nextInt(), r = nextInt(), d = nextInt(), w = 100000;
        City[] cities = new City[c + 1];
        HashSet<Integer> sites = new HashSet<>();
        for (int i = 1; i <= c; i++) {
            cities[i] = new City(i);
        }
        for (int i = 0; i < r; i++) {
            int x = nextInt(), y = nextInt(), z = nextInt();
            Road road = new Road(x, y, z);
            cities[x].ar(road);
            cities[y].ar(road);
        }
        for (int i = 0; i < d; i++) {
            sites.add(nextInt());
        }
        PriorityQueue<City> pq = new PriorityQueue<>();
        pq.add(cities[1]);
        while (!pq.isEmpty()) {
            City cur = pq.remove();
            cur.v = true;
            if (sites.contains(cur.n)) {
                w = Integer.min(w, cur.mw);
                sites.remove(cur.n);
                if (sites.isEmpty()) {
                    break;
                }
            }
            PriorityQueue<Road> net = cur.r;
            while (!net.isEmpty()) {
                Road route = net.remove();
                if (!cities[route.o(cur.n)].v) {
                    cities[route.o(cur.n)].sw(route.w);
                    pq.add(cities[route.o(cur.n)]);
                }
            }
        }
        System.out.println(w);
    }
}