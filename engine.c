#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "engine.h"
#include "table.h"
#include "levenshtein.h"

const int MAXINPUT = 150;
const int MAXLENGTH = 1000;
unsigned int smallest = 5;
char * smallWord = NULL;
const int PRINTNUM = 10;
const int MAXDISTANCE = 5;



void loadfile(char * filename)
{
	static int count = 0;
	static char word[MAXINPUT];
	static char input[MAXLENGTH];
	char * token;
	char ch;
	FILE *fp = fopen(filename,"r");
	printf("What word should I check? ");
	fgets(word,MAXINPUT, stdin);
	while(fgets(input,MAXLENGTH,fp))
	{
		for(int i = 0; i<strlen(input);i++)
		{
			input[i] = tolower(input[i]);
		}
		token = strtok(input," ,.?-!\n\t\"");
		assert(token!=NULL);
		while(token!=NULL)
		{
			unsigned int distance = levenshtein(word,token);
			assert(distance>=0);
			if(distance<MAXDISTANCE)
			{
				if(distance<smallest)
				{
					smallest = distance;
					smallWord = token;
				}
				if(!search(token))
					insert(token);
			}
			token=strtok(NULL," ,.?-!\n\t\"");
		}
	}
	printf("Did you mean ... %s\n?", smallWord);
	printf("There are %d other similar words, would you like to see them?(y/n)", size());
  ch = getchar();
	if(ch == 'Y' || ch == 'y')
	{
		char * word = firstItem();
		for(int i = 0; i<PRINTNUM && count< size();i++)
			{
				count++;
				
				printf("%s\n", word);
				word = nextItem();
			}
			ch = getchar();
		while(count<size() && (ch!='q' || ch != 'Q'))
		{
			
			for(int i = 0; i<PRINTNUM && count< size() && ch == '\n';i++)
			{
				count++;
				
				printf("%s\n", word);
				word = nextItem();
			}
			ch = getchar();
		}
	
	}
	
	fclose(fp);
}


