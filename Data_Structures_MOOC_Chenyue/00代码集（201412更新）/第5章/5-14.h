
int GetAWord( FILE *fp, ElementType word )
{
	int len = 0;
	char tempword[81];/* ��ʱ�ַ������ٶ����е��ʳ��Ȳ��ᳬ��80 */
	char c;

	c = fgetc(fp);
	while( !feof( fp ) ){
		if( IsWordChar(c) )  /* ����ǺϷ��ĵ����ַ� */
			tempword[len++] = c;
		    c = fgetc(fp);
		    if(len && !IsWordChar(c))/* �Ƿ��ĵ����ַ�����һ������*/
				break;  /* һ�����ʽ��� */
	    }
	    tempword[len] = '\0';   /* �趨�ַ��������� */
	    if(len > KEYLENGTH){    /* ̫���ĵ��ʱ��ض� */
		    tempword[KEYLENGTH] = '\0';
		    len = KEYLENGTH;
	    }
	    strcpy(word, tempword); /* ̫���ĵ��ʱ��ض� */
	    return len;		
}
