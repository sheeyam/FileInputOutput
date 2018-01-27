#include <stdio.h>

void openFile();
void openExistingFile();
void readFromFile();
void writeToFile();
void deleteFile();

int main()
{
	int choice;
	FILE *fp = NULL;
	printf("1 - Create a New File \n"); 
	printf("2 - Open an Existing File \n"); 
	printf("3 - Read from a File \n"); 
	printf("4 - Write to a File \n");
	printf("5 - Delete a File \n");

	printf("\nEnter the Program Number to Run:"); 
	scanf("%d",&choice);
	switch(choice) 
	{ 
		case 1: 
		openFile();
		break;

		case 2: 
		openExistingFile();
		break;

		case 3: 
		readFromFile();
		break;

		case 4: 
		writeToFile();
		break;

		case 5: 
		deleteFile();
		break;

		default:
		break;
	}
	return 0;  
}

//Open File Program
void openFile() {
	FILE *fopn;
	printf("*** Create a New File Program ***\n"); 
	char openFileName[100];
	printf("Enter the filename to create: \n");
	scanf("%s", openFileName);
	fopn = fopen(openFileName ,"a");
}

//Open Existing File Program
void openExistingFile() {
	printf("*** Let's open an Existing File ***\n");
	FILE *fopne;
	char openExistingFileName[100];
	
	printf("Enter the filename to open: \n");
	scanf("%s", openExistingFileName);
	
    // Open file
	fopne = fopen(openExistingFileName, "r");
	if (fopne == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	} else {
		printf("File opened Successfully\n");
		exit(0);
	}
}

//Read From File Program
void readFromFile(){
	printf("*** Read from an Existing File Program ***\n");
	FILE *fread;
	char readFileName[100], c;

	printf("Enter the filename to read: \n");
	scanf("%s", readFileName);
	
    // Open file
	fread = fopen(readFileName, "r");
	if (fread == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}
	
    // Read contents from file
	c = fgetc(fread);
	while (c != EOF)
	{
		printf ("%c", c);
		c = fgetc(fread);
	}
	fclose(fread);
}

//Write to File Program
void writeToFile(){
	printf("*** Write to a File Program ***\n");
	char writeFileName[30];
	char writeText[400];

	printf("Enter a Filename to write:  ");
	scanf("%s",&writeFileName);
	FILE *fwrite = fopen(writeFileName, "w");

	if (fwrite == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	printf("Enter File Content:  ");
	scanf("%s",&writeText);

	/* print some text */
	fprintf(fwrite, "%s\n", writeText);
	fclose(fwrite);
}

//Delete File Program
void deleteFile(){
	printf("*** Delete File Program ***\n");
	char fileName[50];
	printf("Enter a Filename:");
	scanf("%s",&fileName);  
	if (remove(fileName) == 0)
		printf("File Deleted Successfully\n");
	else
		printf("File Not Deleted\n");
}