
int FindMin( int LowCost[ ],  int n )
{   /* ��V��VT�е�VT��С����ĵ� */
	int j, k, MinCost= INFINITY;
 
	for ( k = 0, j = 0; j < n; j++ )
		if ( LowCost[j] && LowCost[j]< MinCost ) {
			MinCost = LowCost[j];
			k = j;
		}

	return k;
}
