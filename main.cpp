#include "graph.h"
#include <iostream>
int main()
{
	Graph g;
	g.addVertex(0);
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(5);
	g.addVertex(6);
	g.addVertex(7);
	g.addVertex(8);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 1);
	g.addEdge(4, 5, 1);
	g.addEdge(5, 6, 1);
	g.addEdge(6, 7, 1);
	g.addEdge(7, 8, 1);
	
	
		
	if (g.find3hands(0, 4, 3)) std::cout << "Дружба подтверждена" << std::endl;
	else std::cout << "Дружба не подтверждена" << std::endl;
	//	g.depth(0);
	return 0;
}
