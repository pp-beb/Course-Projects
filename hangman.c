#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
const char* entry(int level)
{
	switch (level) {
		case 1: 
		return "hello";
		break;
		
		case 2: 
		return "whatsup";
		break;
		
		case 3:
			return "beautiful";
			break;
			
		case 4:
			return "symmetrical";
			break;
			
		case 5:
			return " revolutionary";
			break;
			
		default:
			return "wrong input.";
		}
		
}
void Guess(char a[],int n)
{
	int i;
		printf("Enter your guess: \n");
	for(i=0;i<n;i++)
	{
	printf(" __ ");
	}
	printf("\n");
	scanf(" %c",&a[n]);
	n++;
}
	void check(char a[], int n, const char* str)
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(str[i]==a[j])
				{
					printf("correct\n");
				}
				
			}
		}
		
		
	}
int main()
{
	int n;
	printf("Enter the level (1-5): \t");
	scanf("%d" ,&n);
	const char* Entry=entry(n);
	char word[20];
	strcpy(word,Entry);
	int size= strlen(word);
	char guess[size];
	Guess(guess,size);
	check(guess,size,word);
}
