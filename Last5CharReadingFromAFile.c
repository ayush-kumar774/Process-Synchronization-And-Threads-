//Compile :- gcc Last5CharReadingFromAFile.c -o Last5CharReadingFromAFile
// Run :- ./Last5CharReadingFromAFile

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int file_descriptor, number_of_char , pointerHead ;
	char arrayOfChar[100];
	file_descriptor = open("SEEK_END.txt", O_CREAT|O_RDWR, 0777);
	number_of_char = read(0, arrayOfChar, 100);
	write(file_descriptor, arrayOfChar, number_of_char);
 	pointerHead = lseek(file_descriptor, -6, SEEK_END);
  	read(file_descriptor, arrayOfChar, 5);
  	write(1, arrayOfChar, 5);
  	printf("\n");
}
