//
//  main.cpp
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/12.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#include "Graph.h"
#include "Algo.h"

int main(int argc, const char * argv[])
{
    Algo::discrete();
    /*std::ifstream in("data.txt");
    std::ofstream out("output.txt");
    
    int n, m;
    in >> n >> m;
    std::cerr << "n, m = " << n << " " << m << std::endl;
    Graph* graph = new Graph(n, m * 2);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        double z;
        in >> x >> y >> z;
        graph->addEdge(x, y, z);
        graph->addEdge(y, x, z);
    }
    
    graph->check(out);
    //EdgeList* edges = graph->kruskal();
    //edges->print(out);*/
    
    return 0;
}
