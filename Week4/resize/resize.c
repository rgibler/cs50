//This program resizes input .bmp files and sends result to a specified output

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main (int argc, char *argv[])
{
	//prints error explaining usage if there are improper number of arguments
	if (argc != 4)
	{
		fprintf(stderr, "Usage: ./resize n infile outfile\n");
		return 1;
	}

	//assigns argumrnts to variables
	int n = atoi(argv[1]);
	char *infile = argv[2];
	char *outfile = argv[3];

	//if n exceeds bounds sends error
	if (n < 1 || n > 100)
	{
		fprintf(stderr, "n needs to be between 1 and 100");
		return -1;
	}
	//opens input for reading
	FILE *inptr = fopen(infile, "r");
	if (inptr == NULL)
	{
		fprintf(stderr, "Unable to open %s.\n", infile);
		return 2;
	}
	//opens output for writing
	FILE *outptr = fopen( outfile, "w");
	if (outptr == NULL)
	{
		fprintf(stderr, "Unable to open %s.\n", outfile);
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

	//creating variables for output header
	BITMAPFILEHEADER out_bf;
	BITMAPINFOHEADER out_bi;
	out_bf = bf;
	out_bi = bi;
	out_bi.biWidth = bi.biWidth * n;
	out_bi.biHeight = bi.biHeight * n;
	int in_padding;
	int out_padding;

    // determine padding for scanlines
    in_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    out_padding = (4-(out_bi.biWidth *sizeof(RGBTRIPLE)) % 4) % 4;

    //these equations for image size were taken from CoreData github page
    // I dont understand them
    out_bf.bfSize = 54 + out_bi.biWidth * abs(out_bi.biHeight) * 3 + abs(out_bi.biHeight) *  out_padding;
    out_bi.biSizeImage = ((((out_bi.biWidth * out_bi.biBitCount) + 31) & ~31) / 8) * abs(out_bi.biHeight);


	// write outfile's BITMAPINFOHEADER
	fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);
	fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
	//repeats process to elongate height of image
	for (int H = 0; H < n-1; H++)
	{
        // iterate over pixels in scanline
 	       for (int j = 0; j < bi.biWidth; j++)
        	{
            		// temporary storage
            		RGBTRIPLE triple;

            		// read RGB triple from infile
            		fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            		// write RGB triple to outfile
	   		for (int k = 0; k<n; k++) 
	   		{ 
	         		 fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
	   		}
		}
          	
		        // skip over padding
        	        fseek(inptr, in_padding, SEEK_CUR);

         	        // then add it back (to demonstrate how)
        		for (int k = 0; k < out_padding; k++)
        		{
	           		fputc(0x00, outptr);
       			}
			
	//skips padding for each true height change
	fseek(inptr, -(bi.biWidth*3+ in_padding), SEEK_CUR);
	}
    
    fseek(inptr, bi.biWidth * 3 + in_padding, SEEK_CUR);
    }	
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
 

