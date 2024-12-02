#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For sqrt()

// Function to calculate image brightness
int imgBrightness(int row, int column, int img[row][column]) {
    int totalValue = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            totalValue += img[i][j];
        }
    }
    // Calculate brightness as the average pixel value
    int brightness = totalValue / (row * column);
    return brightness;
}

// Function to calculate image contrast
double imgContrast(int row, int column, int img[row][column], int mean) {
    double totalValue = 0.0;

    // Calculate the squared difference from the mean
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            totalValue += (img[i][j] - mean) * (img[i][j] - mean);
        }
    }

    // Calculate contrast (standard deviation)
    double contrast = sqrt(totalValue / (row * column));
    return contrast;
}

int main() {
    int rows, cols;

    // รับจำนวนแถวและคอลัมน์จากผู้ใช้
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    int image[rows][cols];
    // รับค่าพิกเซลของภาพจากผู้ใช้
    printf("Enter pixel values (row by row):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &image[i][j]);
        }
    }


    // Calculate and print the brightness
    int brightness = imgBrightness(rows, cols, image);
    printf("Image Brightness: %d\n", brightness);

    // Calculate and print the contrast
    double contrast = imgContrast(rows, cols, image, brightness);
    printf("Image Contrast: %.2f\n", contrast);

    return 0;
}
