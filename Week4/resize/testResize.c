    #include <stdio.h>
     #include <stdlib.h>

     #include "bmp.h"



    int main(int argc, char* argv[])
    {
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);

    if(0>n || n>100){

        printf("Please enter a value in range\n");
        return 1;
    }


    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
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



    //Create BMP variables for output image
       BITMAPFILEHEADER bf_output = bf;
       BITMAPINFOHEADER bi_output = bi;

       //Keep track of out BMP variables seperently as suggested by Zamyla
       bi_output.biWidth = bi.biWidth * n;
       bi_output.biHeight = bi.biHeight * n;

       //Keep padding of both infile and outfile seperatly
       int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
       int out_padding = (4 - (bi_output.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


       bi_output.biSizeImage = ((bi_output.biWidth * sizeof(RGBTRIPLE)) + out_padding) * abs(bi_output.biHeight);

       bf_output.bfSize = 54 + bi_output.biSizeImage;

       fwrite(&bf_output,sizeof(BITMAPFILEHEADER),1,outptr);

       fwrite(&bi_output,sizeof(BITMAPINFOHEADER),1,outptr);

     // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for(int v=0; v<n;v++){

        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for(int c=0; c<n; c++){
            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

            }
        }

        // then add it back (to demonstrate how)
        for (int k = 0; k < out_padding; k++)
        {
            fputc(0x00, outptr);
        }
            fseek(inptr,-bi.biWidth,SEEK_CUR);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
