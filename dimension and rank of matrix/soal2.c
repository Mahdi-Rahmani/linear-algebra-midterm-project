#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
void gotoxy(int x, int y);
int main(int argc, char *argv[])
 {
	int m , n;
	int pivot_num=0;
	int f=1;
	printf("please enter the number of rows:\n");
	scanf("%d",&m);
	printf("please enter the number of columns:\n");
	scanf("%d",&n);
	printf("a)please enter the elements of the matrix and seperate them with enter:\n");
	float matrix [m][n];
	int i , j;
	int a ,b;
	float E[m][n];
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
	//______________________________________________________________________
	// anjame amaliate satry
	int cpy;
	float cpy1;
	int z;
	float sort[1][n+1];
	for(i=0; i<m;i++)
	{
		for(j=0;j<n+1;j++)
		{
			if(i==j && j!=n)
			{
				if(matrix[i][j]==0)
				{
					if(j<n-1 && i<m-1)
					{
						cpy=i;
						while(matrix[cpy][j]==0 && cpy<m)
						{
							cpy++;
						}
						if(cpy<m)
						{
							
							for(f=0;f<n+1;f++)
							{
								sort[0][f]=matrix[cpy][f];
								matrix[cpy][f]=matrix[i][f];
								matrix[i][f]=sort[0][f];
							}
							counter++;			
						}
				
					}
				
				}
				counter2=0;
				if(matrix[i][j]!=0)
				{
					counter2++;
					for(z=i;z<m-1;z++)
					{
						cpy1=(matrix[z+1][j]/matrix[i][j]);
						if(matrix[z+1][j]==0)
							continue;
						for(f=0;f<n+1;f++)
						{
							matrix[z+1][f]+=(-1)*cpy1*matrix[i][f];
						}
						counter++;

					}
					
				}
				
			}
			else
			{
				if(counter2==0)
				{
					if(matrix[i][j]==0)
					{
						if(j<n && i<m-1)
						{
							cpy=i;
							while(matrix[cpy][j]==0 && cpy<m)
							{
								cpy++;
							}
							if(cpy<m)
							{
								
								for(f=0;f<n+1;f++)
								{
									sort[0][f]=matrix[cpy][f];
									matrix[cpy][f]=matrix[i][f];
									matrix[i][f]=sort[0][f];
								}
								counter++;
							
									
							}
					
						}
					
					}
					counter2=0;
					if(matrix[i][j]!=0)
					{
						counter2++;
						for(z=i;z<m-1;z++)
						{
							cpy1=(matrix[z+1][j]/matrix[i][j]);
							if(matrix[z+1][j]==0)
								continue;
							for(f=0;f<n+1;f++)
							{
								matrix[z+1][f]+=(-1)*cpy1*matrix[i][f];
							}
							counter++;

						}
						
					}
				
				}
			}
		}
	}
	//______________________________________________________________________________________
	for(i=0;i<m;i++)
	{
		a=0;
		for(j=0;j<n;j++)
		{
			if(matrix[i][j]!=0&&a==0)
			{
				pivot_num++;
				a++;
			}
		}
	}
	printf("b)dimention of the Nul(A) is:\ndim Nul(A)=%d\n",n-pivot_num);
	printf("c)rank of the matrix A is:\nrank(A)=%d",pivot_num);
}
void gotoxy(int x, int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
