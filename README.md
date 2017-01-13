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
### 中心度
还没写
### 联通分量
还没写
### k短路
还没写
