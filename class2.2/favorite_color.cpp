#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Pixel {
public:
    int r, g, b;
    Pixel(int r = 0, int g = 0, int b = 0) : r(r), g(g), b(b) {}
    
    bool operator==(const Pixel& other) const {
        return r == other.r && g == other.g && b == other.b;
    }
};

class ImageProcessor {
private:
    vector<vector<Pixel>> image;
    Pixel favorite;
    int rows;
    int cols;

    void processImage() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (image[i][j] == favorite) {
                    if (j > 0) {
                        image[i][j - 1] = favorite;  // Left neighbor
                    }
                    if (i > 0) {
                        image[i - 1][j] = favorite;  // Top neighbor
                    }
                }
            }
        }
    }

    bool validateInput() const {
        if (image.size() != rows) return false;
        for (const auto& row : image) {
            if (row.size() != cols) return false;
            for (const auto& pixel : row) {
                if (pixel.r < 0 || pixel.r > 255 || pixel.g < 0 || pixel.g > 255 || pixel.b < 0 || pixel.b > 255) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    ImageProcessor(int rows = 16, int cols = 16) : rows(rows), cols(cols) {
        image.resize(rows, vector<Pixel>(cols));
    }

    void setFavoriteColor(int r, int g, int b) {
        favorite = Pixel(r, g, b);
    }

void readImage(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    string line;
    bool isEmpty = true; // Flag to track if the file is empty
    for (int i = 0; i < rows; ++i) {
        if (getline(infile, line)) {
            isEmpty = false;
            istringstream iss(line);
            string pixel;
            for (int j = 0; j < cols; ++j) {
                if (getline(iss, pixel, ' ')) {
                    replace(pixel.begin(), pixel.end(), ',', ' ');  
                    istringstream pixelStream(pixel);
                    int r, g, b;
                    if (!(pixelStream >> r >> g >> b)) {
                        cerr << "Error: Invalid format in line " << i + 1 << " of the input file." << endl;
                        exit(1);
                    }
                    image[i][j] = Pixel(r, g, b);
                } else {
                    cerr << "Error: Unexpected end of file." << endl;
                    exit(1);
                }
            }
            if (iss >> pixel) {
                cerr << "Error: Extra data in line " << i + 1 << " of the input file." << endl;
                exit(1);
            }
        }
    }
    if (isEmpty) {
        cerr << "Error: File is empty." << endl;
        exit(1);
    }
}


    void writeImage(const string& filename) const {
        ofstream outfile(filename);
        if (!outfile) {
            cerr << "Error writing to file: " << filename << endl;
            exit(1);
        }
        for (const auto& row : image) {
            for (const auto& pixel : row) {
                outfile << pixel.r << "," << pixel.g << "," << pixel.b << " ";
            }
            outfile << endl;
        }
    }

   void processAndSave(const string& outputFilename) {
    bool foundFavoriteColor = false; // Flag to track if favorite color is found in the image
    for (const auto& row : image) {
        for (const auto& pixel : row) {
            if (pixel == favorite) {
                foundFavoriteColor = true;
                break;
            }
        }
        if (foundFavoriteColor) break; // If found, no need to continue searching
    }

    if (!foundFavoriteColor) {
        cerr << "Favorite color not found in the image." << endl;
        exit(1);
    }

    if (!validateInput()) {
        cerr << "Invalid input data format." << endl;
        exit(1);
    }
    processImage();
    writeImage(outputFilename);
}

};

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cerr << "Usage: " << argv[0] << " input_file favorite_r favorite_g favorite_b output_file" << endl;
        return 1;
    }

    string inputFilename = argv[1];
    int favR = atoi(argv[2]);
    int favG = atoi(argv[3]);
    int favB = atoi(argv[4]);
    string outputFilename = argv[5];
    
    ImageProcessor processor;
    processor.setFavoriteColor(favR, favG, favB);
    processor.readImage(inputFilename);
    processor.processAndSave(outputFilename);
    
    return 0;
}
