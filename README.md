# DSA图论大作业
## 写在最前
原数据里面有81个孤立节点，我把它们都删掉了，然后对节点重新编号，最终的数据放在(`data_new.txt`)里面了，原数据在(`data.txt`)里面。
## 用法
使用命令行参数运行，一般的形式是：
<pre>
./graph &lt;algorithm_type&gt; &lt;output_file_name&gt; &lt;algorithm_name&gt; &lt;parameter1&gt; &lt;parameter2&gt; …
</pre>

(`alorithm_type`)表示算法类型。

(`output_file_name`)表示输出文件名。

(`algorithm_name`)表示算法名称，一种算法类型可能会有多种算法实现，比如最小生成树可以用Prim或者Kruskal。

(`parameter`)表示参数，比如最短路的节点之类，也可能没有参数。

准备写的算法有

* 最小生成树
* 最短路
* 中心度
* 连通分量（联通支）
* K-短路

### 最小生成树
(`algorithm_type`)为(`MST`)。

(`algorithm_name`)可选(`Prim`)或者(`Kruskal`)。

(`parameter`)为空。

<pre>
./graph MST mst_prim.txt Prim
</pre>
或者
<pre>
./graph MST mst_kruskal.txt Kruskal
</pre>

输出的第一行为边数，它一定为n-1。

输出的后面若干行表述了这n-1条边，和输入的描述方式完全相同。

输出的最后一行为边权之和（最小生成树的大小）。

### 最短路
(`algorithm_type`)为(`PATH`)。

(`algorithm_name`)可选(`Dijkstra`)或者(`Spfa`)。

(`parameter`)有两项，表示起点和终点。
<pre>
./graph PATH path_dijkstra.txt Dijkstra 310 479
</pre>
或者
<pre>
./graph PATH path_spfa.txt Spfa 310 479
</pre>

原图非常密集，直径为6.700，就是310和479为两个端点。

输出的第一行为边数。

输出的后面若干行描述了若干条边，按照路径的顺序。

输出的最后一行为边权之和（最短路的长度）。

### 中心度
(`algorithm_type`)为(`CENTER`)。

(`algorithm_name`)可选(`Between`)或者(`Close`)，分别表示介数中心度和紧密中心度。

(`parameter`)为空。

#### 介数中心度：
<pre>
./graph CENTER center_between.txt Between
</pre>

算法时间复杂度较高（总时间大约3s）。

输出的第一行为节点数。

输出的后面以实数的形式给出了每个点的介数中心度。

#### 紧密中心度：
<pre>
./graph CENTER center_close.txt Close
</pre>

输出的第一行为节点数。

输出的后面以实数的形式给出了每个点的紧密中心度。

### 连通分量
(`algorithm_type`)为(`CONNECT`)。

(`algorithm_name`)为(`Default`)。

(`parameter`)有两项，第一项表示共同看过电影数目的最小值，第二项表示评分相似度的最小值。由于评分相似度是一个在0.1~0.9之间的<b>三位小数</b>，因此第二项参数为一个100~900之间的<b>整数</b>，程序会将其除以1000之后再搜索。

<pre>
./graph CONNECT connection.txt Default 10 500
</pre>

输出的第一行表示连通支的个数connCount。

输出的第二行表示节点数n，随后的n行每行有一个在[1, connCount]范围的整数，表示该节点属于的连通支。

在这之后有一个整数m表示边数，随后的m行每行表述了一条边，表示连通支的边的情况。每个连通支为一棵树。

注意到一定有 n = connCount + m。

### K-短路
(`algorithm_type`)为(`KPATH`)。

(`algorithm_name`)为(`Default`)。

(`parameter`)有三项，前两项表示起点和终点，最后一项表示K。K&leq;10000时需要的时间少于3秒。

<pre>
./graph KPATH kpath.txt Default 310 479 10001
</pre>

输出和最短路的形式相同。

