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
* 联通分量（联通支）
* k短路

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
正在看算法。

#### 紧密中心度：
<pre>
./graph CENTER center_close.txt Close
</pre>
输出的第一行为节点数。

输出的后面以实数的形式给出了每个点的紧密中心度。

### 联通分量
还没写
### k短路
还没写

