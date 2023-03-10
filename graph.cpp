#include "graph.h"
#include <string>
//using std namespace;
#include <iostream>
Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}
// добавление вершины
void Graph::addVertex(int vnumber, const char* name)
{
    vertexes[vertexCount] = vnumber;
    //list vertexname[vertexCount] = name;
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}
// проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
// проверка существования вершины
bool Graph::vertexExists(int v)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == v)
            return true;
    return false;
}
void Graph::delVertex(int vnumber) // удаление вершины
{
    // обнуляем столбец и строку матрицы
    for (int i = 0; i < SIZE; i++)
    {
        matrix[i][vnumber] = 0;
        matrix[vnumber][i] = 0;
    }
    // удаляем вершину из списка вершин
    int foundIndex = 1;
    for (int i = 0; i < vertexCount; i++)
    {
        if (vertexes[i] == vnumber)
            foundIndex = i;
    }
    vertexCount--;
    for (int i = foundIndex; i < vertexCount; i++)
    {
        vertexes[i] = vertexes[i + 1];
    }
}

void Graph::delEdge(int v1, int v2) // удаление ребра
{
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}

// поиск количества путей

int Graph::pathCount(int from, int to)
{
    bool visited[SIZE]; // массив пройденных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
    int count = 0; // результат
    pathCountInner(from, to, visited, count);
    return count;
}

void Graph::pathCountInner(int current, int to, bool visited[], int& count)
{
    if (current == to)
    {
        // если дошли до второй вершины, увеличиваем счётчик путей
        // и выходим
        count++;
        return;
    }
    visited[current] = true; // отмечаем как посещенную
    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(current, i) && !visited[i])
        {
            pathCountInner(i, to, visited, count);
        }
    }
    // отмечаем, что путь уже не содержит эту вершину
    visited[current] = false;
}

bool Graph::find3hands(int from, int to, int count)
{
    bool visited[SIZE]; // массив пройденных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
    int current;
    int toto;
    int tcount=0;
    //while (tcount == 0)
    
        //if (current == to)
    //{
        // если дошли до второй вершины, увеличиваем счётчик путей
        // и выходим
        //tcount--;
       // return;
    //}
    if (to > from) {
        current = from;
        toto = to;
    }
    else {
        toto = from;
        current = to;
        
    }

        int tcurrent = current + 1;
        
        for (int i=tcurrent; i<= toto; i++)
        {
            if (edgeExists(current, i) && !visited[current])
            {
               
                visited[current] = true; // отмечаем как посещенную
                current++;
                tcurrent++;
                tcount++; //счет рукопожатий
            }
            if (tcount>3)
            {
                std::cout << "count =  "<< tcount << std::endl;
                return false ;
            }
        }
       if (tcount >count)
           return false;

       
        
 }
    
   