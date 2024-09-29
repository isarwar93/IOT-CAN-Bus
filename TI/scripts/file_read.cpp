// #include <iostream>
// #include <fstream>
// #include <string>
#include <stdio.h>

int main() {
    // Open the file
    // Open the file in read mode
    FILE *fh = fopen("firmware_cpu1.txt", "rb");

    // Check if the file is open
    if (fh == NULL) {
        printf("Error: Could not open the file!\n");
        return 1;
    }
    // char c = 0;
    // for (int i = 0;i<50;i++)
    // {
    //     c = getc(fh);
    //     printf("%d -> %c \n",i,c);
    // }


    unsigned char sendData[8];
	unsigned int fileStatus;
	unsigned int rcvData = 0;
	unsigned int checksum = 0;
	char ack = 0x2D;
    unsigned char buf[8];
	int readf;

	char c_temp;
	// c_temp = getc(fh);
    printf("[0]:%x,",c_temp);
	c_temp = getc(fh);
    printf("[1]:%x,",c_temp);
	c_temp = getc(fh);
    printf("[2]:%x\n",c_temp);

	float bitRate = 0;
	//First 22 bytes are initialization data
	for (int i = 0; i < 22; i++)
	{
		fileStatus = fscanf(fh, "%x", &sendData[0]);
        //write(fd, &sendData[0], 1);
		printf("[0]:%x,",sendData[0]);
        //fileStatus++;
        bitRate += 8;
		checksum += sendData[0];
	}
    // // Buffer to hold the first 22 characters (+1 for the null terminator)
    // char buffer[23]; // 22 characters + 1 for the null terminator

    // // Read the first 22 characters from the file
    // size_t n = fread(buffer, 1, 22, file);

    // // Null-terminate the string
    // buffer[n] = '\0';

    // // Print the first 22 characters
    // printf("First 22 characters: %s\n", buffer);

    // Close the file
    fclose(fh);

    return 0;
}