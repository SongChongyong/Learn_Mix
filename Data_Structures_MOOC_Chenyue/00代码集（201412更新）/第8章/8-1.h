
struct People { /* �˿����� */
	int T;		/* �˿͵���ʱ�� */
	int P;		/* �˿����񱻴����ʱ�� */
};

struct QueueRecord { /* ���н�� */
	int front;	/* ͷָ�� */
	int rear;   /* βָ�� */
	int size;   /* ��ǰ�����е�Ԫ�ظ��� */
	struct People *Customer; /* �˿����� */
};

typedef struct QueueRecord *Queue;

Queue CreateQueue( int MaxElements );
void AddQ( Queue Q, struct People X );
struct People DeleteQ( Queue Q );
int IsEmpty( Queue Q );
