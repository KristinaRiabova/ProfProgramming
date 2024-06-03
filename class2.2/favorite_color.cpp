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
        for (int i = 0; i < rows; ++i) {
            getline(infile, line);
            istringstream iss(line);
            string pixel;
            for (int j = 0; j < cols; ++j) {
                getline(iss, pixel, ' ');
                replace(pixel.begin(), pixel.end(), ',', ' ');  // Correct usage of std::replace
                istringstream pixelStream(pixel);
                int r, g, b;
                pixelStream >> r >> g >> b;
                image[i][j] = Pixel(r, g, b);
            }
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
        if (!validateInput()) {
            cerr << "Invalid input data format." << endl;
            exit(1);
        }
        processImage();
        writeImage(outputFilename);
    }
};

int main() {
    string inputFilename, outputFilename;
    int favR, favG, favB;
    
    cout << "Enter input file name: ";
    cin >> inputFilename;
    cout << "Enter favorite color (R G B): ";
    cin >> favR >> favG >> favB;
    cout << "Enter output file name: ";
    cin >> outputFilename;
    
    ImageProcessor processor;
    processor.setFavoriteColor(favR, favG, favB);
    processor.readImage(inputFilename);
    processor.processAndSave(outputFilename);
    
    return 0;
}
