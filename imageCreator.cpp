#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    int width, height;
    int i, j;
    int val;

    if(argc != 3){
        cout << "Argomenti insufficienti in chiamata di programma" << endl;
        return -1;
    }

    ifstream fIn(argv[1]);
    ofstream fOut(argv[2]);

    if(!fIn|| !fOut){
        cout << "Errore nell'apertura del file" << endl;
        return -1;
    }

    cout << "Loading..." << endl;

    fIn >> width >> height;

    i = 0;
    while(i < height){
        j = 0;
        while(j < width){
            fIn >> val;
            switch(val){
                case 0 ... 25: 
                    fOut << "@ ";
                    break;
                case 26 ... 50: 
                    fOut << "# ";
                    break;
                case 51 ... 75: 
                    fOut << "%% ";
                    break;
                case 76 ... 100:
                    fOut << "* ";
                    break;
                case 101 ... 125: 
                    fOut << "+ ";
                    break;
                case 126 ... 150: 
                    fOut << "= ";
                    break;
                case 151 ... 175: 
                    fOut << "- ";
                    break;
                case 176 ... 200: 
                    fOut << ": ";
                    break;
                case 201 ... 225: 
                    fOut << ". ";
                    break;
                case 226 ... 255: 
                    fOut << "  ";
                    break;
            }
            j++;
        }
        fOut << endl;
        i++;
    }

    cout << "Image successfully created" << endl;
    return 0;
}

