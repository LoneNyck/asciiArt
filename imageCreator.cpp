#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    FILE *fIn, *fOut;
    int width, height;
    int i, j;
    int val;

    if(argc != 3){
        cout << "Missing arguments" << endl;
        return -1;
    }

    fIn = fopen(argv[1], "r");
    fOut = fopen(argv[2], "w");

    if(fIn == NULL || fOut == NULL){
        cout << "Error while opening the files" << endl;
        return -1;
    }

    fscanf(fIn, "%d, %d", &width, &height);

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

    return 0;
}

