#include <stdio.h>
#include <stdlib.h>
#include "solve.h"
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
