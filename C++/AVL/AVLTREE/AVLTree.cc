#include <iostream>

using namespace std;

template<class T>
struct AVLNode
{
  AVLNode(const T& val = T())
    :_data(val)
     , _pLeft(nullptr)
     , _pRight(nullptr)
     , _pParent(nullptr)
     , _bf(0)
  {}
  T _data;
  AVLNode<T>* _pLeft;
  AVLNode<T>* _pRight;
  AVLNode<T>* _pParent;
  //平衡因子
  int _bf;

};

template <class T>
class AVLTree
{
  public:
    typedef AVLNode<T> Node;
    typedef Node* pNode;

    bool insert(const T& val)
    {
      if (_root == nullptr)
      {
        _root = new Node(val);
        return true;

      }

      pNode cur = _root;
      pNode parent = nullptr;
      while (cur)
      {
        parent = cur;
        if (cur->_data > val)
        {
          cur = cur->_pLeft;

        }
        else if (cur->_data < val)
        {
          cur = cur->_pRight;

        }
        else
          return false;
      }

      pNode newNode = new Node(val);
      if (parent->_data > val)
        parent->_pLeft = newNode;
      else
        parent->_pRight = newNode;
      newNode->_pParent = parent;
      cur = newNode;
      //调整，保证平衡
      while (parent)
      {
        //更新当前节点的平衡因子
        if (parent->_pLeft == cur)
          --parent->_bf;
        else
          ++parent->_bf;
        //检查平衡因子，_bf ==0, 高度没有发生变化，停止更新
        if (parent->_bf == 0)
          break;
        //高度加1，更新此路径上的祖先节点的平衡因子
        if (parent->_bf == 1 || parent->_bf == -1)
        {
          cur = parent;
          parent = parent->_pParent;
        }

        else if (parent->_bf == 2 || parent->_bf == -2)
        {
          //不平衡，需要调整
          //左旋
          if (parent->_bf == 2 && cur->_bf == 1)
          {
            RotateL(parent);
          }
          else if (parent->_bf == -2 && cur->_bf == -1)
          {
            //右旋
            RotateR(parent);
          }
          else if (parent->_bf == -2 && cur->_bf == 1)
          {
            //左右双旋

            RotateL(cur);
            RotateR(parent);

          }
          else if (parent->_bf == 2 && cur->_bf == -1)
          {
            pNode subR = parent->_pRight;
            pNode subRL = subR->_pLeft;
            int bf = subRL->_bf;
            //右左双旋
            RotateR(cur);
            RotateL(parent);
            if (bf == 1)
            {
              subR->_bf = 0;
              parent->_bf = -1;
            }
            else if (bf == -1)
            {
              parent->_bf = 0;
              subR->_bf = 1;
            }
          }

          //旋转结束，已经平衡，结束调整
          break;
        }
      }
      return true;
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
      if (parent != _root)
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
        _root = subR;
      }

      //链接subR 和 parent
      parent->_pParent = subR;

      //更新平衡因子
      subR->_bf = parent->_bf = 0;
    }


    //右旋
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
      if (parent != _root)
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
        _root = subL;
        //更新根节点
      }
      //4. 向上链接parent, subL
      parent->_pParent = subL;
      //更新平衡因子
      parent->_bf = subL->_bf = 0;

    }

    /*
       左右双旋的条件：parent->bf==-2;孩子结点bf==1;
       先左旋，后右旋
       左旋:RotateL(subL)
       右旋:RotateR(parent)
       */

    void Inorder()
    {
      _Inorder(_root);
      cout << endl;
    }

    void _Inorder(pNode root)
    {
      if (root)
      {
        _Inorder(root->_pLeft);
        cout << root->_data << " ";
        _Inorder(root->_pRight);
      }
    }

    int Height(pNode cur)
    {
      if (cur == nullptr)
        return 0;
      int left = Height(cur->_pLeft);
      int right = Height(cur->_pRight);
      return left > right ? left + 1 : right + 1;
    }

    bool IsBalance()
    {
      return _isBalance(_root);
    }

    bool _isBalance(pNode root)
    {
      if (root == nullptr)
        return true;
      int left = Height(root->_pLeft);
      int right = Height(root->_pRight);

      if (root->_bf != (right - left))
      {
        cout << root->_data << "--->" << root->_bf << "  " << (right - left) << endl;
        return false;
      }
      return abs(root->_bf) < 2 && _isBalance(root->_pLeft)
        && _isBalance(root->_pRight);
    }
  private:
    pNode _root = nullptr;
};

void testAVL()
{

  int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14  };

  AVLTree<int> avl;
  int num=sizeof(arr)/sizeof(arr[0]);
  for (int i = 0; i<num; i++)
  {
    avl.insert(arr[i]);
    cout << "插入值:"<<arr[i] << "--->" << "平衡因子:"<<avl.IsBalance() << endl;
  }
  avl.Inorder();
}

int main()
{
  testAVL();
  return 0;
}





























