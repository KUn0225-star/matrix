void init_matrix(double **matrix, int n, int m, double step)
{
	    for(int i = 0; i < n; ++i)
		        {
				        for (int j = 0; j < m; ++j)
						        {
								            matrix[i][j] = (i * step) * (i * step) - (j * step) * (j * step);
									            }
					    }
}
