

//the Next Node of BinaryTreeNode

//二叉树结点的下一结点
BinaryTreeNode* GetNextNode(BinaryTreeNode* pNode) {
	if (pNode == nullptr)
		return nullptr;
	BinaryTreeNode* pNext = nullptr;
	if (pNode->right != nullptr) {
		BinaryTreeNode* right = pNode->right;
		while (right->left != nullptr)
			right = right->left;

		pNext = right;
	}
	else if (pNode->parent != nullptr) {
		BinaryTreeNode* pCur = pNode;
		BinaryTreeNode* pParent = pNode->parent;
		while (pParent != nullptr && pCur == pParent->right) {
			pCur = pParent;
			pParent = pParent->parent;
		}
		pNext = pParent;
	}
	return pNext;
}
