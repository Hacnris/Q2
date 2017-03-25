#include "engine.h"
#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void checktablesuite();
int main(int argc, char * argv[])
{
	
		checktablesuite();
		loadfile("fable.txt");
		return EXIT_SUCCESS;
	
	
}
void checktablesuite()
{
	if(size() == 0)
	{
		if(firstItem() == NULL)
		{
			printf("Test Passed! The Table is empty.\n");
		}
		else
			printf("Test Failed! The table is not empty\n");
		
	}
	if(size() == 1)
	{
		if(nextItem() == NULL)
		{
			printf("Test Passed! The Table is a single element table.\n");
		}
		else
			printf("Test Failed! The table is not a single element table\n");
		
	}
	
}