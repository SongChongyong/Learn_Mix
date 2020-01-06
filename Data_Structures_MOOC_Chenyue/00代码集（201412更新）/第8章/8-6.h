
struct People { 
	int T; 
	int P; 
    int VIP; /* VIP��־��1=VIP��0=��ͨ��-1=ɾ�� */
};

struct QueueRecord {
	int front; 
	int rear;
	int size;
	struct People *Customer;
    /*--������VIP���е���ӦԪ��--*/
	int VIPfront;
	int VIPrear;
	int VIPsize;
	int *VIPCustomer;
	/*------------------------*/
};
typedef struct QueueRecord *Queue;

Queue CreateQueue( int MaxElements );
void AddQ( Queue Q, struct People X );
struct People DeleteQ( Queue Q );
int IsEmpty( Queue Q );
void AddVIP( Queue Q, int Position );   /* ��VIP�ͻ������в��� */
struct People DeleteVIP( Queue Q );     /* ��VIP�ͻ��ĳ��в��� */
