#include <stdio.h> 
  
int main() 
{ 
    int i, j, temp = 0; 
    int width = 10, height = 12; 
  
    // Suppose the 2D Array to be converted to Image is as given below 
    
int image[12][10] = {
      {0, 0, 0, 0, 0 ,0 ,0, 0, 0, 0},
      {0, 255, 255, 255 ,255 ,255, 255, 255, 255, 0},
      {0, 255, 255, 255, 255, 0, 0, 0, 255, 0},
{0 ,255, 255, 255, 255, 0, 0, 0, 255, 0},
{0 ,255, 0, 0 ,255, 0, 0, 0, 255, 0},
{0, 255, 0 ,0 ,255 ,0 ,0 ,0, 255, 0},
{0 ,0 ,0, 0, 0, 0 ,0 ,0 ,0 ,0},
{0, 255 ,255, 255, 255, 255 ,255, 255, 255, 0},
{0 ,255 ,255, 255 ,0 ,0 ,0 ,255 ,255, 0},
{0, 255, 255, 255, 0 ,0 ,0 ,255 ,255, 0},
{0, 255, 255 ,255, 0, 0 ,0 ,255, 255, 0},
{0 ,0 ,0 ,0 ,0, 0, 0, 0 ,0, 0}
    };
    FILE* pgmimg; 
    pgmimg = fopen("pgmimg.pgm", "wb"); 
  
    // Writing Magic Number to the File 
    fprintf(pgmimg, "P2\n");  
  
    // Writing Width and Height 
    fprintf(pgmimg, "%d %d\n", width, height);  
  
    // Writing the maximum gray value 
    fprintf(pgmimg, "255\n");  
    int count = 0; 
    for (i = 0; i < height; i++) { 
        for (j = 0; j < width; j++) { 
            temp = image[i][j]; 
  
            // Writing the gray values in the 2D array to the file 
            fprintf(pgmimg, "%d ", temp); 
        } 
        fprintf(pgmimg, "\n"); 
    } 
    fclose(pgmimg); 
} 
