#include <iostream>
#include <vector>
#define inf 100000
using namespace std;

struct STRUCTURKA {
	int u, v, w;
};

const int maximV = 1000;
const int maximE = maximV * (maximV - 1) / 2;
int i, j, n, e, e2, nachalo, e_new = 0;
STRUCTURKA edge[maximE];
STRUCTURKA edge2[maximE];
STRUCTURKA edge3[maximE];
STRUCTURKA edge4[maximE];
STRUCTURKA edge5[maximE];
int h[maximV];
int d[maximV];
int d1[maximV];


void bellman_ford(int n, int s)
{
	int i, j;

	for (i = 0; i < n; i++) d[i] = inf;
	d[s] = 0;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < e; j++)
			if (d[edge[j].v] + edge[j].w < d[edge[j].u])
				d[edge[j].u] = d[edge[j].v] + edge[j].w;

	for (i = 0; i < n + 1; i++) d1[i] = inf;
	d1[n] = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < e + n; j++)
			if (d1[edge4[j].v] + edge4[j].w < d1[edge4[j].u])
				d1[edge4[j].u] = d1[edge4[j].v] + edge4[j].w;

	cout << endl;
	cout << "Bellman - Ford algorithm : ";

	for (i = 0; i < n; i++) if (d[i] == inf)
		cout << endl << nachalo << "->" << i + 1 << "=" << "Not";
	else cout << endl << nachalo << "->" << i + 1 << "=" << d[i];

	for (i = 0; i < n + 1; i++)
		if (d1[i] == inf)
		{
			h[i] = 0;
		}
		else h[i] = d1[i];
}


void Dijkstra(int st, int V)
{
	int** TY = new int* [V];
	for (i = 0; i < V; i++)
	{
		TY[i] = new int[V];
	};

	int s = 0;

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			TY[i][j] = edge2[s].w;
			s++;
		};
	};

	int count, index, p, r, m = st + 1;
	int* distance = new int[V];
	bool* visited = new bool[V];

	for (i = 0; i < V; i++)
	{
		distance[i] = INT_MAX;
		visited[i] = false;
	};

	distance[st] = 0;

	for (count = 0; count < V - 1; count++)
	{
		int min = INT_MAX;

		for (i = 0; i < V; i++)
			if (!visited[i] && (distance[i] <= min))
			{
				min = distance[i];
				index = i;
			};

		r = index;
		visited[r] = true;

		for (i = 0; i < V; i++)
			if (!visited[i] && (TY[r][i] != 0) && (distance[r] != INT_MAX) &&
				(distance[r] + TY[r][i] < distance[i]))
				distance[i] = distance[r] + TY[r][i];
	}
	cout << endl;
	cout << "Dijkstra's algorithm:\t\n";
	cout << "The cost of the path from the initial vertex to the rest:\t\n";
	for (p = 0; p < V; p++) if (distance[p] != INT_MAX)
		cout << m << " > " << p + 1 << " = " << distance[p] << endl;
	else cout << m << " > " << p + 1 << " = " << "route unavailable" << endl;


	for (i = 0; i < V; i++)
	{

		delete[] TY[i];

	};

	delete[] distance;
	delete[] visited;
};


void Flo(int V)
{
	int k;

	int** D = new int* [V];
	for (i = 0; i < V; i++)
	{
		D[i] = new int[V];
	};

	int s = 0;

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			D[i][j] = edge3[s].w;
			s++;
		};
	};

	for (i = 0; i < V; i++) D[i][i] = 0;

	for (k = 0; k < V; k++)
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
				if (D[i][k] && D[k][j] && i != j)
					if (D[i][k] + D[k][j] < D[i][j] || D[i][j] == 0)
						D[i][j] = D[i][k] + D[k][j];

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++) cout << D[i][j] << "\t";
		cout << endl;
	};

	for (i = 0; i < V; i++)
	{

		delete[] D[i];

	};
};


void Dijkstra_for_dj(int st, int V)
{
	int** G = new int* [V];
	for (i = 0; i < V; i++)
	{
		G[i] = new int[V];
	};

	int s = 0;

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			G[i][j] = edge5[s].w;
			s++;
		};
	};

	int count, index, p, r, m = st + 1;
	int* distance = new int[V];
	bool* visited = new bool[V];

	for (i = 0; i < V; i++)
	{
		distance[i] = INT_MAX;
		visited[i] = false;
	};

	distance[st] = 0;

	for (count = 0; count < V - 1; count++)
	{
		int min = INT_MAX;

		for (i = 0; i < V; i++)
			if (!visited[i] && (distance[i] <= min))
			{
				min = distance[i];
				index = i;
			};

		r = index;
		visited[r] = true;

		for (i = 0; i < V; i++)
			if (!visited[i] && (G[r][i] != 0) && (distance[r] != INT_MAX) &&
				(distance[r] + G[r][i] < distance[i]))
				distance[i] = distance[r] + G[r][i];


	}
	cout << endl;
	cout << "Johnson algorithm:\t\n";
	cout << "The cost of the path from the initial vertex to the rest :\t\n";
	for (p = 0; p < V; p++) if (distance[p] != INT_MAX)
		cout << m << " > " << p + 1 << " = " << distance[p] << endl;
	else cout << m << " > " << p + 1 << " = " << "route unavailable" << endl;


	for (i = 0; i < V; i++)
	{

		delete[] G[i];

	};

	delete[] distance;
	delete[] visited;
};


int main()
{
	setlocale(LC_ALL, "Rus");
	int w;

	cout << "number of vertices > "; cin >> n;
	e = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "weight " << i + 1 << "->" << j + 1 << " > "; cin >> w;
			if (w != 0)
			{
				edge[e].v = i;
				edge[e].u = j;
				edge[e].w = w;

				edge4[e].v = i;
				edge4[e].u = j;
				edge4[e].w = w;

				e++;
			};

			edge2[e_new].v = i;
			edge2[e_new].u = j;
			edge2[e_new].w = w;

			edge3[e_new].v = i;
			edge3[e_new].u = j;
			edge3[e_new].w = w;

			edge5[e_new].v = i;
			edge5[e_new].u = j;
			edge5[e_new].w = w;

			e_new++;
		};

	int pp = 0;
	e2 = e;
	int y = e;
	for (j = e; j < (e + n); j++)
	{

		edge4[j].v = n;
		edge4[j].u = pp;
		edge4[j].w = 0;

		pp++;
	};

	cout << "starting peak > ";
	cin >> nachalo;

	cout << "list of shortest paths:";
	bellman_ford(n, nachalo - 1);
	Dijkstra(nachalo - 1, n);

	cout << endl;
	cout << "Floyd-Warshall algorithm" << endl;
	cout << "shortest path matrix:" << endl;
	Flo(n);

	for (i = 0; i < n * n; i++)
	{
		if (edge5[i].w != 0)
		{
			edge5[i].w = edge5[i].w + h[edge5[i].v] - h[edge5[i].u];

		};
	};

	Dijkstra_for_dj(nachalo - 1, n);

	system("pause>>void");
};
