#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct TreeNode{
	int *group;
	int groupSize;
	TreeNode *left;
	TreeNode *right;
	//k为字符个数
	TreeNode(int *g,int k){
		group = new int[k]();
		groupSize = k;
		for (int i = 0; i < k; i++){
			group[i] = g[i];
		}
		left = NULL;
		right = NULL;
	}
}TreeNode,*BiTree;

int abss(int a){
	return a>=0?a:-a;
}
int countDifference(char *a, int *group, int n, int m, int k, int flag){
	int index=0;
	int minDifference = k;//总共k个，假设最大差别是k
	int *one = new int[n*m*k]();
	for (int i = 0; i < n*m*k; i++){
		one[i] = 0;
	}
	for (int i = 0; i < n*m; i++){
		for (int j = 0; j < k; j++){
			if (group[j] == flag){
				if (a[j*n*m + i] == '1'){
					one[i]++;
				}
				else{
					one[i]--;
				}
			}
		}
		if (minDifference>abss(one[i])){
			minDifference = abss(one[i]);
			index = i;
			if (minDifference == 0){
				break;
			}
		}
	}
	delete one;
	return index;
}

void creatTree(BiTree &root, int *data,char *a, int n, int m, int k){
	root = new TreeNode(data, k);
	int index;
	int count=0;
	int *lg = new int[k]();
	int *rg = new int[k]();
	for (int i = 0; i < root->groupSize; i++){
		if (root->group[i] == 1){
			count++;
		}
	}
	
	if (count != 1){
		index = countDifference(a, root->group, n, m, k, 1);
		for (int j = 0; j < k; j++){
			if (root->group[j] == 0){
				lg[j] = 0;
				rg[j] = 0;
				continue;
			}
			if (a[j*n*m + index] == '1'){
				lg[j] = 1;
				rg[j] = 0;
			}
			else{
				lg[j] = 0;
				rg[j] = 1;
			}
		}
		creatTree(root->left, lg,a, n, m, k);
		creatTree(root->right, rg,a, n, m, k);
	}

}

int max(int a,int b){
	return a>b?a:b;
}

int printTree(TreeNode *root,int k)
{
	if (root == NULL)return 0;
	// for (int i = 0; i < k; i++){
	// 	cout << root->group[i] << ' ';
	// }
	// cout << endl;
	return max(printTree(root->left, k)+1,printTree(root->right, k)+1);
}

int main()
{
	char tem[10];
	int n, m, k;
	cin >> n >> m >> k;
	char *a = (char *)malloc(sizeof(char)*n*m*k);
	int count = 0;
	int *group = new int[k]();
	for (int i = 0; i < k; i++){
		group[i] = 1;
	}
	cin.getline(tem, 10);
	for (int l = 0; l<n*m*k; l++)
	{
		if (l % (n*m) == 0)
		{
			cin.getline(tem,10);
		}
		a[l] = cin.get();
		if ((l+1)%m==0)
		{
			cin.get();
		}
	}
	BiTree root;
	creatTree(root, group, a, n, m, k);
	
	cout << printTree(root, k)-1 << endl;
}

d56db64f-3943-4483-9fe3-486430faa413