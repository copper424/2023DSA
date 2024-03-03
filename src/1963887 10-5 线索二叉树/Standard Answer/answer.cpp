 
#include <cstdio>
#include <cstdlib>
#include<iostream>
#include <type_traits>
using namespace std;
typedef struct ThreadNode{
	char data;
	struct ThreadNode *lchild;
	struct ThreadNode *rchild;
	int ltag,rtag;//左右线索标志位
}ThreadNode,*ThreadTree;
 
ThreadNode *pre=NULL;//定义全局变量
 
//先建立一棵二叉树
void creat_ThreadTree(ThreadTree &T){
	char data;
	cin>>data;
	if(data=='#'){
		T=NULL;return;
	}else{
	T=(ThreadNode *)malloc(sizeof(ThreadNode));
	T->data=data;
	T->lchild=NULL;
	T->rchild=NULL;
	T->ltag=0;
	T->rtag=0;
	creat_ThreadTree(T->lchild);
	creat_ThreadTree(T->rchild);
	}
}
//中序线索化,对每个节点的处理
void visit(ThreadNode *q){
	if(q->lchild==NULL){//寻找前驱
	q->lchild=pre;
	q->ltag=1;//标志位为1，表示q节点的左指针指向的是前驱，而不是孩子
	}
	if(pre!=NULL&&pre->rchild==NULL){//这两个条件不能写反，因为在pre为NULL情况下访问它的右孩子，会导致程序崩溃
		pre->rchild=q;
		pre->rtag=1;
	}
	pre=q;
 
}
//对整棵树的所有节点做处理
void InThread(ThreadTree T){
	if(T!=NULL){
 
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}
void creat_InThread(ThreadTree T){
	pre=NULL;
	if(T!=NULL){
		InThread(T);
		if(pre->rchild==NULL)
		pre->rtag=1;//最后一个节点要单独做处理，后继一定是NULL，标志为1
	}
}
//中序线索二叉树遍历
//1.求中序线索二叉树中序下的第一个节点
ThreadNode *FirstNode(ThreadNode *p){
	while(p->ltag==0) p=p->lchild;
	return p;
}
//2.求节点p在中序序列下的后继
ThreadNode *NextNode(ThreadNode *p){
	if(p->rtag==0) return FirstNode(p->rchild);//p的右子树的左下角的元素就是它的后继
	else return p->rchild;
}
void Outp(ThreadNode *i){
	cout<<i->data<<" ";
 
}
//利用上面1、2算法可以对中序线索二叉树进行遍历
void Inorder(ThreadNode *T){
	for(ThreadNode *i=FirstNode(T);i!=NULL;i=NextNode(i))
	Outp(i);
}
//3.找到中序线索二叉树中序遍历的最后一个节点
ThreadNode *LastNode(ThreadNode *p){
	while(p->rtag==0) p=p->rchild;
	return p;
}
//4.求节点p在中序遍历下的前驱
ThreadNode *PreNode(ThreadNode *p){
	if(p->ltag==0) return LastNode(p->lchild);//p的左子树右下角元素是它的前驱
	else return p->lchild;
}
//利用上面3、4算法可对中序线索二叉树进行逆向遍历
void RevInorder(ThreadNode *T){
	for(ThreadNode *i=LastNode(T);i!=NULL;i=PreNode(i))
	Outp(i);
}
 
int main(){
	ThreadTree T;
	creat_ThreadTree(T);
 
	creat_InThread(T);
	cout<<"中序顺序遍历结果："<<endl;
	Inorder(T);
    puts("");
    cout<<"中序逆序遍历结果："<<endl;
	RevInorder(T);
	return 0;
}