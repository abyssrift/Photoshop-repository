#include <iostream>
#include <string>
#include "Image_Class.h" // Assuming this is your own image processing library

using namespace std;

int main() {
    // Initialize total rotation angle
    int totalRotation = 0;

    while (true) {
        // Prompt user for the name of the input image
        cout << "Please enter the name of the input image: ";
        string inputImageName;
        cin >> inputImageName;

        // Load the input image
        Image inputImage(inputImageName);

        // Perform rotation based on the total rotation angle
        Image rotatedImage(inputImage.height, inputImage.width);
        for (int i = 0; i < inputImage.width; ++i) {
            for (int j = 0; j < inputImage.height; ++j) {
                for (int k = 0; k < inputImage.channels; ++k) {
                    // Rotate the pixel by 90 degrees clockwise
                    rotatedImage(inputImage.height - 1 - j, i, k) = inputImage(i, j, k);
                }
            }
        }

        // Save the rotated image
        string outputImageName = "rotated_image_" + to_string(totalRotation) + ".png";
        rotatedImage.saveImage(outputImageName);

        // Update the total rotation angle
        totalRotation = (totalRotation + 90) % 360;

        // Prompt user if they want to continue rotating
        char choice;
        cout << "Do you want to rotate the image again? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}