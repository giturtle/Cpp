

状态：
  子状态：前1，2，3，...,n个字符能否根据词典中的词被成功分词
  F(i): 前i个字符能否根据词典中的词被成功分词
  
状态递推：
  F(i): true{j < i && F(j) && substr[j+1,i]能在词典中找到} OR false
  在j小于i中，只要能找到一个F(j)为true，并且从j+1到i之间的字符能在词典中找到，则F(i)为true
  
初始值：
  对于初始值无法确定的，可以引入一个不代表实际意义的空状态，作为状态的起始
  空状态的值需要保证状态递推可以正确且顺利的进行
  F(0) = true
  
返回结果：F(n)


bool wordBreak(string s, unordered_set<string> &dict){
	if (s.empty()){
		return false;
	}
	if (dict.empty()){
		return false;
	}
	
	// 获取词典中的单词的最大长度
	int max_length = 0;
	unordered_set<string>::iterator dict_iter= dict.begin();
	for (; dict_iter != dict.end(); dict_iter++){
		if ((*dict_iter).size() > max_length){
			max_length = (*dict_iter).size();
		}
	}
	vector<bool> can_break(s.size() + 1, false);
	// 初始化 F(0) = true
	can_break[0] = true;
	for (int i = 1; i <= s.size(); i++){
		for (int j = i - 1; j >= 0; j--){
			// 如果最小子串长度大于max_length，跳过
			if ((i - j) > max_length)	break;
			
			// F(i): true{j <i && F(j) && substr[j+1,i]能在词典中找到} OR false
			// 第j+1个字符的索引为j
			if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end()){
				can_break[i] = true;
				break;
			}
		}
	}
	return can_break[s.size()];
}
