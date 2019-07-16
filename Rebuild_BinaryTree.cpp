





struct BinaryTreeNode {
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};
BinaryTreeNode* ConstructCore(int *startPre, int *endPre, int *startIn, int *endIn) {
	int rootval = startPre[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->val = rootval;
	root->left = root->right = nullptr;

	if (startPre == endPre) {
		if (startPre == endPre	//只有一个节点
			&& *startPre == *startIn) {
			return root;
		}
		else
			throw std::exception("Invalid input");
	}
	int *rootInorder = startIn;
	while (rootInorder <= endIn && *rootInorder != rootval)
		++rootInorder;

	if (rootInorder == endIn && *rootInorder != rootval) 
		throw std::exception("Invalid input");
	int left = rootInorder - startIn;
	int *leftOrderEnd(startPre + left);
	if (left > 0) {
		//构建左子树
		root->left = ConstructCore(startPre + 1, leftOrderEnd, startIn, rootInorder - 1);
	}
	if (left < endPre - startPre) {
		//构建右子树
		root->right = ConstructCore(leftOrderEnd + 1, endPre, rootInorder + 1, endIn);
	}
	return root;
}
BinaryTreeNode* Construct(int *preorder, int* inorder, int length) {
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}
