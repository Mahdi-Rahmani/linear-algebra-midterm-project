#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
void gotoxy(int x, int y);
int main(int argc, char *argv[])
 {
	int m , n;
	int e,w;
	int pivot_num=0;
	int f=1;
	printf("please enter the number of rows of the coefficients matrix:\n");
	scanf("%d",&m);
	printf("please enter the number of columns the coefficients matrix:\n");
	scanf("%d",&n);
	printf("please enter the elements of the coefficients matrix and seperate them with enter:\n");
	float matrix [m][n];
	int i , j;
	int a ,b;
	
	float E[m][m];
	float sortE[1][m];
	for(a=0; a<m;a++)
	{
		for(b=0;b<m;b++)
		{
			if(a==b)
			{
				E[a][b]=1;
			}	
			else
				E[a][b]=0;
		}
	}
								
	int counter=0;
	int counter2=0;
	//_____________________________________________________________________
	//gereftane marixe zarayeb
	for(i=0; i<m;i++)
	{
		f=1;
		for(j=0;j<n;j++)
		{
			
			gotoxy(j+f,i+5);
			scanf("%f",&matrix[i][j]);
			f+=2;
		}
	}
	e=0;
	printf("   ");
	for(e=0;e<(n+1)*13-3;e++)		
		printf("*");
	printf("\n");
	//_____________________________________________________________________
	//gereftan sotune javabha
	float ans[m][1];
	printf(" please enter the column of the answer:\n");
	for(i=0; i<m;i++)
	{
		scanf("%f",&ans[i][0]);
	}
	e=0;
	printf("   ");
	for(e=0;e<(n+1)*13-3;e++)		
		printf("*");
	printf("\n");
	//_____________________________________________________________________
	// tashkile matrixe afzoode
	float aug_matrix[m][n+1];
	printf("  now the augmented matrix is:\n");
	for(i=0; i<m;i++)
	{
		
		f=1;
		for(j=0;j<n+1;j++)
		{
			if(j<n)
			{
				aug_matrix[i][j]=matrix[i][j];
			}
			else
			{
				aug_matrix[i][j]=ans[i][0];
			}
			gotoxy(j+f,i+2*m+9);
			printf("%f",aug_matrix[i][j]);
			f+=9;
		}
	}
	gotoxy(0,i+2*m+10);
	e=0;
	printf("   ");
	for(e=0;e<(n+1)*13-3;e++)		
		printf("*");
	printf("\n");
	//______________________________________________________________________
	// anjame amaliate satry
	int cpy;
	float cpy1;
	int z;
	float sort[1][n+1];
	for(i=0; i<m;i++)
	{
		for(a=0; a<m;a++)
		{
			for(b=0;b<m;b++)
			{
				if(a==b)
				{
					E[a][b]=1;
				}	
				else
					E[a][b]=0;
			}
		}
		for(j=0;j<n+1;j++)
		{
			if(i==j && j!=n)
			{
				if(aug_matrix[i][j]==0)
				{
					if(j<n-1 && i<m-1)
					{
						cpy=i;
						while(aug_matrix[cpy][j]==0 && cpy<m)
						{
							cpy++;
						}
						if(cpy<m)
						{
							
							for(f=0;f<n+1;f++)
							{
								sort[0][f]=aug_matrix[cpy][f];
								aug_matrix[cpy][f]=aug_matrix[i][f];
								aug_matrix[i][f]=sort[0][f];
							}
							counter++;
						
					
//**************************************************************************************(namayesh)
							//elementry
							printf("\n   the elementry matrix for operation%d:\n",counter);
							for(a=0; a<m;a++)
							{
								printf("    ");
								for(b=0;b<m;b++)
								{
									if(a==i)
									{
										sortE[0][b]=E[cpy][b];
										E[cpy][b]=E[i][b];
										E[i][b]=sortE[0][b];
									}
									
								}
								for(b=0;b<m;b++)
								{
									printf("%6.2f",E[a][b]);
								}
								printf("\n");
							}	
							//augmented matrix after operations
							printf("\n   the augmented matrix after operation%d:\n",counter);
							for(a=0; a<m;a++)
							{
								for(b=0;b<n+1;b++)
								{
				
									printf("%12f",aug_matrix[a][b]);
								
								}
								printf("\n");
							}
							//equation
							printf("\n   equation after operation%d:\n",counter);
							for(a=0; a<m;a++)
							{
								printf("      ");
								for(b=0;b<n+1;b++)
								{
									if(b==n)
									{
										printf("= %11f",aug_matrix[a][b]);
									}
									else
									{
										if(aug_matrix[a][b]==0)
										{
									
											printf("%-9c",32);
										}
										else
											printf("%.2f x%d  ",aug_matrix[a][b],b+1);
										e=0;
										for(w=b+1;w<n;w++)
										{
											if(aug_matrix[a][w]!=0)
												e++;
										}
										if(e!=0&&aug_matrix[a][b]!=0)
										{
											printf(" + ");
										}
									}
				
								}
								printf("\n");
							}		
							e=0;
							printf("   ");
							for(e=0;e<(n+1)*13-3;e++)		
								printf("*");
							printf("\n");
							//equation		
//**************************************************************************************						
						}
				
					}
				
				}
				counter2=0;
				if(aug_matrix[i][j]!=0)
				{
					counter2++;
					for(z=i;z<m-1;z++)
					{
						for(a=0; a<m;a++)
						{
							for(b=0;b<m;b++)
							{
								if(a==b)
								{
									E[a][b]=1;
								}	
								else
									E[a][b]=0;
							}
						}
						cpy1=(aug_matrix[z+1][j]/aug_matrix[i][j]);
						if(aug_matrix[z+1][j]==0)
							continue;
						for(f=0;f<n+1;f++)
						{
							aug_matrix[z+1][f]+=(-1)*cpy1*aug_matrix[i][f];
						}
						counter++;
	//**************************************************************************************(namayesh)	
						//elementry
						printf("\n   the elementry matrix for operation%d:\n",counter);
						for(a=0; a<m;a++)
						{
							printf("    ");
							for(b=0;b<m;b++)
							{	
								if(a==z&&b==j)
								{
									if(cpy1!=0)
									E[z+1][b]+=(-1)*cpy1*E[i][b];
								}
							
								printf("%6.2f",E[a][b]);
							}
							printf("\n");
						}	
						//augmented matrix after operations				
						printf("\n   the augmented matrix after operation%d:\n",counter);
						for(a=0; a<m;a++)
						{
							for(b=0;b<n+1;b++)
							{
			
								printf("%12f",aug_matrix[a][b]);
								
							}
							printf("\n");
						}		
						//equation
						printf("\n   equation after operation%d:\n",counter);
						for(a=0; a<m;a++)
						{
							printf("      ");
							for(b=0;b<n+1;b++)
							{
								if(b==n)
								{
									printf("= %11f",aug_matrix[a][b]);
								}
								else
								{
									if(aug_matrix[a][b]==0)
									{
										
										printf("%-9c",32);
									}
									else
									printf("%.2f x%d  ",aug_matrix[a][b],b+1);
									e=0;
									for(w=b+1;w<n;w++)
									{
										if(aug_matrix[a][w]!=0)
											e++;
									}
									if(e!=0&&aug_matrix[a][b]!=0)
									{
										printf(" + ");
									}
								}
					
							}
							printf("\n");
						}		
							e=0;
							printf("   ");
							for(e=0;e<(n+1)*13-3;e++)		
								printf("*");
							printf("\n");
						//equation	
	//**************************************************************************************
					}
					
				}
				
			}
			else
			{
				if(counter2==0)
				{
					if(aug_matrix[i][j]==0)
					{
						if(j<n && i<m-1)
						{
							cpy=i;
							while(aug_matrix[cpy][j]==0 && cpy<m)
							{
								cpy++;
							}
							if(cpy<m)
							{
								
								for(f=0;f<n+1;f++)
								{
									sort[0][f]=aug_matrix[cpy][f];
									aug_matrix[cpy][f]=aug_matrix[i][f];
									aug_matrix[i][f]=sort[0][f];
								}
								counter++;
							
						
	//**************************************************************************************(namayesh)
								//elementry
								printf("\n   the elementry matrix for operation%d:\n",counter);
								for(a=0; a<m;a++)
								{
									printf("    ");
									for(b=0;b<m;b++)
									{
										if(a==i)
										{
											sortE[0][b]=E[cpy][b];
											E[cpy][b]=E[i][b];
											E[i][b]=sortE[0][b];
										}
										
									}
									for(b=0;b<m;b++)
									{
										printf("%6.2f",E[a][b]);
									}
									printf("\n");
								}	
								//augmented matrix after operations
								printf("\n   the augmented matrix after operation%d:\n",counter);
								for(a=0; a<m;a++)
								{
									for(b=0;b<n+1;b++)
									{
					
										printf("%12f",aug_matrix[a][b]);
									
									}
									printf("\n");
								}
								//equation
								printf("\n   equation after operation%d:\n",counter);
								for(a=0; a<m;a++)
								{
									printf("      ");
									for(b=0;b<n+1;b++)
									{
										if(b==n)
										{
											printf("= %11f",aug_matrix[a][b]);
										}
										else
										{
											if(aug_matrix[a][b]==0)
											{
										
												printf("%-9c",32);
											}
											else
												printf("%.2f x%d  ",aug_matrix[a][b],b+1);
											e=0;
											for(w=b+1;w<n;w++)
											{
												if(aug_matrix[a][w]!=0)
													e++;
											}
											if(e!=0&&aug_matrix[a][b]!=0)
											{
												printf(" + ");
											}
										
										}
					
									}
									printf("\n");
								}		
								e=0;
								printf("   ");
								for(e=0;e<(n+1)*13-3;e++)		
									printf("*");
								printf("\n");
								//equation		
	//**************************************************************************************						
							}
					
						}
					
					}
					counter2=0;
					if(aug_matrix[i][j]!=0)
					{
						counter2++;
						for(z=i;z<m-1;z++)
						{
							cpy1=(aug_matrix[z+1][j]/aug_matrix[i][j]);
							if(aug_matrix[z+1][j]==0)
								continue;
							for(f=0;f<n+1;f++)
							{
								aug_matrix[z+1][f]+=(-1)*cpy1*aug_matrix[i][f];
							}
							counter++;
		//**************************************************************************************(namayesh)	
							//elementry
							printf("\n   the elementry matrix for operation%d:\n",counter);
							for(a=0; a<m;a++)
							{
								for(b=0;b<m;b++)
								{	
									printf("    ");
									if(a==z&&b==j)
									{
										if(cpy1!=0)
										E[z+1][b]+=(-1)*cpy1*E[i][b];
									}
								
									printf("%6.2f",E[a][b]);
								}
								printf("\n");
							}	
							//augmented matrix after operations							
							printf("\n   the augmented matrix after operation%d:\n",counter);
							for(a=0; a<m;a++)
							{
								for(b=0;b<n+1;b++)
								{
				
									printf("%12f",aug_matrix[a][b]);
									
								}
								printf("\n");
							}		
							//equation
							printf("\n   equation after operation%d:\n",counter);
							for(a=0; a<m;a++)
							{
								printf("      ");
								for(b=0;b<n+1;b++)
								{
									if(b==n)
									{
										printf("= %11f",aug_matrix[a][b]);
									}
									else
									{
										if(aug_matrix[a][b]==0)
										{
											
											printf("%-9c",32);
										}
										else
											printf("%.2f x%d  ",aug_matrix[a][b],b+1);
										e=0;
										for(w=b+1;w<n;w++)
										{
											if(aug_matrix[a][w]!=0)
												e++;
										}
										if(e!=0&&aug_matrix[a][b]!=0)
										{
											printf(" + ");
										}
									}
						
								}
								printf("\n");
							}		
							e=0;
							printf("   ");
							for(e=0;e<(n+1)*13-3;e++)		
								printf("*");
							printf("\n");
							//equation	
		//**************************************************************************************
						}
						
					}
				
				}
			}
		}
	}
	//______________________________________________________________________________________
	// marhale 5 amaliate satry va haman kahesh
	float cpy2;
	for(i=m-1;i>=0;i--)
	{
		for(a=0; a<m;a++)
		{
			for(b=0;b<m;b++)
			{
				if(a==b)
				{
					E[a][b]=1;
				}	
				else
					E[a][b]=0;
			}
		}
		j=0;
		while(aug_matrix[i][j]==0 && j<n-1)
		{
			j++;
			if(aug_matrix[i][j]>0)
			{
				if(aug_matrix[i][j]<0.00001)
				{
					aug_matrix[i][j]=0;
				}
			}
			else
			{
				if(-aug_matrix[i][j]<0.00001)
				{
					aug_matrix[i][j]=0;
				}
			}
			
			
		}
		if(aug_matrix[i][j]!=0)
		{

			// yek kardane pivot
			if(aug_matrix[i][j]!=1)
			{
			cpy2=aug_matrix[i][j];
			for(f=j;f<n+1;f++)
			{
				aug_matrix[i][f]/=cpy2;
				
			}
			counter++;
//**************************************************************************************(namayesh)
			//elementry
			printf("\n   the elementry matrix for operation%d:\n",counter);
			for(a=0; a<m;a++)
			{
				for(b=0;b<m;b++)
				{	
					printf("    ");
					if(a==i&&b==j)
					{
						E[a][b]/=cpy2;
					}
					
				printf("%6.2f",E[a][b]);
				}
			printf("\n");
			}	
			//augmented matrix after operations			
			printf("\n   the augmented matrix after operation%d:\n",counter);
			for(a=0; a<m;a++)
			{
				for(b=0;b<n+1;b++)
				{
					printf("%12f",aug_matrix[a][b]);
							
				}
				printf("\n");
			}
			//equation
			printf("\n   equation after operation%d:\n",counter);
			for(a=0; a<m;a++)
			{
				printf("      ");
				for(b=0;b<n+1;b++)
				{
					if(b==n)
					{
						printf("= %11f",aug_matrix[a][b]);
					}
					else
					{
						if(aug_matrix[a][b]==0)
						{
								
							printf("%-9c",32);
						}
						else
						printf("%.2f x%d  ",aug_matrix[a][b],b+1);
						e=0;
						for(w=b+1;w<n;w++)
						{
							if(aug_matrix[a][w]!=0)
								e++;
						}
						if(e!=0&&aug_matrix[a][b]!=0)
						{
							printf(" + ");
						}
					}
			
				}
				printf("\n");
			}		
			e=0;
			printf("   ");
			for(e=0;e<(n+1)*13-3;e++)		
				printf("*");
			printf("\n");
			}
			//equation
//**************************************************************************************
			//0 kardane balaye pivot
			if(i!=0)
			{		
			for(z=i;z>0;z--)
			{
				for(a=0; a<m;a++)
				{
					for(b=0;b<m;b++)
					{
						if(a==b)
						{
							E[a][b]=1;
						}	
						else
							E[a][b]=0;
					}
				}
				if(aug_matrix[z-1][j]==0)
					continue;
				cpy1=(aug_matrix[z-1][j]/aug_matrix[i][j]);
				for(f=0;f<n+1;f++)
				{
					aug_matrix[z-1][f]+=(-1)*cpy1*aug_matrix[i][f];
				}
				counter++;
//**************************************************************************************(namayesh)
				//elementry
				printf("\n  the elementry matrix for operation%d:\n",counter);
				for(a=0; a<m;a++)
				{
					for(b=0;b<m;b++)
					{	
						printf("    ");
						if(a==z-1&&b==j)
						{
							if(cpy1!=0)
								E[z-1][b]+=(-1)*cpy1*E[i][b];
						}
						printf("%6.2f",E[a][b]);
					}
					printf("\n");
				}	
				//augmented matrix after operations			
				printf("\n   the augmented matrix after operation%d:\n",counter);
				for(a=0; a<m;a++)
				{
					for(b=0;b<n+1;b++)
					{
		
						printf("%12f",aug_matrix[a][b]);
							
					}
					printf("\n");
				}
				//equation
				printf("\n   equation after operation%d:\n",counter);
				for(a=0; a<m;a++)
				{
					printf("      ");
					for(b=0;b<n+1;b++)
					{
						if(b==n)
						{
							printf("= %11f",aug_matrix[a][b]);
						}
						else
						{
							if(aug_matrix[a][b]==0)
							{
								
								printf("%-9c",32);
							}
							else
							{
								printf("%.2f x%d  ",aug_matrix[a][b],b+1);
							
							}
							e=0;
							for(w=b+1;w<n;w++)
							{
								if(aug_matrix[a][w]!=0)
								e++;
							}
							if(e!=0&&aug_matrix[a][b]!=0)
							{
								printf(" + ");
							}
							
						}
			
					}
					printf("\n");
				}
				e=0;
				printf("   ");
				for(e=0;e<(n+1)*13-3;e++)		
					printf("*");
				printf("\n");
				//equation
//**************************************************************************************
			}
			}
			
		}

	}


//-----------------
int q=0;
	for(q=3*m+10;q<((counter+1)*(3*m+7))+4;q++)
	{
		gotoxy(0,q);
		printf("*");
		gotoxy((n+1)*13+3,q);
		printf("*");
	}
//barresie javabe moadele

if(q==(counter+1)*(3*m+7)+4)
{
	b=0;
	int g=0;
	int free[n][1];
	int free_pos[n];
	int max=0;
	int jj=0;
	int o=0;
	for(i=0;i<n;i++)
	{
		free[i][1]=0;
		free_pos[i]=0;
	}
	float x[n][1];
	int s;
	counter=0;
	while(aug_matrix[m-1][b]==0 && b<n)
	{
		b++;
	}
	if(b==n && aug_matrix[m-1][b]!=0)
	{
		gotoxy(0,q+2);
		printf("\n    the equation is inconsistent    \n");
	}
	else
	{
	
		for(a=0; a<m;a++)
		{
			j=0;
			for(b=0;b<n;b++)
			{
			
				if(aug_matrix[a][b]!=0)
				{
					j++;
				}
			}
			if(j==1)
			{
				pivot_num++;
			}
		}
		if(pivot_num==n)
		{
			gotoxy(0,q+2);
			printf("  the equation is consistent and has a unique answer:\n X=\n");
			for(b=0;b<m;b++)
			{
				printf("   %f\n",aug_matrix[b][n]);
			}
		}
		else// bishomar javab
		{
			gotoxy(0,q+2);
			printf("  the equation is consistent and has countless answer:\n X=\n");
			for(a=0; a<m;a++)
			{
				g=0;
				while(counter+1==free[g][1] && g<i+1)
				{
					printf("  ");
					printf("x%d",free[g][1]);
					printf("\n");
					g++;
					jj++;
					counter++;
					o++;
				}
				j=0;
				i=0;
				for(b=0;b<n;b++)
				{
					if(aug_matrix[a][b]!=0)
					{
						j++;
						if(j>1)
						{
							free[i][1]=b+1;
							free_pos[b]=b;
							i++;		
						}
					}
				}
				printf("  ");
				printf("%.2f",aug_matrix[a][n]);
				for(f=0;f<i;f++)
				{
					s=free[f][1]-1;
					printf("+(%.2f x%d)",-aug_matrix[a][s],free[f][1]);
				}
				printf("\n");
					counter++;
			}
		
			for(f=0;f<n;f++)
			{
				if(	free_pos[f]!=0)
				{
					free[max][1]=f+1;
					max++;
				}
			}
			int spe=0;
			if(free[0][1]>m || o!=max)
			{
				if(o!=max&&free[o][1]>m&&jj!=0)
					spe++;
				for(f=o;f<max;f++)
				{
					printf("  ");
					printf("x%d",free[f][1]);
					printf("\n");
				}
				
			}
		///////////////////////////////////////////////////////////// namayesh bordari bishomar javab
			float vec[n][max+1]	;
			g=0;
			 o=0;
			for(f=0;f<n;f++)
			{
				for(g=0;g<max+1;g++)
				{
					if(g==0)
					{
						if(f!=free_pos[f]||f==0)
						{
							vec[f][0]=aug_matrix[o][n];
							o++;
						}
						else
						{
							vec[f][0]=0;
						}
					}
					else
					{
						if(f!=free[g-1][1]-1)
						{
							if(f<m)
							{
								i=0;
								if(f==m-1&&spe!=0)
								{
									while(aug_matrix[m-1][i]==0)
									{
										i++;
									}
									s=free[g-1][1]-1;
									vec[i][g]=-aug_matrix[f][s];
									vec[f][g]=0;
								
								}
								else
								{
									s=free[g-1][1]-1;
									vec[f][g]= -aug_matrix[f][s];
								}
	
							}
							else
							{
								if(i==0)
									vec[f][g]=0;
							}

						}
						else
						{
							vec[f][g]=1;
						}
					}
					
				}
			}
			g=0;
				gotoxy(1,q+5+n+(n/2));
					printf("X=");
				for(f=0;f<max;f++)
				{
					gotoxy(5+14*f+9,q+5+n+(n/2));
					printf("+x%d *",free[f][1]);
				}
			if(f==max)
			{
				g=1;
			}
			gotoxy(1,q+4+n);
			printf("the vector form of the answer:\n");
			for(f=0;f<n;f++)
			{

				for(g=0;g<max+1;g++)
				{
					gotoxy(5+14*g,q+5+n+f);
					printf("|%4.2f",vec[f][g]);
					gotoxy(5+14*g+8,q+5+n+f);
					printf("|");

				}
				printf("\n");
			}
			////////////////////////////////////////////////////////////

		}
	}
	
}
	return 0;

}
void gotoxy(int x, int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
