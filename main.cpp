#include "graph.h"
#include <iostream>

int main()
{
	Graph g;
	g.addVertex(0, "Lena");
	g.addVertex(1, "Misha");
	g.addVertex(2, "Saha");
	g.addVertex(3, "Kostya");
	g.addVertex(4, "Olya");
	g.addVertex(5, "Vera");
	g.addVertex(6, "Ilya");
	g.addVertex(7,"Foma");
	g.addVertex(8,"Alexander");
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 1);
	g.addEdge(4, 5, 1);
	g.addEdge(5, 6, 1);
	g.addEdge(6, 7, 1);
	g.addEdge(7, 8, 1);
	
	
		
	if (g.find3hands(0, 3, 3)) std::cout << "Дружба подтверждена" << std::endl;
	else std::cout << "Дружба не подтверждена" << std::endl;
	
	return 0;
}
