//Link State Routing(LSR).
#include <iostream> 
using namespace std;
int main() 
{
	int count, src_router, i, j, k, w, v, min;
	int cost_matrix[100][100], dist[100], last[100]; 
	int flag[100];
	char user_input;
	do 
	{
		cout << "\nEnter the number of routers: "; 
		cin >> count;
		cout << "\nEnter the cost matrix values:\n"; 
		for (i = 0; i < count; i++) 
		{
			for (j = 0; j < count; j++) 
			{
				cout << i << "->" << j << ": ";
				cin >> cost_matrix[i][j];
				if (cost_matrix[i][j] < 0) cost_matrix[i][j] = 1000;
			}
		}
		cout << "\nEnter the source router: "; 
		cin >> src_router;
		for (v = 0; v < count; v++) 
		{ 
			flag[v] = 0;
			last[v] = src_router;
			dist[v] = cost_matrix[src_router][v];
		}
		flag[src_router] = 1;
		for (i = 0; i < count; i++) 
		{ 
			min = 1000;
			for (w = 0; w < count; w++) 
			{
				if (!flag[w] && dist[w] < min) 
				{ 
					v = w;
					min = dist[w];
				}
			}
			flag[v] = 1;
			for (w = 0; w < count; w++) 
			{
				if (!flag[w] && (min + cost_matrix[v][w] < dist[w])) 
				{ 
					dist[w] = min + cost_matrix[v][w];
					last[w] = v;
				}
			}
		}
		for (i = 0; i < count; i++) 
		{
			cout << "\n" << src_router << "=>" << i << ": Path taken: " << i; 
			w = i;
			while (w != src_router) 
			{ 
				cout << "<--" << last[w]; 
				w = last[w];
			}
			cout << "\nShortest path cost: " << dist[i];
		}
		cout << "\nEnter 'q' to quit or any other character to continue: "; 
		cin >> user_input;
	}while (user_input != 'q');
	return 0;
}
