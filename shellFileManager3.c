/*
Steven Gallegos
Project: File Manager
CST 315
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct asdf
{
	char * ptr;
	int index;
	long ptr2;
};

int ptrInt;
char ptrString[1000];

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

//void action(char * temp)
//void action (void* arg)
void action (/*char temp[]*//*void *context*/)
{
	
    //struct asdf *a = context;
	//char * temp = a->ptr;
	
	//printf("String: %ld Function\n",temp);
	//printf("String: %ld Global Var\n",ptrString);
	//char * temp = ptrString;
	char temp[1000];
	stpcpy(temp, ptrString);
	
	
	/*
	printf("ptr String: %s\n", ptrStr);
	printf("String: %ld\n",temp->ptr);
	printf("String: %s\n",temp->ptr);
	printf("Index: %d\n",temp->index);
	
	char * temp = ptrString;*/
	
	int k = 0;
	while( temp[k] != ' ')//find position in command
	{
		k++;
	}
	//printf("temp: (%c)(%c)(%c)(%c)(%c)\n", temp[0], temp[1], temp[2], temp[3], temp[4]);
	//printf("temp: (%c)(%c)(%c)(%c)(%c)\n", temp[k], temp[k+1], temp[k+2], temp[k+3], temp[k+4]);
	
	//printf("Command Running: %ld LD\n", temp);
	//printf("Command Running: %s\n", temp);
	//printf("Command Running: %s\n", temp);
	
	if(temp[0] == 'e' && temp[1] == 'x' && temp[2]=='i' && temp[3]=='t')
	{
		printf("\tExiting...\n");
		exit(0);
	}
			
	//if change directory, cd command
	if(temp[ptrInt] == 'c' && temp[k+1] == 'd' && temp[k+2]==' ')
	{
		chdir(temp);
	}
	else{
		//if(temp[i] == 'e' && temp[k+1] == 'x' && temp[k+2]=='i' && temp[k+2]=='t' && temp[k+2]==' ')
		//{
		//	exit(0);
		//}else{
		//do this command
		//if(temp[ptrInt] == 'i' && temp[k+1] == 'n' && temp[k+2] == 't' && temp[k+3] == 'l')//intl
		if(temp[0] == 't' && temp[1] == 'r' && temp[2] == 'e' && temp[3] == 'e')//tree
		{
			char temp2 [1000];
			trimwhitespace(temp);
			//printf("\n%s\n",temp);
			strncpy(temp2, temp + 4, sizeof(temp) / sizeof(temp[0])  - 4);
			
			char temp3 [] = "find ";
			
			strcat(temp3, temp2);  
			strcat(temp3," | sed 's|[^//]*//|- |g'");
			
			//printf("\nNew Command: %s\n",temp3);
			
			if(strcmp(temp2, "") != 0)
			{
				system(temp3);
			}
			else
			{
				//system("ls -R | grep \":$\" | sed -e 's/:$//' -e 's/[^-][^\\/]*\\//--/g' -e 's/^/   /' -e 's/-/|/'");
				system("find | sed 's|[^//]*//|- |g'");
			}
		}
		else{
			if(temp[0] == 'i' && temp[1] == 'n' && temp[2] == 't' && temp[3] == 'l')//intl	
			{
				/*
				char temp2 [1000];
				trimwhitespace(temp);
				printf("\n%s\n",temp);
				strncpy(temp2, temp + 4, sizeof(temp) / sizeof(temp[0])  - 4);
				
				char temp3 [] = "locate -eb0P ";
				
				strcat(temp3, temp2);  
				strcat(temp3," | xargs -r0 ls -ald");
				
				printf("\nNew Command: %s\n",temp3);
				
				system(temp3);*/
				
				if(temp[4] == '+')
				{			
					char temp2 [1000];
					trimwhitespace(temp);
					//printf("\n%s\n",temp);
					strncpy(temp2, temp + 4, sizeof(temp) / sizeof(temp[0])  - 4); 
				
					char tempo3 [] = "./shell5.sh ";
					char tempo4 [] = "file ";
					
					strcat(tempo3, temp);  
					strcat(tempo4, temp);  
					
					//printf("\nNew Command: %s\n",tempo3);
					system(tempo3);
					system(tempo4);
				}
				else{
					trimwhitespace(temp);
				
					char tempo3 [] = "./shell5.sh "; 
					
					strcat(tempo3, temp);  
					
					//printf("\nNew Command: %s\n",tempo3);
					system(tempo3);
				}
				
			}
			else
			{
				
				if(temp[0] == 'd' && temp[1] == 'r' && temp[2] == 'n' && temp[3] == 'o')
				{
					if(temp[4] == '+')
					{
						trimwhitespace(temp);
						char temp2 [1000];
						strncpy(temp2, temp + 5, sizeof(temp) / sizeof(temp[0])  - 5);
						char temp3 [] = "du -sh ";
						strcat(temp3, temp2);  	

						//char temp4 [] = "| find ";			
						char temp4 [] = " | ls -ld ";			
						strcat(temp4, temp2);  
						//strcat(temp4," | sed 's|[^//]*//|- |g'");
						
						strcat(temp3, temp4);						
						//printf("\n%s\n", temp3);
						
						system(temp3);
						//system(temp4);
					}
					else{
						trimwhitespace(temp);
						char temp2 [1000];
						strncpy(temp2, temp + 5, sizeof(temp) / sizeof(temp[0])  - 5);
						char temp3 [] = "du -sh ";
			
						strcat(temp3, temp2);  	
						
						system(temp3);
					}
				}
				else{
					system(temp);
				}
			}
		}
	}
}

int indexPoint(char *arr, int size)
{
	pthread_t tids[size];
	int pcounter = 0;
		
	//start of substring set to 0
	int front = 0;
	//Goes through entire character array
    for (int i=0; i < size; i++) 
	{
		//printf("Check: %c\n", arr[i]);
        if (arr[i] == ';')
		{
			//create substring with length of current position - front
			char temp[i-front];
			int len = (sizeof(temp) / sizeof(temp[0]));
			//printf("%d\n", len);
			
			//copy substring
			strncpy ( temp, arr+front, i);
			//add end character at end of array
			temp[len] = '\0';
			
			printf("\nSubString: %s\n",temp);
			
			//action(temp, i);
			//*************************
			
			//long tempPtr = &temp;
			//printf("pointer value: %ld\n",tempPtr);
			//printf("pointed string %s\n",tempPtr);
			//struct asdf xs;
			//printf("String: %ld\n",xs.ptr);
			//printf("String: %s Original\n",&temp);
			//printf("String: %ld Original\n",&temp);
			/*xs.ptr = &temp;
			xs.index = i;
			xs.ptr2 = &temp;*/
			//ptrStr = &temp;
			ptrInt = i;
			//ptrString = temp;
			strcpy(ptrString, temp);
			
			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_create(&tids[pcounter], &attr, action, NULL);
			pcounter++;

			// Wait until thread is done its work
			
			
			//***********************
			
			//increment list
			front = i+1;
		}
    }
	
	for (int i = 0; i < pcounter; i++) {
			pthread_join(tids[i], NULL);
		}
}

int main()
//int main(int argc, char *argv[])
{
	//command must have semicolon at end, else removed
	char comm[1000];
	char check = ';';
	//substring front and back
	int front = 0;
	int back = 0;
	//x == number of ";"
	int x = 0;
	
	while(1){
		//user input
		fgets(comm, 1000, stdin);
		printf("Executing Command(s): %s\n\n", comm);
		//**********************************************************
		//size of array
		int len = (sizeof(comm) / sizeof(comm[0]));

		//printf("%d\n", len);
		
		indexPoint(comm, len);
	}

	return 0;
}

