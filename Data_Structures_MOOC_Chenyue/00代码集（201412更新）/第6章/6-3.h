
#define  MaxVertexNum  100     /* ��󶥵���Ϊ100 */
enum GraphType { DG, UG, DN, UN }; 
/* ����ͼ,����ͼ,������ͼ,������ͼ*/

typedef  struct  node{          /* �߱��� */
  int AdjV;                   /* �ڽӵ��� */
  struct  node  *Next;       /* ָ����һ���ڽӵ��ָ���� */
  /* ��Ҫ��ʾ���ϵ�Ȩֵ��Ϣ����Ӧ����һ��������Weight */
} EdgeNode;        

typedef  char  VertexType;       /* �������ַ���ʾ */
typedef  struct  Vnode{           /* ������� */
  VertexType  Vertex;         /* ������ */
  EdgeNode  *FirstEdge;       /* �߱�ͷָ�� */
} VertexNode;   
    
typedef  VertexNode  AdjList[ MaxVertexNum ];
/* AdjList���ڽӱ����� */

typedef  struct{  
	AdjList  adjlist;       /* �ڽӱ� */
	int  n, e;              /* �������ͱ��� */
	enum GraphType GType;   /* ͼ�����ͷ�4�֣�UG��DG��UN��DN */
} ALGraph;  /*ALGraph�����ڽӱ�ʽ�洢��ͼ���� */
