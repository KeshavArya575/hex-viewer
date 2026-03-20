#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s file\n", argv[0] );
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if (!f)
    {
        printf("Failed to open file\n");
        return 1;
    }
    fseek(f, 0, SEEK_END);
   long size = ftell(f);
   rewind(f);
   printf("File size: %ld bytes\n\n", size);
   
    unsigned char buffer[16];
    size_t bytes_read;
    unsigned int offset = 0;

    while((bytes_read = fread(buffer, 1, 16, f)) > 0){
        printf("%08X  ", offset);
//hex
        for(int i = 0; i < 16; i++) 
        {
          if(i < bytes_read)
          printf("%02X ", buffer[i]);
    else
          printf("   ");
    if (i == 7) printf(" ");
        }
    printf(" ");

//ascii
    for(int i = 0; i < 16; i++) 
    {
    if(i < bytes_read) {
        if(buffer[i] >= 32 && buffer[i] <= 126)
            printf("%c", buffer[i]);
        else
            printf(".");
    } else 
    {
        printf(" ");
    }
}
    printf("\n"); 
    offset += bytes_read;
}
fclose(f);
return 0;

}