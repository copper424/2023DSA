#include <stdio.h>
#include <string.h>

const int graph_size = 1000;
const int infinity = 0x3fffffff;

bool component[graph_size]; // Vertices in set X
int distance[graph_size]; // Distances of vertices adjacent to X
int neighbor[graph_size]; // Nearest neighbor in set X
int cs, n, m;
int a[graph_size][graph_size];

int MSF(int source)
{
	int ret = 0;
	int w;
	for (w = 0; w < n; w++) {
		distance[w] = a[source][w];
		neighbor[w] = source;
	}
	component[source] = true; // source alone is in the set X.
	while (true) {
		int v; // Add one vertex v to X on each pass.
		int mx = -infinity;
		for (w = 0; w < n; w++)
		if (!component[w])
		if (distance[w] > mx) {
			v = w;
			mx = distance[w];
		}
		if (mx > -infinity) {
			ret += mx;
			component[v] = true;
			for (w = 0; w < n; w++)
			if (!component[w])
			if (a[v][w] > distance[w]) {
				distance[w] = a[v][w];
				neighbor[w] = v;
			}
		}
		else break; // finished a component in disconnected graph
	}
	return ret;
}

int main()
{
	int x, y, i;
	scanf("%d", &cs);
	while (cs--) {
		scanf("%d%d", &n, &m);
		for (x = 0; x < n; x++) {
			a[x][x] = 0;
			for (y = x + 1; y < n; y++)
				a[x][y] = a[y][x] = -infinity;
		}

		while (m--) {
			scanf("%d%d%d", &x, &y, &i);
			a[x][y] = a[y][x] = i;
		}

		for (i = 0; i < n; i++)
			component[i] = false;

		int ans = 0;
		for (i = 0; i < n; i++)
			if (!component[i]) ans += MSF(i);
		printf("%d\n", ans);
	}
	return 0;
}
