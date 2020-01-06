
#define  MaxVertexNum  100   /* ��󶥵�����Ϊ100 */
#define  INFINITY  65535     /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef  char  VertexType;   /* ����������Ϊ�ַ��� */
typedef  int  EdgeType;      /* �ߵ�Ȩֵ��Ϊ���� */
enum GraphType { DG, UG, DN, UN };  
/* ����ͼ,����ͼ,������ͼ,������ͼ*/

typedef  struct {
	VertexType  Vertices[ MaxVertexNum ];  /* ����� */
	EdgeType  Edges[ MaxVertexNum ][ MaxVertexNum ]; /* �ڽӾ��󣬼��߱�  */
	int  n, e;   /* ������n�ͱ���e */
	enum GraphType GType;   /* ͼ�����ͷ�4�֣�UG��DG��UN��DN */
} MGraph;    /* MGragh�����ڽӾ���洢��ͼ���� */
