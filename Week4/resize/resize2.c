 /**
  * Resizes a given BMP by given float 
 */

#include <stdio.h>
#include <stdlib.h>
//#include <cs50.h>
#include <math.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
// ensure proper usage (three command line arguments)
if (argc != 4)
{
    fprintf(stderr, "Usage: ./resize n infile outfile\n");
    return 1;
} 

// point to and label given filenames
char *infile = argv[2];
char *outfile = argv[3];

// PARSE FLOAT
float f = atof(argv[1]);
if (f > 100 || f < 0) {
    fprintf(stderr, "Usage: n > 0 and n < 100\n");
    return 1;
}

// open input file 
FILE *inptr = fopen(infile, "r");
if (inptr == NULL)
{
    fprintf(stderr, "Could not open %s.\n", infile);
    return 2;
}

// open output file
FILE *outptr = fopen(outfile, "w");
if (outptr == NULL)
{
    fclose(inptr);
    fprintf(stderr, "Could not create %s.\n", outfile);
    return 3;
}

// read infile's BITMAPFILEHEADER
BITMAPFILEHEADER bf;
fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

// read infile's BITMAPINFOHEADER
BITMAPINFOHEADER bi;
fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

// ensure infile is (likely) a 24-bit uncompressed BMP 4.0
if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
    bi.biBitCount != 24 || bi.biCompression != 0)
{
    fclose(outptr);
    fclose(inptr);
    fprintf(stderr, "Unsupported file format.\n");
    return 4;
}

// store original variables for later
int height = bi.biHeight; 
int width = bi.biWidth;


// determine padding for scanlines
int padding =  (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;
int width_times_f = fabsf(width * f);
int new_padding = (4 - ((width_times_f) * sizeof(RGBTRIPLE)) % 4) % 4;



// update horizontal and vertical resize
bi.biWidth = bi.biWidth * f;
bi.biHeight = bi.biHeight * f;

// update header size info
bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + new_padding) * abs(bi.biHeight); 
bf.bfSize = bi.biSizeImage + 54; // number of bytes needed for header

// write outfile's BITMAPFILEHEADER
fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

// write outfile's BITMAPINFOHEADER
fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

// iterate over infile's scanlines
for (int i = 0, biHeight = abs(height); i < biHeight; i++)
{

    int line_size = (sizeof(RGBTRIPLE) * width) + padding;

    // iterate vertically
    for (int x = 0; x < f; x++) {

        // iterate over pixels in scanline (horizontal)
        for (int j = 0; j < width; j++)
        {

            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile * f to scale
            for (int l = 0; l < f; l++) {
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }

            // skip pixels if downsizing
            if (f < 1) {
                 fseek(inptr, sizeof(RGBTRIPLE), SEEK_CUR);
            }

        }


        // add padding (if necessary)
        for (int k = 0; k < new_padding; k++) {
            fputc(0x00, outptr);
        }

         // skip over old padding (if any) 
        fseek(inptr, padding, SEEK_CUR);

        // if resizing up; jump back to repeat line. 
        if (x < f - 1) {
            fseek(inptr, -line_size, SEEK_CUR);
        }



    }
}


// close infile
fclose(inptr);

// close outfile
fclose(outptr);

// success
return 0;
}
