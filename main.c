#include <stdio.h>
#include <stdlib.h>
#include "solve.h"
#include "init_mat.h"
int main() {
	    int n, m;
	        double step;
		    scanf("%d %d %lf", &n, &m, &step);
		        double **matrix = (double **)malloc(sizeof(double *) * n);
			    double solution, max_elem, min_elem;
			        int x, y;
				    for(int i = 0; i < n; ++i)
					        {
							        matrix[i] = (double *)malloc(sizeof(double) * m);
								    }
				        init_matrix(matrix, n, m, step);
					    for(int i = 0; i < n; ++i)
						        {
								        for(int j = 0; j < m; ++j)
										        {
												            printf("%lf ", matrix[i][j]);
													            }
									        printf("\n");
										    }
					        printf("\n");
						    if(solve(matrix, n, m, &x, &y, &solution, &max_elem, &min_elem) == 1)
							        {
									        printf("%lf %lf %lf", max_elem, min_elem, solution);
										    }
						        else
								    {
									            printf("%lf %lf", max_elem, min_elem);
										        }
};
