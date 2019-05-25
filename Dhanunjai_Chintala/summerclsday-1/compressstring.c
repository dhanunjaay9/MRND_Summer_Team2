#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* customatoi(int count)
{
	char *s = (char *)malloc(10 * sizeof(char));
	int n = 0;
	while (count > 0)
	{
		int rem = count % 10;
		count = count / 10;
		s[n++] = rem + '0';
	}
	s[n] = '\0';
	for (int front = 0, rear = n - 1; front < rear; front++, rear--)
	{
		char temp = s[front];
		s[front] = s[rear];
		s[rear] = temp;
	}
	return s;
}
void compressstring(char *s)
{
	char *a = (char *)malloc(strlen(s)*sizeof(char));
	int index = 0,i=0,j=0;
	for (; i < strlen(s) && s[i] != '\0';)
	{
		j = i;
		int count = 0;
		while (s[j] == s[i])
		{
			count++;
			j++;
		}
		if (count > 1)
		{
			s[index++] = s[i];
			if (count < 10)
				s[index++] = count + '0';
			else
			{
				char *res = customatoi(count);
				for (int j = 0; res[j] != '\0'; j++)
					s[index++] = res[j];
			}
		}
		else
		{
			s[index++] = s[i];
		}
		i = j;
	}
	s[index]='\0';
	printf("%s",s);
}
void main()
{
	char s[100];
	printf("Enter the string");
	scanf("%s", s);
    compressstring(s);
}
