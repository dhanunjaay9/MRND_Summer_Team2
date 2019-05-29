#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
char* customstrrev(char *string)
{
	int len = 0;
	for (int i = 0; string[i] != 0; i++, len++);
	char *reverse = (char *)malloc(len*sizeof(int));
	for (int i = 0, j = len - 1; i < j; i++, j--)
	{
		reverse[i] = string[j];
		reverse[j] = string[i];
	}
	return reverse;
}
int stringtoeast(char **Array,int currow,int curcolumn,int row,int column,char *string)
{
	int len = 0;
	for (int i = 0; string[i] != 0; i++, len++);
	int front = 0, rear = len - 1;
	while (string[front] != '\0'&&curcolumn < column)
	{
		if (Array[currow][curcolumn++] == string[front])
			front++;
		else
			break;
	}
	if (string[front]=='\0')
		return 1;
	return 0;
}
int stringtowest(char **Array, int currow, int curcolumn, int row, int column, char *string)
{
	int len = 0;
	for (int i = 0; string[i] != 0; i++, len++);
	int front = 0, rear = len - 1;
	while (string[front] != '\0'&&curcolumn >= 0)
	{
		if (Array[currow][curcolumn--] == string[front])
			front++;
		else
			break;
	}
	if (string[front] == '\0')
		return 1;
	return 0;
}
int stringtosouth(char **Array, int currow, int curcolumn, int row, int column, char *string)
{
	int len = 0;
	for (int i = 0; string[i] != 0; i++, len++);
	int front = 0, rear = len - 1;
	while (string[front] != '\0'&&currow < row )
	{
		if (Array[currow++][curcolumn] == string[front])
			front++;
		else
			break;
	}
	if (string[front] == '\0')
		return 1;
	return 0;
}
int stringtonorth(char **Array, int currow, int curcolumn, int row, int column, char *string)
{
	int len = 0;
	for (int i = 0; string[i] != 0; i++, len++);
	int front = 0, rear = len - 1;
	while (string[front] != '\0'&&currow >= 0 )
	{
		if (Array[currow--][curcolumn] == string[front])
			front++;
		else
			break;
	}

	if (string[front] == '\0')
		return 1;
	return 0;

}
int stringtonortheast(char **Array, int currow, int curcolumn, int row, int column, char *string)
{
	int len = 0;
	for (int i = 0; string[i] != 0; i++, len++);
	int front = 0, rear = len - 1;
	while (string[front] != '\0'&&currow >= 0 && curcolumn < column )
	{
		if (Array[currow--][curcolumn++] == string[front])
			front++;
		else
			break;
	}
	if (string[front] == '\0')
		return 1;
	return 0;
}
int stringtonorthwest(char **Array, int currow, int curcolumn, int row, int column, char *string)
{
	int len = 0;
	for (int i = 0; string[i] != 0; i++, len++);
	int front = 0, rear = len - 1;
	while (string[front] != '\0'&&currow >= 0 && curcolumn >= 0)
	{
		if (Array[currow--][curcolumn--] == string[front])
			front++;
		else
			break;
	}
	if (string[front] == '\0')
		return 1;
	return 0;
}
int stringtosoutheast(char **Array, int currow, int curcolumn, int row, int column, char *string)
{
	int len = 0;
	for (int i = 0; string[i] != 0; i++, len++);
	int front = 0, rear = len - 1;
	while (string[front] != '\0'&&currow<row && curcolumn < column )
	{
		if (Array[currow++][curcolumn++] == string[front])
			front++;
		else
			break;
	}
	if (string[front] == '\0')
		return 1;
	return 0;
}
int stringtosouthwest(char **Array, int currow, int curcolumn, int row, int column, char *string)
{
	int len = 0;
	for (int i = 0; string[i] != 0; i++, len++);
	int front = 0, rear = len - 1;
	while (string[front] != '\0'&&currow <row && curcolumn >= 0 )
	{
		if (Array[currow++][curcolumn--] == string[front])
			front++;
		else
			break;
	}
	if (string[front] == '\0')
		return 1;
	return 0;
}
void findstringinmatrix(char **Array, int row, int column, char *string)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (stringtoeast(Array, i, j, row, column, string))
				printf("Epossible %d %d\n",i,j);
			if (stringtowest(Array, i, j, row, column, string))
				printf("Wpossible %d %d\n",i,j);
			if (stringtonorth(Array, i, j, row, column, string))
				printf("Npossible %d %d\n",i,j);
			if (stringtosouth(Array, i, j, row, column, string))
				printf("Spossible %d %d\n",i,j);
			if (stringtosoutheast(Array, i, j, row, column, string))
				printf("SEpossible %d %d\n",i,j);
			if (stringtosouthwest(Array, i, j, row, column, string))
				printf("SWpossible %d %d\n",i,j);
			if (stringtonortheast(Array, i, j, row, column, string))
				printf("NEpossible %d %d\n",i,j);
			if (stringtonorthwest(Array, i, j, row, column, string))
				printf("NWpossible %d %d\n",i,j);
		}
	}
}
int main()
{
	int row,column;
	scanf("%d%d",&row, &column);
	char **array = (char **)malloc(row*sizeof(char *));
	for (int i= 0; i < row; i++)
		array[i] = (char *)malloc(column*sizeof(char));
	char space=' ';
	scanf("%c", &space);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			scanf("%c", &array[i][j]);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			printf("%c", array[i][j]);
		printf("\n");
	}
	char s[100];
	scanf("%s", s);
	findstringinmatrix(array, row, column,s);
	return 0;
}