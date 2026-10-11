,?..kkl#include <stdio.h>


int main()
{
int pageSize, logicalMemory, physicalMemory; int numPages, numFrames;
int pageTable[100]; int logicalAddress;
int pageNumber, offset;
int frameNumber, physicalAddress; int i;

printf("Enter Logical Memory Size: "); scanf("%d", &logicalMemory);

printf("Enter Physical Memory Size: "); scanf("%d", &physicalMemory);

printf("Enter Page Size: "); scanf("%d", &pageSize);
 

numPages = logicalMemory / pageSize; numFrames = physicalMemory / pageSize;

printf("\nNumber of Pages = %d", numPages); printf("\nNumber of Frames = %d\n", numFrames);

printf("\nEnter Frame Number for each Page:\n");


for (i = 0; i < numPages; i++)
{
printf("Page %d -> Frame: ", i); scanf("%d", &pageTable[i]);
}

for (i = 0; i < numPages; i++)
{
printf("%d\t%d\n", i, pageTable[i]);
}


printf("\nEnter Logical Address: "); scanf("%d", &logicalAddress);



pageNumber = logicalAddress / pageSize;
 
offset = logicalAddress % pageSize;


if (pageNumber >= numPages)
{


printf("\nInvalid Logical Address!\n"); return 0;
}
frameNumber = pageTable[pageNumber]; physicalAddress = (frameNumber * pageSize) + offset; printf("\n--- Address Translation ---\n"); printf("Logical Address = %d\n", logicalAddress); printf("Page Number	= %d\n", pageNumber); printf("Offset	= %d\n", offset);
printf("Frame Number	= %d\n", frameNumber); printf("Physical Address = %d\n", physicalAddress); return 0;
}
