#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fIn, *fOut;
    int width, height;
    int i, j;
    int val;

    if(argc != 3){
        printf("Argomenti insufficienti in chiamata di programma\n");
        return -1;
    }

    fIn = fopen(argv[1], "r");
    fOut = fopen(argv[2], "w");

    if(fIn == NULL || fOut == NULL){
        printf("Errore nell'apertura del file\n");
        return -1;
    }

    fscanf(fIn, "%d %d", &width, &height);

    printf("Loading...\n");
    
    i = 0;
    while(i < height && !feof(fIn)){
        j = 0;
        while(j < width && !feof(fIn)){
            fscanf(fIn, "%d", &val);
            switch(val){
                case 0 ... 25: 
                    fprintf(fOut, "@ ");
                    break;
                case 26 ... 50: 
                    fprintf(fOut, "# ");
                    break;
                case 51 ... 75: 
                    fprintf(fOut, "%% ");
                    break;
                case 76 ... 100:
                    fprintf(fOut, "* ");
                    break;
                case 101 ... 125: 
                    fprintf(fOut, "+ ");
                    break;
                case 126 ... 150: 
                    fprintf(fOut, "= ");
                    break;
                case 151 ... 175: 
                    fprintf(fOut, "- ");
                    break;
                case 176 ... 200: 
                    fprintf(fOut, ": ");
                    break;
                case 201 ... 225: 
                    fprintf(fOut, ". ");
                    break;
                case 226 ... 255: 
                    fprintf(fOut, "  ");
                    break;
            }
            j++;
        }
        fprintf(fOut, "\n");
        i++;
    }

    fclose(fIn);
    fclose(fOut);

    printf("Image successfully created\n");

    return 0;
}

