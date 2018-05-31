#define PNG_DEBUG 3
#include <png.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
 
struct Png {
    int width, height;
    png_byte color_type;
    png_byte bit_depth;
   
    png_structp png_ptr;
    png_infop info_ptr;
    int number_of_passes;
    png_bytep *row_pointers;
};
 
void PngRead(char *file, struct Png *image) {
    int x, y;
    char header[8];
 
    FILE *fp = fopen(file, "rb");
    fread(header, 1, 8, fp);
 
    image->png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    image->info_ptr = png_create_info_struct(image->png_ptr);
    png_init_io(image->png_ptr, fp);
    png_set_sig_bytes(image->png_ptr, 8);
    png_read_info(image->png_ptr, image->info_ptr);
 
    image->width = png_get_image_width(image->png_ptr, image->info_ptr);
    image->height = png_get_image_height(image->png_ptr, image->info_ptr);
    image->color_type = png_get_color_type(image->png_ptr, image->info_ptr);
    image->bit_depth = png_get_bit_depth(image->png_ptr, image->info_ptr);
    image->number_of_passes = png_set_interlace_handling(image->png_ptr);
    png_read_update_info(image->png_ptr, image->info_ptr);
 
    image->row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * image->height);
    for (y = 0; y < image->height; y++) {
        image->row_pointers[y] = (png_byte *)malloc(png_get_rowbytes(image->png_ptr, image->info_ptr));
    }
    png_read_image(image->png_ptr, image->row_pointers);
 
    fclose(fp);
}
 
void PngWrite(char *file, struct Png *image) {
    int x, y;
 
    FILE *fp = fopen(file, "wb");
    image->png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    image->info_ptr = png_create_info_struct(image->png_ptr);
    png_init_io(image->png_ptr, fp);
    png_set_IHDR(image->png_ptr, image->info_ptr, image->width, image->height, image->bit_depth, image->color_type, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
    png_write_info(image->png_ptr, image->info_ptr);
    png_write_image(image->png_ptr, image->row_pointers);
    png_write_end(image->png_ptr, NULL);
 
    for (y = 0; y < image->height; y++) {
        free(image->row_pointers[y]);
    }
    free(image->row_pointers);
 
    fclose(fp);
}
 
void PngDraw(int x0, int y0, int x1, int y1, struct Png *image) {
        for (int i = y0; i <= y1; i++) {
            png_byte *row = image->row_pointers[i];
            for (int j = x0; j <= x1; j++) {
                png_byte *ptr = &(row[j * 6]);
                ptr[0] = 255 - ptr[0];
                ptr[2] = 255 - ptr[2];
                ptr[4] = 255 - ptr[4];
            }
        }
}
 
int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Usage: %s <input_file> <x0> <y0> <x1> <y1>", argv[0]);
    }
    int x0, x1, y0, y1;
    if (sscanf(argv[2], "%d", &x0) != 1) {
        printf("Failed with x0\n");
        return 0;
    }
    if (sscanf(argv[3], "%d", &y0) != 1) {
        printf("Failed with y0\n");
        return 0;
    }
    if (sscanf(argv[4], "%d", &x1) != 1) {
        printf("Failed with x1\n");
        return 0;
    }
    if (sscanf(argv[5], "%d", &y1) != 1) {
        printf("Failed with y1\n");
        return 0;
    }
 
    struct Png image;
    PngRead(argv[1], &image);
    if (x0 < 0 || x0 >= image.width) {
        printf("Fail with x0\n");
        return 0;
    }
    if (x1 < 0 || x1 >= image.width) {
        printf("Fail with x1\n");
        return 0;
    }
    if (y0 < 0 || y0 >= image.height) {
        printf("Fail with y0\n");
        return 0;
    }
    if (y1 < 0 || y1 >= image.height) {
        printf("Fail with y1\n");
        return 0;
    }
    if (x0 > x1) {
        printf("Fail with x0 x1\n");
        return 0;
    }
    if (y0 > y1) {
        printf("Fail with y0 y1\n");
        return 0;
    }
 
    PngDraw(x0, y0, x1, y1, &image);
    PngWrite("result.png", &image);
 
    return 0;
}
