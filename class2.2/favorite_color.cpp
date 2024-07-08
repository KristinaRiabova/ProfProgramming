#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace {
    constexpr auto IMAGE_WIDTH = 16;
    constexpr auto IMAGE_HEIGHT = 16;
}

class Pixel {
public:
    int r, g, b;
    Pixel(int r = 0, int g = 0, int b = 0) : r(r), g(g), b(b) {}

    bool operator==(const Pixel& other) const {
        return r == other.r && g == other.g && b == other.b;
    }

    bool isValid() const {
        return r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255;
    }

    std::string toString() const {
        return std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b);
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
                if (!pixel.isValid()) return false;
            }
        }
        return true;
    }

public:
    ImageProcessor(int rows = IMAGE_HEIGHT, int cols = IMAGE_WIDTH) : rows(rows), cols(cols) {
        image.resize(rows, vector<Pixel>(cols));
    }

    void setFavoriteColor(int r, int g, int b) {
        favorite = Pixel(r, g, b);
    }

    bool readImage(const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            cerr << "Error opening file: " << filename << endl;
            return false;
        }
        string line;
        for (int i = 0; i < rows; ++i) {
            if (getline(infile, line)) {
                istringstream iss(line);
                string pixel;
                for (int j = 0; j < cols; ++j) {
                    if (getline(iss, pixel, ' ')) {
                        replace(pixel.begin(), pixel.end(), ',', ' ');
                        istringstream pixelStream(pixel);
                        int r, g, b;
                        if (!(pixelStream >> r >> g >> b)) {
                            cerr << "Error: Invalid format in line " << i + 1 << " of the input file." << endl;
                            return false;
                        }
                        image[i][j] = Pixel(r, g, b);
                    } else {
                        cerr << "Error: Unexpected end of file." << endl;
                        return false;
                    }
                }
                if (iss >> pixel) {
                    cerr << "Error: Extra data in line " << i + 1 << " of the input file." << endl;
                    return false;
                }
            }
        }
        if (getline(infile, line)) {
            cerr << "Error: Extra lines present in the file." << endl;
            return false;
        }
        return true;
    }

    bool writeImage(const string& filename) const {
        ofstream outfile(filename);
        if (!outfile) {
            cerr << "Error writing to file: " << filename << endl;
            return false;
        }
        for (const auto& row : image) {
            for (size_t j = 0; j < row.size(); ++j) {
                outfile << row[j].toString();
                if (j < row.size() - 1) {
                    outfile << " ";
                }
            }
            outfile << endl;
        }
        return true;
    }

    bool processAndSave(const string& outputFilename) {
        bool foundFavoriteColor = false;
        for (const auto& row : image) {
            for (const auto& pixel : row) {
                if (pixel == favorite) {
                    foundFavoriteColor = true;
                    break;
                }
            }
            if (foundFavoriteColor) break;
        }

        if (!foundFavoriteColor) {
            cerr << "Favorite color not found in the image." << endl;
            return false;
        }

        if (!validateInput()) {
            cerr << "Invalid input data format." << endl;
            return false;
        }

        processImage();
        return writeImage(outputFilename);
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

    if (!processor.readImage(inputFilename)) {
        return 1;
    }

    if (!processor.processAndSave(outputFilename)) {
        return 1;
    }

    return 0;
}
