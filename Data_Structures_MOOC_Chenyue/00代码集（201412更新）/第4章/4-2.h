
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
	ElementType Element;  /*����ֵ��*/
	PtrToNode Next;       /*��һ������ָ����*/
};
