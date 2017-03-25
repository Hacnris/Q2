#include "engine.h"
#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

Boolean checkSuite(char * arg);
void checktablesuite();

int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		printf("2 args the executable and a dictionary.txt file\n");
		return 1;
	}
	else
	{
		checkSuite(argv[1]);
		loadfile(argv[1]);
		printf("END OF PROCESSING\n");
		return EXIT_SUCCESS;
	}
	
	
}

Boolean checkSuite(char * arg)
{
	Boolean result = true;
	printf("Testing if dictionary is empty input\n");
	if(strcmp(arg,"")!=0)
	{
		printf("Test Passed: dictionary file is not empty\n");
	}
	else
	{
		printf("Test Failed! dictionary arg is empty\n");
		result = false;
	}
	if(strcmp(arg+(int)strlen(arg)-4,".txt")==0)
	{
		printf("Test Passed: arg is a .txt file\n");
	}
	else
	{
		printf("Test Failed! arg is not a .txt file\n");
		result = false;
	}
	if(arg!=NULL)
		printf("Test Passed! arg is not NULL\n");
	else
	{
		printf("Test Failed! arg is NULL\n");
		result = false;
	}
	return result;
}

void checktablesuite()
{
	if(firstItem()!=NULL)
		printf("Test Passed! table is not empty\n");
	else
		printf("Test Failed! table is empty\n");
	if(size()==1)
	{
		if(nextItem() == NULL)
		{
			printf("Test Passed! table is a one element table\n");
		}
		else
			printf("Test Failed! table is not a one element table\n");
	}
}