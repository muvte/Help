void function2(int *a,int n) 
{ 
	int A [n]; 
	int i, s, j; 
	for (i = 0; i < n; i++) { 
		s = 0; 
		for (j = 0; j < n; j++) { 
			if (a[i] > a [j]) 
			s = s + 1; 
		} 
		A[s] = a[i]; 
	}
	for (i = 0; i < n; i++) {
	a[i] = A[i]; 
	}
	return 0;
}
