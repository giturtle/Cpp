

struct RandomListNode* copyRandomList(struct RandomListNode *head) {
	//判断极端情况，链表为空
	if (head == NULL) {
		return NULL;
	}

	//1. 复制原链表，让新的结点跟在老的结点后边
	struct RandomListNode *oldNode = head;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = CreateNode(oldNode->label);	//调用创建结点函数
		newNode->next = oldNode->next;	//把老链表当前结点的下一结点接在新结点之后
		oldNode->next = newNode;		//把新链表结点接在老链表结点之后
		oldNode = oldNode->next->next;	//此时老结点一次走两步才能指向老链表中的结点
	}

	//2. 处理random指针
	oldNode = head;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = oldNode->next;
		if (oldNode->random != NULL) {
			newNode->random = oldNode->random->next;
			//相当于oldNode->next->random = oldNode->random->next
		}
		oldNode = oldNode->next->next;
	}

	//3. 把一个链表拆分成两个链表
	oldNode = head;
	struct RandomListNode *newHead = head->next;		//保存新链表的头指针
	while (oldNode != NULL) {
		struct RandomListNode *newNode = oldNode->next;
		oldNode->next = newNode->next;
		if (oldNode->next != NULL) {
			newNode->next = oldNode->next->next;
			//形如 1->3  2->4
		}
		else {			
			newNode->next = NULL;	//其实没必要特殊处理，因为它本身就是空指针
		}

		//oldNode->next 已经更新，所以往后走一个next单位即为原来老链表的两个单位
		oldNode = oldNode->next;
	}
	return newHead;
}
