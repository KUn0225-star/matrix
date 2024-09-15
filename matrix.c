
#include <stdio.h>
#include <stdlib.h>
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

int solve(double **matrix, int n, int m, int *i , int *j, double *solution, double *max_element, double *min_element)
{
	    double *min_els = (double *)malloc(sizeof(double) * n);
	        double *max_els = (double *)malloc(sizeof(double) * m);
		    for(int f = 0; f < n; ++f)
			        {
					        for(int g = 0; g < m; ++g)
							        {
									            if(f == 0)
											                {
														                max_els[g] = matrix[f][g];
																            }
										                else if(matrix[f][g] > max_els[g])
													            {
															                    max_els[g] = matrix[f][g];
																	                }
												            if(g == 0)
														                {
																	                min_els[f] = matrix[f][g];
																			            }
													                else if(matrix[f][g] < min_els[f])
																            {
																		                    min_els[f] = matrix[f][g];
																				                }
															        }
						    }
		        *min_element = min_els[0];
			    for (int f = 1; f < n; ++f)
				        {
						        if(min_els[f] < *min_element)
								        {
										            *min_element = min_els[f];
											            }
							    }
			        *max_element = max_els[0];
				    for (int g = 1; g < m; ++g)
					        {
							        if(max_els[g] > *max_element)
									        {
											            *max_element = max_els[g];
												            }
								    }
				        for(int f = 0; f < n; ++f)
						    {
							            for(int g = 0; g < m; ++g)
									            {
											                if(matrix[f][g] == min_els[f] && matrix[f][g] == min_els[g])
														            {
																                    *solution = matrix[f][g];
																		                    *i = f;
																				                    *j = g;
																						                    return 1;
																								                }
													        }
								        }
					    return 0;
}
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
