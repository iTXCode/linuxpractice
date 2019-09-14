#include<iostream>

enum Color{
  Red,
  Black
};

template <class K,class V>
struct RBTreeNode{
  std::pair<K,V> _kv;
  Color _color=Red;

  RBTreeNode<K,V>*  _pLeft=nullptr;
  RBTreeNode<K,V>* _pRight=nullptr;
  RBTreeNode<K,V>* _pParent=nullptr;
};

template <class K,class V>

class RBTree{
public:
  typedef RBTreeNode<K,V> Node;
  typedef Node* pNode;
  RBTree()
  :_header(new Node)
  {
    _header->_pLeft=_header;
    _header->_pRight=_header;
  }
  bool Insert(const std::pair<K,V>& kv){
    //二叉树搜索树的插入
    if(_header->_pParent==nullptr){
      //空树，插入根节点,颜色为黑
      pNode root=new Node;
      root->_kv=kv;
      root->_color=Black;
      _header->_pParent=root;
      root->_pParent=_header;
      _header->_pLeft=root;
      _header->_pRight=root;
      return true;
    }

    //遍历该树,找出一个叶子节点
    pNode cur=_header->_pParent;
    pNode parent=nullptr;
    while(cur){
      if(cur->_kv.first>kv.first){
        parent=cur;
        cur->cur->_pLeft;
      }else if(cur->_kv.first<kv.first){
        parent=cur;
        cur=cur->_pRight;
      }else{
        return false;
      }
    } //end of while 
    cur =new Node;
    cur->_kv=kv;
    if(parent->_kv.first>cur->_kv.first){
      parent->_pLeft=cur;
    }else {
      parent->_pRight=cur;
    }
    cur->_pParent=parent;
    //调整，变色
    pNode root=_header->_pParent;
    while(cur!=_header->_pParent&&cur->_pParent->_color==Red){
      //插入节点不是根并且父亲节点为红色,新插入的节点默认为红色(两个红节点连接到了一起)
      
     
      pNode parent =cur->_pParent;
      pNode gParent=parent->_pParent;
      if(gParent->_pLeft==parent){
         pNode uncle=gParent->_pRight;
         
         if(uncle&&uncle->_color==Red){
         //叔叔存在且为红,只需要修改颜色就行
         //将其父亲和叔叔节点的 颜色变成黑色
         //祖父颜色变成红的,让cur变成祖父
           parent->_color=uncle->_color=Black;
           gParent->_color=Red;
           cur=gParent;
         }else{
           //叔叔存在且为黑或者不存在
           //1.叔叔不存在的情况需要旋转
           //将祖父节点放在父亲节点的右边
           //将父情节点的右边放在祖父节点的左边
           //将祖父节点变红,将父亲节点变黑
           //以祖父为轴进行右旋
           

           //2.叔叔存在，还是以祖父为轴进行右旋
           //将祖父节点拿下来,将父亲节点的右
           //子树接到父亲节点的左边将祖父节点
           //接到父亲节点的右边
           //父亲节点变黑,祖父节点变红
           

           //开始写代码
           //首先检查是否有双旋的场景:左右双旋
           //首先左单旋，swap ,-->右单旋
           if(parent->_pRight==cur){
              Rotatel(parent);
              swap(parent,cur);
           }

           RotateR(gParent);
           parent->_color=Black;
           gParent->_clocr=Red;
           break;
         }
      }else{
        pNode uncle=gParent->_pLeft; 
        if (uncle && uncle->_color == Red)
        {
          parent->_color = uncle->_color = Black;
          gParent->_color = Red;
          cur = gParent;

        }
        else
        {
          //u存在且为黑 / u不存在
            if (parent->_pLeft == cur)
            {
              RotateR(parent);
              swap(cur, parent);
            }

          RotateL(gParent);
          gParent->_color = Red;
          parent->_color = Black;
          break;
        }
      }
    }
 //红黑树根始终是黑色的
    _header->_pParent->_color = Black;
    _header->_pParent->_pParent = _header;
    //为了实现后续的迭代器
    _header->_pLeft = leftMost();
    _header->_pRight = rightMost();
    return true;
}

pNode leftMost()
{
  pNode cur = _header->_pParent;
  while (cur && cur->_pLeft)
  {
    cur = cur->_pLeft;

  }
  return cur;

}

pNode rightMost()
{
  pNode cur = _header->_pParent;
  while (cur && cur->_pRight)
  {
    cur = cur->_pRight;

  }
  return cur;

}

void RotateL(pNode parent)
{
  pNode subR = parent->_pRight;
  pNode subRL = subR->_pLeft;
  //旋转
  subR->_pLeft = parent;
  parent->_pRight = subRL;

  //更新三叉链
  //链接subRL 和parent
  if (subRL)
    subRL->_pParent = parent;

  //链接subR 和 parent->_pParent
  if (parent != _header->_pParent)
  {
    pNode gParent = parent->_pParent;
    //判断parent之前是parent->_pParent的那一边的节点
    //把subR链接到对应的边

    if (gParent->_pLeft == parent)
      gParent->_pLeft = subR;
    else
      gParent->_pRight = subR;
    //更新subR的pParent
    subR->_pParent = gParent;
  }
  else
  {
    //如果parent是根，subR变成新的根
    subR->_pParent = nullptr;
    _header->_pParent = subR;
  }

  //链接subR 和 parent
  parent->_pParent = subR;

}


void RotateR(pNode parent)
{
  pNode subL = parent->_pLeft;
  pNode subLR = subL->_pRight;
  // 1. 单向链接subL, subLR, parent
  subL->_pRight = parent;
  parent->_pLeft = subLR;
  //2 向上链接subLR, parent
  if (subLR)
    subLR->_pParent = parent;
  //3. 双向链接subL与pParent->_pParent
  if (parent != _header->_pParent)
  {
    pNode gParent = parent->_pParent;
    if (gParent->_pLeft == parent)
      gParent->_pLeft = subL;
    else
      gParent->_pRight = subL;
    subL->_pParent = gParent;
  }
  else
  {
    subL->_pParent = nullptr;
    _header->_pParent = subL;
  }
  //4. 向上链接parent, subL
  parent->_pParent = subL;

}

void Inorder()
{
  _Inorder(_header->_pParent);
  std::cout << std::endl;
}

void _Inorder(pNode root)
{
  if (root)
  {
    _Inorder(root->_pLeft);
    std::cout << root->_kv.first << " ";
    _Inorder(root->_pRight);
  }
}

bool IsValidRBTree()
{
  pNode pRoot = _header->_pParent;
  // 空树也是红黑树
  if (nullptr == pRoot)
    return true;
  // 检测根节点是否满足情况
  if (Black != pRoot->_color)
  {
    std::cout << "违反红黑树性质二：根节点必须为黑色" << std::endl;
    return false;
  }
  // 获取任意一条路径中黑色节点的个数
  size_t blackCount = 0;
  pNode pCur = pRoot;
  while (pCur)
  {
    if (Black == pCur->_color)
      blackCount++;
    pCur = pCur->_pLeft;
  }
  // 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
  size_t k = 0;
  return _IsValidRBTree(pRoot, k, blackCount);
}
bool _IsValidRBTree(pNode pRoot, size_t k, const size_t blackCount)
{
  //走到null之后，判断k和black是否相等
  if (nullptr == pRoot)
  {
    if (k != blackCount)
    {
      std:: cout << "违反性质四：每条路径中黑色节点的个数必须相同" <<std:: endl;
      return false;
    }
    return true;
  }
  // 统计黑色节点的个数
  if (Black == pRoot->_color)
    k++;
  // 检测当前节点与其双亲是否都为红色
  pNode pParent = pRoot->_pParent;
  if (pParent && Red == pParent->_color && Red == pRoot->_color)
  {
    std::cout << "违反性质三：没有连在一起的红色节点" <<std::endl;
    return false;
  }
  return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
    _IsValidRBTree(pRoot->_pRight, k, blackCount);
}

private:
pNode _header;
};

int main()

{
  RBTree<int, int> rbt;
  srand(time(nullptr));
  /*int arr[] = { 5, 7, 9, 1, 3, 4, 10, 6, 8  };
  for (const auto& e : arr)
  {
  rbt.Insert(make_pair(e, e));
  }*/

  int n;
  std:: cin >> n;
  while (n--)
  {
    int num = rand();
    std::cout << num << " ";
    rbt.Insert(std::make_pair(num,n));
    /*if (!rbt.IsValidRBTree())
    {
      cout << "插入节点异常：" << num << endl;
    }*/
  }
  std::cout << std::endl;
  /*rbt.Inorder();*/
  std::cout <<"IsValidRBTree: "<< rbt.IsValidRBTree() << std::endl;
  return 0;
}







