//
//  main.cpp
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/12.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#include "Graph.h"
#include "Algo.h"

int main(int argc, const char* argv[])
{
    //Algo::discrete();
    //Algo::randomGraph();
    std::ifstream in("data_new.txt");
    std::ofstream out(argv[2]);
    out << std::fixed << std::setprecision(3);
    
    int n, m;
    in >> n >> m;
    Graph* graph = new Graph(n, m * 2);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        double z;
        in >> x >> y >> z;
        graph->addEdge(x, y, z);
        graph->addEdge(y, x, z);
    }
    
    if (strcmp(argv[1], "MST") == 0)
    {
        if (strcmp(argv[3], "Prim") == 0)
        {
            EdgeList* edges = graph->prim();
            edges->print(out);
        }
        else if (strcmp(argv[3], "Kruskal") == 0)
        {
            EdgeList* edges = graph->kruskal();
            edges->print(out);
        }
    }
    return 0;
}
