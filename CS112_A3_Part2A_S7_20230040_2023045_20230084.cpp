/* Photoshop project for University of cairo computer science faculty
the menu loops forever while constantly uploading filters chosen by user onto specified image.
image should automatically open when user saves, however, if run by c++ file, code will stop after opening the image, if run by normal visual studio code
file, it will countinue untill user presses exit.


Authors:
Adam Samir Farouk 20230040 Filter 1, Filter 2, Filter 7, Filter 4, Filter 22, Filter 16,
Nour Alaa Hassan 20230445   Filter 10, Filter 11, Filter 20, Filter 12, Filter 21, Filter 19
Aya magdi Ali Ahmed 20230084 Filter 5, Filter 8, Filter 9, Filter 15, Filter 17, Filter 18

Menu was done by all of us combined.

Filter 21 and 22 represent the two bonus filters from our imagination.


*/

#include <iostream>
#include "Image_Class.h"
using namespace std;


void extensionadder(Image processed_image)
{
cout << "please insert a name to save your image as (WITHOUT AN EXTENSION)" << endl;
    string newname;
    cin >> newname;
    l:
    cout <<"please select an extension to save the image as"<< endl;
    cout <<"1-JPG" << endl;
    cout <<"2-BMP" << endl;
    cout <<"3-tga"<<endl;
    cout <<"4-PNG"<<endl;
    cout <<"your response: "<<endl;
    string x;
    cin >>x;
    if (x == "1")
    {
        newname = newname + ".jpg";
    }
    else if (x=="2"){
        newname = newname + ".bmp";
    }
    else if (x=="3"){
        newname = newname + ".tga";
    }
    else if(x=="4"){
        newname = newname +".png";
    }
    else{
        cout <<"invalid extension type, please choose again";
        goto l;
    }

    processed_image.saveImage(newname);
    cout << "Image successfully saved" << endl;
    string command = "start " + newname;
    system(command.c_str());
}
//grayscale filter
Image filter1( Image processed_image)
{
    unsigned int avg = 0;
    for (int i = 0; i < processed_image.width; ++i)
    {
        for (int j = 0; j < processed_image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
            avg = processed_image(i,j,k) + avg;
            avg /=3;
            }
            
            processed_image(i,j,0)=avg;
            processed_image(i,j,1)=avg;
            processed_image(i,j,2)=avg;
  
            
        }
        
    }
    cout <<"image successfuly processed" <<endl;
    cout <<"----------------------------"<<endl;
    return(processed_image);
}

//black and white filter
Image filter2(Image processed_image){
    unsigned int avg = 0;
    for (int i = 0; i < processed_image.width; ++i)
    {
        for (int j = 0; j < processed_image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
              avg = processed_image(i,j,k) + avg;
              avg/=3;
            }
            if (avg > 60)
            {
                for (int k = 0; k < 3; ++k)
                {
                    processed_image(i,j,k) = 255;
                }
            }
            else if (avg < 60)
            {
                for (int k = 0; k < 3; ++k)
                {
                    processed_image(i,j,k) = 0;
                }
            }
        } 
    }
    cout <<"image successfuly processed" <<endl;
    cout <<"----------------------------"<<endl;
    return(processed_image);
}

//inverted colors filter
Image filter3(Image processed_image){
     for(int i=0; i<processed_image.width; i++){

        for(int j=0; j<processed_image.height; j++){
            unsigned int avg[3];
            
            avg[0] = 255 - processed_image(i, j, 0);
            avg[1] = 255 - processed_image(i, j, 1);
            avg[2] = 255 - processed_image(i, j, 2);

            for(int k=0; k<3; k++){
                processed_image(i, j, k ) = avg[k];

            }
            
        }
    }
    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(processed_image);

}

//merge two images
Image filter4 (Image processed_image,Image processed_image2)
{
    int min_width = min(processed_image.width,processed_image2.width);
    int min_height = min(processed_image.height,processed_image2.height);
    Image mergeimage(min_width,min_height);
    int avg = 0;
    for (int i = 0; i < mergeimage.width-1; ++i)
    {
        for (int j = 0; j < mergeimage.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                avg = processed_image(i,j,k) + processed_image2(i,j,k);
                mergeimage(i,j,k) = avg/2;
            }

        }
    }
    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(mergeimage);
}

Image filter5(Image processed_image){
    Image originalImage;
    originalImage = processed_image;
    int x = originalImage.width ;


    // Create a new image to store the flipped version
    Image flippedImage(originalImage.width, originalImage.height);

    // Flip the image horizontally
    for (int i = 0; i < originalImage.width; ++i) {
        for (int j = 0; j < originalImage.height; ++j) {
            for (int k= 0; k < 3; ++k) { // Assuming 3 channels (RGB)
                // Copy pixels from the original image to the flipped image in reverse order along the vertical axis
                flippedImage( x -1 - i, j, k) = originalImage(i, j, k);
            }
        }
    }
    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(flippedImage);
}




//rotate images
Image filter6(Image photo){
    cout << "Welcome, Choose A, B or C\n";
    filter6waypoint:
    cout << "(A) rotate the image clockwise 90\n";
    cout << "(B) rotate the image clockwise 180\n";
    cout << "(C) rotate the image clockwise 270\n";
    char c; 
    cin >> c;

    if(c == 'a' || c == 'A'){

        Image route(photo.height, photo.width);

        for(int i=0; i<photo.width; i++){
            for(int j=0; j<photo.height; j++){

                for(int k=0; k<photo.channels; k++){
                    route(photo.height-1-j, photo.width-1-i, k)= photo(i, j, k);
                }
            }
        }

        cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(route);
    }

    else if(c == 'b' || c == 'B'){

        Image route(photo.height, photo.width);
    

        for(int i=0; i<photo.width; i++){
            for(int j=0; j<photo.height; j++){

                for(int k=0; k<photo.channels; k++){
                    route(photo.height-1-j, i, k) = photo(i, j, k);
                }
            
            }
        }
        Image route2(route.height, route.width);
        for(int i=0; i<route.width; i++){
            for(int j=0; j<route.height; j++){

                for(int k=0; k<route.channels; k++){
                    route2(route.height-1-j, i, k) = route(i, j, k);
                }
            }
        }

        cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(route2);
    }

    else if(c == 'c' || c == 'C'){

        Image route(photo.height, photo.width);

        for(int i=0; i<photo.width; i++){
            for(int j=0; j<photo.height; j++){

                for(int k=0; k<photo.channels; k++){
                    route(j, i, k)= photo(i, j, k);
                }
            }
        }
    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(route);

    }

    else{ 
        cout << "PLease enter valid choose\n";
        goto filter6waypoint;
    }


}
//darken and lighten images
Image filter7(Image processed_image){
        cout << "Insert a number between 0 and 100 to dark/lighten" <<endl;
        float value = 0;
        cin >> value;
        filter7waypoint1:
        cout <<"Choose between lightening or Darkening" <<endl;
        cout <<"1-Darken" <<endl;
        cout <<"2-Lighten"<<endl;
        string response2;
        cin >> response2;
        if (response2 == "1")
        {
            value = (value/100)*10;
            for(int i=0; i <processed_image.width;i++){
                for(int j=0;j<processed_image.height;j++){
                    for(int k=0;k<3;++k)
                    {
                        processed_image(i,j,k) = processed_image(i,j,k)/(value);
                    }
                }
            }
        }
        else if(response2 == "2")
        {
            value = (value/101);
            for(int i=0; i <processed_image.width;i++){
                for(int j=0;j<processed_image.height;j++){
                    for(int k=0;k<3;++k)
                    {
                        processed_image(i,j,k) = processed_image(i,j,k)+((255-processed_image(i,j,k))*value);
                    }
                }
            }
        }
        else{
            cout <<"invalid choice"<<endl;
            goto filter7waypoint1;
        }
        cout <<"image processed successfully"<<endl;
        return(processed_image);
}
//crop images
Image filter8(Image processed_image){

    filter8waypoint:
    int starting_position_X, starting_position_Y, width_pece, length_pece;
    string image_name, nameOfNewImage;
    cout << "Please enter the starting_position_X  ";
    cin >> starting_position_X;
    cout << "Please enter the starting_position_Y: ";
    cin >> starting_position_Y;
    cout << "Please enter the width of the piece to crop  ";
    cin >> width_pece;
    cout << "Please enter the height of the piece to crop  ";
    cin >> length_pece;

    if (starting_position_X < 0 || starting_position_Y < 0 ||
        starting_position_X + width_pece > processed_image.width ||
        starting_position_Y + length_pece > processed_image.height) {
        cout << "Invalid dimensions for cropping.\n";
        goto filter8waypoint;
    }

    // Initializing cropped image with desired dimensions
    Image newImage(width_pece, length_pece);

    // Crop the desired piece and copy it to the new image
    for (int i = 0; i < length_pece; ++i) 
    {
        for (int j = 0; j < width_pece; ++j)
        {
            for (int k = 0; k < processed_image.channels; ++k)
            {
                newImage(i, j, k) = processed_image(starting_position_X + i, starting_position_Y + j, k);
            }
        }
    }
    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;  
    return(newImage); 
}
//add frames to images
Image filter9(Image processed_image){
    Image image = processed_image;
    cout << "choose if you want simple frame or fancy one\n";
    cout << "1) simple\n2) fancy: ";
k:
    char c; cin >> c;

    if(c == '1'){   // simple frame
        cout << "Choose the color of frame\n";
        cout << "1) white\n2) red\n3) green\n4) blue\n";
        int colo; cin >> colo;
        cl:
        unsigned int frameSize = image.width/60; 

        for (unsigned int i = 5; i < image.width-5; i++) {
            for (unsigned int j = 5; j < image.height-5; j++) {

                if (i < frameSize || j < frameSize || i >= image.width - frameSize || j >= image.height - frameSize) {
                    if(colo == 1){
                        for (int k = 0; k < 3; k++) {
                            image(i, j, k) = 255; 
                        }
                    }
                    else if(colo == 2){
                        image(i, j, 0) = 255;  image(i, j, 1) = 0;  image(i, j, 2) = 0;
                    }
                    else if(colo == 3){
                        image(i, j, 0) = 0;  image(i, j, 1) = 255;  image(i, j, 2) = 0;
                    }
                    else if(colo == 4){
                        image(i, j, 0) = 0;  image(i, j, 1) = 0;  image(i, j, 2) = 255;
                    }
                    else{
                        cout << "wrong number\n"; goto cl;
                    }
                }
            }
        }

    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(image);
    }

    else if(c == '2'){   // fancy frame
        cout << "Choose the color of frame\n";
        cout << "1) white\n2) red\n3) green\n4) blue\n";
        cl0:
        int colo; cin >> colo;
        unsigned int frameSize = image.height/90; 

        for (unsigned int i = 5; i < image.width-5; i++) {
            for (unsigned int j = 5; j < image.height-5; j++) {

                if (i < frameSize || j < frameSize || i >= image.width - frameSize || j >= image.height - frameSize) {
                    if(colo == 1){
                        for (int k = 0; k < 3; k++) {
                            image(i, j, k) = 255; 
                        }
                    }
                    else if(colo == 2){
                        image(i, j, 0) = 255;  image(i, j, 1) = 0;  image(i, j, 2) = 0;
                    }
                    else if(colo == 3){
                        image(i, j, 0) = 0;  image(i, j, 1) = 255;  image(i, j, 2) = 0;
                    }
                    else if(colo == 4){
                        image(i, j, 0) = 0;  image(i, j, 1) = 0;  image(i, j, 2) = 255;
                    }
                    else{
                        cout << "wrong number\n"; goto cl0;
                    }
                }
            }
        }

        unsigned int frameSize2 = image.height/60;

        for (unsigned int i = 10; i < image.width-10; i++) {
            for (unsigned int j = 10; j < image.height-10; j++) {

                if (i < frameSize2 || j < frameSize2 || i >= image.width - frameSize2 || j >= image.height - frameSize2) {
                    if(colo == 1){
                        for (int k = 0; k < 3; k++) {
                            image(i, j, k) = 255; 
                        }
                    }
                    else if(colo == 2){
                        image(i, j, 0) = 255;  image(i, j, 1) = 0;  image(i, j, 2) = 0;
                    }
                    else if(colo == 3){
                        image(i, j, 0) = 0;  image(i, j, 1) = 255;  image(i, j, 2) = 0;
                    }
                    else if(colo == 4){
                        image(i, j, 0) = 0;  image(i, j, 1) = 0;  image(i, j, 2) = 255;
                    }
                    else{
                        cout << "wrong number\n"; goto cl0;
                    }
                }

                if (i < frameSize2 * 2 && j < frameSize2 * 2 || i >= image.width-1-frameSize2 * 2 && j >= image.height-1-frameSize2 * 2 ||
                    i < frameSize2 * 2 && j >= image.height-1-frameSize2 * 2 || i >= image.width-1-frameSize2 * 2 && j < frameSize2 * 2){
                    if(colo == 1){
                        for (int k = 0; k < 3; k++) {
                            image(i, j, k) = 255; 
                        }
                    }
                    else if(colo == 2){
                        image(i, j, 0) = 255;  image(i, j, 1) = 0;  image(i, j, 2) = 0;
                    }
                    else if(colo == 3){
                        image(i, j, 0) = 0;  image(i, j, 1) = 255;  image(i, j, 2) = 0;
                    }
                    else if(colo == 4){
                        image(i, j, 0) = 0;  image(i, j, 1) = 0;  image(i, j, 2) = 255;
                    }
                    else{
                        cout << "wrong number\n"; goto cl0;
                    }
                }

                if ((i < frameSize2 * 4 && i > frameSize2 * 3 && j < frameSize2 * 4 && j > frameSize2 * 3) || 
                    (i >= image.width - 1 - frameSize2 * 4 && i < image.width - 1 - frameSize2 * 3 && 
                     j >= image.height - 1 - frameSize2 * 4 && j < image.height - 1 - frameSize2 * 3) || 
                    (i < frameSize2 * 4 && i > frameSize2 * 3 && j >= image.height - 1 - frameSize2 * 4 && j < image.height - 1 - frameSize2 * 3) ||
                    (i >= image.width - 1 - frameSize2 * 4 && i < image.width - 1 - frameSize2 * 3 && j < frameSize2 * 4 && j > frameSize2 * 3 )) {

                    if(colo == 1){
                        for (int k = 0; k < 3; k++) {
                            image(i, j, k) = 255; 
                        }
                    }
                    else if(colo == 2){
                        image(i, j, 0) = 255;  image(i, j, 1) = 0;  image(i, j, 2) = 0;
                    }
                    else if(colo == 3){
                        image(i, j, 0) = 0;  image(i, j, 1) = 255;  image(i, j, 2) = 0;
                    }
                    else if(colo == 4){
                        image(i, j, 0) = 0;  image(i, j, 1) = 0;  image(i, j, 2) = 255;
                    }
                    else{
                        cout << "wrong number\n"; goto cl0;
                    }
                }
                if(j < frameSize2 * 4  && j > frameSize2 * 4 - 5 || i < frameSize2 * 4 && i > frameSize2 * 4 - 5 ||
                j > image.height - frameSize2 * 4 - 5 && j < image.height - frameSize2 * 4 || i > image.width - frameSize2 * 4 - 5 && i < image.width - frameSize2 * 4
                ){
                    if(i < frameSize2 * 4 && j < frameSize2 * 4){
                        if(colo == 1){
                        for (int k = 0; k < 3; k++) {
                            image(i, j, k) = 255; 
                        }
                    }
                    else if(colo == 2){
                        image(i, j, 0) = 255;  image(i, j, 1) = 0;  image(i, j, 2) = 0;
                    }
                    else if(colo == 3){
                        image(i, j, 0) = 0;  image(i, j, 1) = 255;  image(i, j, 2) = 0;
                    }
                    else if(colo == 4){
                        image(i, j, 0) = 0;  image(i, j, 1) = 0;  image(i, j, 2) = 255;
                    }
                    else{
                        cout << "wrong number\n"; goto cl0;
                    }
                    }
                    else if(i < frameSize2 * 4 && j > image.height - frameSize2 * 4 - 5){
                        if(colo == 1){
                        for (int k = 0; k < 3; k++) {
                            image(i, j, k) = 255; 
                        }
                    }
                    else if(colo == 2){
                        image(i, j, 0) = 255;  image(i, j, 1) = 0;  image(i, j, 2) = 0;
                    }
                    else if(colo == 3){
                        image(i, j, 0) = 0;  image(i, j, 1) = 255;  image(i, j, 2) = 0;
                    }
                    else if(colo == 4){
                        image(i, j, 0) = 0;  image(i, j, 1) = 0;  image(i, j, 2) = 255;
                    }
                    else{
                        cout << "wrong number\n"; goto cl0;
                    }
                    }
                    else if (i > image.width - frameSize2 * 4 - 5 && j < frameSize2 * 4){
                        if(colo == 1){
                        for (int k = 0; k < 3; k++) {
                            image(i, j, k) = 255; 
                        }
                    }
                    else if(colo == 2){
                        image(i, j, 0) = 255;  image(i, j, 1) = 0;  image(i, j, 2) = 0;
                    }
                    else if(colo == 3){
                        image(i, j, 0) = 0;  image(i, j, 1) = 255;  image(i, j, 2) = 0;
                    }
                    else if(colo == 4){
                        image(i, j, 0) = 0;  image(i, j, 1) = 0;  image(i, j, 2) = 255;
                    }
                    else{
                        cout << "wrong number\n"; goto cl0;
                    }
                    }
                    else if(i > image.width - frameSize2 * 4 - 5 && j > image.height - frameSize2 * 4 - 5){
                        if(colo == 1){
                        for (int k = 0; k < 3; k++) {
                            image(i, j, k) = 255; 
                        }
                    }
                    else if(colo == 2){
                        image(i, j, 0) = 255;  image(i, j, 1) = 0;  image(i, j, 2) = 0;
                    }
                    else if(colo == 3){
                        image(i, j, 0) = 0;  image(i, j, 1) = 255;  image(i, j, 2) = 0;
                    }
                    else if(colo == 4){
                        image(i, j, 0) = 0;  image(i, j, 1) = 0;  image(i, j, 2) = 255;
                    }
                    else{
                        cout << "wrong number\n"; goto cl0;
                    }
                    }
                }
                
            }
        }
        

    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(image);
    }

    else{
        cout << "Invalid input please enter valid number\n";
        goto k;
    }

}


// Function to convert the image to gray and white
void convertToGrayAndWhite(Image& img) {
    int avg;
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            avg = 0;
            // Calculate average pixel value
            for (int k = 0; k < 3; ++k) {
                avg += img(i, j, k);
            }
            avg /= 3;

            // Apply threshold to convert to gray and white
            if (avg > 127) {
                // Set pixel to white (255) for each channel
                for (int k = 0; k < 3; ++k) {
                    img(i, j, k) = 255;
                }
            }
            else {
                // Set pixel to gray (128) for each channel
                for (int k = 0; k < 3; ++k) {
                    img(i, j, k) = 128;
                }
            }
        }
    }
}

// Function to detect edges in the picture using Sobel edge detection
Image detectEdges(const Image& img) {
    string nameOfNewImage;
    int width = img.width;
    int height = img.height;

    // Create a copy of the input image for processing
    Image processedImg = img;

    Image edges(width, height); // Create a new single-channel image for edges

    // Sobel operators for edge detection
    int sobelX[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
    int sobelY[3][3] = { {1, 2, 1}, {0, 0, 0}, {-1, -2, -1} };

    // Apply Sobel operator to each pixel in the image
    for (int x = 1; x < width - 1; ++x) {
        for (int y = 1; y < height - 1; ++y) {
            int gradientX = 0;
            int gradientY = 0;

            // Compute gradients in x and y directions
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    gradientX += processedImg(x + i, y + j, 0) * sobelX[i + 1][j + 1];
                    gradientY += processedImg(x + i, y + j, 0) * sobelY[i + 1][j + 1];
                }
            }

            // Compute gradient magnitude
            int magnitude = sqrt(gradientX * gradientX + gradientY * gradientY);

            // Apply a threshold to detect edges
            if (magnitude > 100) {
                edges(x, y, 0) = 50;
                edges(x, y, 1) = 50;
                edges(x, y, 2) = 50;// Set edge pixel to gray
            }
            else {
                edges(x, y, 0) = 255;
                edges(x, y, 1) = 255;
                edges(x, y, 2) = 255;// Set non-edge pixel to white
            }
        }
    }
    return(edges);
}

Image filter10(Image processed_image){
cout <<"please wait while image is processing"<<endl;
// Function to detect edges in the picture using Sobel edge detection


    convertToGrayAndWhite(processed_image);
    processed_image = detectEdges(processed_image);

    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(processed_image);
}



Image filter11(Image processed_image){
    Image originalImage;
    originalImage = processed_image;
    int new_Width, new_Height;
    cout << "Please enter the new width of the image  ";
    cin >> new_Width;
    cout << "Please enter the new height of the image  ";
    cin >> new_Height;

    // Calculate the scaling factors
    float scaleX = (float)originalImage.width / new_Width;
    float scaleY = (float)originalImage.height / new_Height;

    // Create a new image to store the resized version
    Image resizedImage(new_Width, new_Height);

    // Perform nearest-neighbor interpolation
    for (int i = 0; i < new_Height; ++i) {
        for (int j = 0; j < new_Width; ++j) {
            // Calculate the corresponding position in the original image
            int srcX = (int)(j * scaleX);
            int srcY = (int)(i * scaleY);

            // Copy the pixel value from the original image to the resized image
            for (int k = 0; k < 3; ++k) { 
                resizedImage(j, i, k) = originalImage(srcX, srcY, k);
            }
        }
    }




    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(resizedImage);
}







//blur filter
Image filter12(Image processed_image){
    int width = processed_image.width;
    int height = processed_image.height;

    int kernelSize;
    cout << "Choose the degree of Blur from 1 to UP: ";
    cin >> kernelSize;

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            for (int k = 0; k < 3; ++k) {

                int sum = 0;
                int count = 0;

                for (int dx = -kernelSize ; dx <= kernelSize ; ++dx) {
                    for (int dy = -kernelSize ; dy <= kernelSize ; ++dy) {
                        // Check bounds
                        if ((x + dx >= 0 && x + dx < width) && (y + dy >= 0 && y + dy < height)) {
                            sum += processed_image.getPixel(x + dx, y + dy, k);
                            count++;
                        }
                    }
                }

                unsigned int avg = sum / count;
                processed_image.setPixel(x, y, k, avg);
            }
        }
    }
cout <<"image successfuly processed"<<endl;
cout <<"----------------------------"<<endl;
return(processed_image);
}
//adds sunshine to the image
Image filter15(Image proccessed_image){
    for (int i = 0; i < proccessed_image.width; i++)
    {
        for (int j = 0; j < proccessed_image.height; j++)
        {
            proccessed_image(i,j,0)=proccessed_image(i,j,0);
            proccessed_image(i,j,1)=proccessed_image(i,j,1);
            proccessed_image(i,j,2)=proccessed_image(i,j,2)-50;

            
        }
        
    }
    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(proccessed_image);
}
//oilpainting filter
Image filter16(Image processed_image)
{
    cout <<"Please wait while the image is processing"<<endl;
     int width = processed_image.width;
    int height = processed_image.height;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            for (int k = 0; k < 2; k++)
            {
                processed_image(x,y,k)/=30;
                processed_image(x,y,k)*=30;
            }
            
        }
    }

cout <<"image successfuly processed"<<endl;
cout <<"----------------------------"<<endl;
return(processed_image);
}
//television effect filter
Image filter17(Image processed_image)
{
    srand(time(0));
    Image newImage(processed_image.width,processed_image.height);
    unsigned int avg;
      for (int i = 0; i < processed_image.width; i++)
    {
        for (int j = 0; j < processed_image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
            int randomvalue = rand()%100;
            int coinflip = rand()%2;
            if(coinflip = 1){
            newImage(i,j,k) = min(255,processed_image(i,j,k) + randomvalue);
            randomvalue = 0;
            }
            }
        }
    }
    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(newImage); 
}
//purple filter
Image filter18(Image processed_image){
        for (int i = 0; i < processed_image.width; i++)
    {
        for (int j = 0; j < processed_image.height; j++)
        {
            processed_image(i,j,0)=processed_image(i,j,0);
            processed_image(i,j,1)=max(0,processed_image(i,j,1)-30);
            processed_image(i,j,2)=processed_image(i,j,2);

            
        }
        
    }
    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(processed_image);
}
//infrared filter
Image filter19(Image processed_image){
           for (int i = 0; i < processed_image.width; i++)
    {
        for (int j = 0; j < processed_image.height; j++)
        {
            processed_image(i,j,0)=255;
            processed_image(i,j,1)=255-processed_image(i,j,1);
            processed_image(i,j,2)=255-processed_image(i,j,2);

            
        }
        
    }
    cout <<"image successfuly processed"<<endl;
    cout <<"----------------------------"<<endl;
    return(processed_image);
}

Image filter20(Image processed_image){
    filter20waypoint:
    cout <<"please enter a degree for skewing"<<endl;
    string x;
    cin >> x;
    if(stoi(x)>90 || stoi(x) < 0 ){
        cout <<"invalid input";
        goto filter20waypoint;
    }
    float skew_Degree = stoi(x);
    Image originalImage;
    originalImage = processed_image;
    // Calculate radians from degrees for trigonometric functions
    float skew_Radians = skew_Degree * M_PI / 180.0;

    // Calculate the dimensions of the skewed image
    int skewed_Width = originalImage.width + abs((int)(originalImage.height * tan(skew_Radians)));
    int skewed_Height = originalImage.height;

    // Create a new image to store the skewed version
    Image skewedImage(skewed_Width, skewed_Height);

    // Apply skewing to each pixel
    for (int i = 0; i < skewed_Width; ++i) {
        for (int j = 0; j < skewed_Height; ++j) {
            // Calculate the corresponding coordinates in the original image
            int originalX = i - j * tan(skew_Radians);
            int originalY = j;

            // Check if the coordinates are within the bounds of the original image
            if (originalX >= 0 && originalX < originalImage.width && originalY >= 0 && originalY < originalImage.height) {
                // Copy pixel values from the original image to the skewed image
                for (int k = 0; k < originalImage.channels; ++k) {
                    skewedImage(i, j, k) = originalImage(originalX, originalY, k);
                }
            }
        }
    }
cout <<"image successfuly processed"<<endl;
cout <<"----------------------------"<<endl;
return(skewedImage);
}


Image slightblur(Image processed_image){
    int width = processed_image.width;
    int height = processed_image.height;

    int kernelSize = 3;

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            for (int k = 0; k < 3; ++k) {

                int sum = 0;
                int count = 0;

                for (int dx = -kernelSize ; dx <= kernelSize ; ++dx) {
                    for (int dy = -kernelSize ; dy <= kernelSize ; ++dy) {
                        // Check bounds
                        if ((x + dx >= 0 && x + dx < width) && (y + dy >= 0 && y + dy < height)) {
                            sum += processed_image.getPixel(x + dx, y + dy, k);
                            count++;
                        }
                    }
                }

                unsigned int avg = sum / count;
                processed_image.setPixel(x, y, k, avg);
            }
        }
    }
return(processed_image);
}



//adds random white stars at random highlight points and slightly blurs the image
Image filter21(Image processed_image){
cout <<"please wait while image is processing"<<endl;
srand(time(0));
    for (int x = 0; x < processed_image.width; x++)
    {
        for (int y = 0; y < processed_image.height; y++)
        {
            if(processed_image(x,y,0)> 220 && processed_image(x,y,1)>220 && processed_image(x,y,2)>220 && y < processed_image.height-100 && x < processed_image.width - 100 && x > 100 && y > 100)
            {   
                srand(time(0));
                int randomint = rand()%30;
                //making sure that the size of stars is different
                for (int h = 0; h < 30+randomint ; h++)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        processed_image(x+h,y,k) = 180+randomint*2;
                        processed_image(x-h,y,k) = 180+randomint*2;
                        processed_image(x,y-h,k) = 180+randomint*2;
                        processed_image(x,y+h,k) = 180+randomint*2;
                        
                        //making sure highlights arent spammed with stars
                
                    }   
                }
            srand(time(0));
            int distance = rand()%40;
            y=(min(y+100+randomint + distance,processed_image.height));
            x=(min(x+100+randomint + distance,processed_image.width)); 
            }
        }
    } 
//slight bleach for he effect
processed_image = slightblur(processed_image);
cout <<"image successfuly processed"<<endl;
cout <<"----------------------------"<<endl;
return(processed_image);
}

//contrast filter to enhance images
Image filter22(Image processed_image)
{
    int intensity;
    for (int i = 0; i < processed_image.width; i++)
    {
        for (int j = 0; j < processed_image.height; j++)
        {
            intensity = processed_image(i,j,0) + processed_image(i,j,1) + processed_image(i,j,2);
            intensity /=3;
            //contrast where if intensity is higher than a threshold, light things get lighter
            if (intensity > 160 )
            {
                for (int k = 0; k < 3; k++)
                {
                    processed_image(i,j,k) = min(255,processed_image(i,j,k) + 40);
                }
                
            }
            //contrast where if intensity is lower than a threshold, dark things get darker
            else if(intensity < 100)
            {
            for (size_t k = 0; k < 3; k++)
            {
                processed_image(i,j,k) = max(0,processed_image(i,j,k) - 40);
            }
            
            }
        
        }
    }





cout <<"image successfuly processed"<<endl;
cout <<"----------------------------"<<endl;
return(processed_image);
}

void menu(){
    #include "Image_Class.h"
    g:
    cout << "===========================================================================" << endl;
    cout << "Welcome to Baby Photoshop, Please select a functionality from the following" << endl;
    cout << "===========================================================================" << endl;
    newimage:
    string image_name;
    cin >> image_name;
    try
    {
        Image test_image(image_name);
    }
    catch(...)
    {
        cout <<"Try again" <<endl;
        goto g;
    }
    Image image1(image_name);
    menuwaypoint:
    cout <<"Please select a specific functionality that you wish to use" << endl;
    cout <<"================================================="<<endl;
    cout <<"0-insert a new image"<< endl;
    cout <<"1-gray scale filter" << endl;
    cout <<"2-black and white filter"<< endl;
    cout <<"3-invert images"<< endl;
    cout <<"4-merge images" << endl;
    cout <<"5-flip image" << endl;
    cout <<"6-rotate image" << endl;
    cout <<"7-darken and lighten images" <<endl;
    cout <<"8-crop images" << endl;
    cout <<"9-add a frame" << endl;
    cout <<"10-detect image edges" << endl;
    cout <<"11-resizing images" << endl;
    cout <<"12-Blur Filter" << endl;
    cout <<"13-Sunshine Filter"<< endl;
    cout <<"14-Oilpainting Filer"<< endl;
    cout <<"15-Television Filter"<< endl;
    cout <<"16-Purple Filter"<< endl;
    cout <<"17-Infrared Filter"<< endl;
    cout <<"18-Skew Filter"<<endl;
    cout <<"19-Disney effect Filter"<<endl;
    cout <<"20-Contrast Filter"<<endl;
    cout <<"S-save and exit"<<endl;
    cout <<"E-exit"<<endl;
    cout <<"================================================="<< endl;
    string response;
    cout <<"your response: ";
    cin >> response;
    if(response == "0"){
    cout <<"please insert the new of an existing image"<<endl;
    goto newimage;
    }
    else if(response == "1"){
        image1 = filter1(image1);
        goto menuwaypoint;
    }
    else if(response == "2"){
        image1 = filter2(image1);
        goto menuwaypoint;
    }
    else if(response == "3"){
        image1 = filter3(image1);
        goto menuwaypoint;
    }
    else if(response == "4"){
    string image_name2;
    cout <<"please insert a new image to merge with the previous one" << endl;
    cin >> image_name2;
    Image image2(image_name2);
    image1 = filter4(image1,image2);
    goto menuwaypoint;
    }
    else if(response == "5"){
        image1 = filter5(image1);
        goto menuwaypoint;
    }
    else if(response == "6"){
        image1 = filter6(image1);
        goto menuwaypoint;
    }
    else if(response == "7"){
        image1 = filter7(image1);
        goto menuwaypoint;
    }
    else if(response == "8"){
        image1 = filter8(image1);
        goto menuwaypoint;
    }
    else if(response == "9"){
        image1 = filter9(image1);
        goto menuwaypoint;
    }
    else if(response == "10"){
        image1 = filter10(image1);
        goto menuwaypoint;
    }
    else if(response == "11"){
        image1 = filter11(image1);
        goto menuwaypoint;
    }
    else if(response == "12"){
        image1 = filter12(image1);
        goto menuwaypoint;
    }
    else if(response == "13"){
        image1 = filter15(image1);
        goto menuwaypoint;
    }
    else if(response == "14"){
        image1 = filter16(image1);
        goto menuwaypoint;
    }
    else if(response == "15"){
        image1 = filter17(image1);
        goto menuwaypoint;
    }
    else if(response == "16"){
        image1 = filter18(image1);
        goto menuwaypoint;
    }
    else if(response == "17"){
        image1 = filter19(image1);
        goto menuwaypoint;
    }
    else if(response == "18"){
        image1 = filter20(image1);
        goto menuwaypoint;
    }
    else if(response == "19"){
        image1 = (filter21(image1));
        goto menuwaypoint;
    }
    else if(response == "20"){
        image1 = filter22(image1);
        goto menuwaypoint;
    }
    else if(response == "S" || response =="s"){
        extensionadder(image1);
        menu();
    }
    else if(response == "E" || response == "e"){
        exit(0);
    }
    else{
        cout << "invalid choice, please select again"<< endl;
        goto menuwaypoint;
    }



}

int main()
{
    menu();
}