#ifndef GRAPH_CPP
#define GRAPH_CPP
#include "Graph.h"
#include <map>
#include <set>
#include <iostream>
#include <queue>


using namespace std;
template<class T>
Graph<T>::Graph()
{

}

//check if there is an edge
template<class T>
bool Graph<T>::hasEdge(T v, T w) const
{
    if (adjMap.find(v) == adjMap.end())
    {
        return false;
    }
    if (adjMap.at(v).find(w) == adjMap.at(v).end())
    {
        return false;
    }
    else
    {
        return true;
    }

}

template<class T>
void Graph<T>::addEdge(T v,T w) //add edges to graph
{

    adjMap[v].insert(w);
    adjMap[w].insert(v);
}

//bfs search algorithm
template<class T>
int Graph<T>::BFS(T s, T t, map<T, int>& distance,  map<T, T>& go_through) const
{
    for (auto i = adjMap.begin(); i != adjMap.end(); i++)
    {
        distance[i->first] = NOPATH;
    }
    queue<T> find;
    find.push(s);
    distance[s] = 0;
    go_through[s] = s;
    T current = s;
   
    while(!find.empty() && current != t)
        {
            current = find.front();
            find.pop();
            for (auto i = adjMap.at(current).begin(); i != adjMap.at(current).end(); i++)
            {
                auto w = (*i);
                if (distance[w] == NOPATH)
                {
                    distance[w] = distance[current] + 1;
                    go_through[w] = current;
                    find.push(w);
                }
            }
        }
    return distance[t];
}
#endif
