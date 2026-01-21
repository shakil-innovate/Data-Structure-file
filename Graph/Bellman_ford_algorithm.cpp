//problem:4.4 Bellman Ford Algorithm - Single Source Shortest Path - Dynamic Programming
//vedio link:https://www.youtube.com/watch?v=FtN3BYH2Zes
//problem link: https://bit.ly/3K7emug

struct Edge {
    int u, v, w;
};

class BellmanFord {
public:
    int V;
    vector<Edge> edges;
    BellmanFord(int vertices, const vector<Edge>& edgeList) {
        V = vertices;
        edges = edgeList;
    }

    vector<int> run(int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (auto &e : edges) {
                if (dist[e.u] != 1e8 && dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        for (auto &e : edges) {
            if (dist[e.u] != 1e8 && dist[e.u] + e.w < dist[e.v]) {
                return {-1};
            }
        }
        return dist;
    }
};
