二叉堆(又叫堆) 本身逻辑上是一颗完全二叉树
物理上是一个数组
作用:找数据中的最值
二叉堆中任意节点的值大于(小于)左右孩子结点的值
大堆和小堆
 



已知[parent]
[left]=2*[parent]+1;
[right]=2*[parent]+2;

已知[child](无论左右)
[parent]=([child-1])/2

堆的向下调整过程
要调整的结点下标是[root]
[root] 左右子树已经满足堆的性质
【假如是小堆】
1.要调整[root] 所在的结点
  前提：[root] 的左右子树已经满足堆的性质
  如果root所在的结点已经是叶子结点，调整结束
2.找到左右孩子中最小的一个结点[min]

3.if(array[min] > array[root])
  不需要继续调整,调整结束
  else 
    Swap(&array[root].&array[min])
    [min]=[root];




