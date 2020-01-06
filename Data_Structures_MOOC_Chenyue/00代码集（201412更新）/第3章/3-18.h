
void Path( )
{ 
	int i, Row, Col, NextRow, NextCol, Dir, Found = FALSE;
	int Mark[MAXMATRIXSIZE][MAXMATRIXSIZE]; /* ���λ���Ƿ��߹� */
	ElementType Position;
	Stack S;
	S.Top = -1;  /* ��ջ��ʼ��Ϊ�� */

	Mark[1][1] = 1;      /* �����λ�ÿ�ʼ�����Ϊ�߹� */
	/* �����λ�ü���һ����������ջ */
	S.Top++;
	S.Data[S.Top].Row = 1;
	S.Data[S.Top].Col = 1;
	S.Data[S.Top].Dir = 2; 
	/* ע�⣺�����ܴ�������ߣ����Է�����Ŵ�2��ʼ�������򶫿�ʼ */
    
	while ( S.Top > -1 && !Found ) { /* ��ջ�ǿ���û�ҵ�����ʱ */
		Position = Pop(&S); /* ȡ��ջ��Ԫ��Ϊ��ǰλ�� */
		Row = Position.Row; Col = Position.Col; Dir = Position.Dir;
		while ( Dir < 8 && !Found ) {/* �����з����̽��û�ҵ�����ʱ */
			/*��������һ������Dir�ƶ� */
			NextRow = Row + Move[Dir].Vert;
			NextCol = Col + Move[Dir].Horiz;
			if ( NextRow == EXITROW && NextCol == EXITCOL )  
				/* ��������� */
				Found = TRUE;
			else  /* ��һ��λ�ò��ǳ��� */
				if ( !Maze[NextRow][NextCol] && !Mark[NextRow][NextCol] ){
					/* ����һ��λ�ÿ�ͨ����û�߹� */
					Mark[NextRow][NextCol] = 1; /* ���Ϊ�߹� */
					Position.Row = Row;
					Position.Col = Col;
					Position.Dir = Dir + 1;
					Push(&S, Position);  /* ��ǰλ�ú���һ���������ջ */
					/* ���µ�ǰλ�ã��ӷ���0��ʼ */
					Row = NextRow; Col = NextCol; Dir = 0;
				} /* ����if */
				else ++Dir; /* ����·��ͨ�����ڵ�ǰλ�ó�����һ������ */
		} /* ����8����̽�� */
	} /* �������� */
	if ( Found ) {    /* �ҵ�һ��·�����������·�� */
		printf ("The path is:\n");
		printf ("row  col\n");
		for ( i = 0; i <= S.Top; i++ )
			printf ("%d %d\n", S.Data[i].Row, S.Data[i].Col);
		printf ("%d %d\n", Row, Col); /* ��Ҫ�������һ��δ���ջ */
		printf ("%d %d\n", EXITROW, EXITCOL); /* ��ӡ���� */
	}
	else /* ��û�ҵ�·�� */
		printf ("The maze does not have a path\n");
}
