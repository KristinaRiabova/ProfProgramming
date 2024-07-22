import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

class Pixel {
    int r, g, b;

    Pixel(int r, int g, int b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pixel pixel = (Pixel) o;
        return r == pixel.r && g == pixel.g && b == pixel.b;
    }
}

class ImageProcessor {
    private Pixel[][] image;
    private Pixel favorite;
    private Pixel unfavorite;
    private int rows;
    private int cols;

    public ImageProcessor(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        image = new Pixel[rows][cols];
    }

    public void setFavoriteColor(int r, int g, int b) {
        if (isValidColor(r, g, b)) {
            favorite = new Pixel(r, g, b);
        } else {
            System.err.println("Invalid favorite color");
            System.exit(1);
        }
    }

    public void setUnfavoriteColor(int r, int g, int b) {
        if (isValidColor(r, g, b)) {
            unfavorite = new Pixel(r, g, b);
        } else {
            System.err.println("Invalid unfavorite color");
            System.exit(1);
        }
    }

    private boolean isValidColor(int r, int g, int b) {
        return (r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255);
    }

    private void processImage() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (unfavorite != null && image[i][j].equals(unfavorite)) {
                    image[i][j] = favorite;
                } else if (image[i][j].equals(favorite)) {
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

    public void readImage(String filename) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename));
            String line;
            int row = 0;
            while ((line = reader.readLine()) != null && row < rows) {
                String[] values = line.split(" ");
                if (values.length != cols) {
                    System.err.println("Invalid number of pixels in row " + (row + 1));
                    System.exit(1);
                }
                for (int col = 0; col < cols; col++) {
                    String[] rgb = values[col].split(",");
                    if (rgb.length != 3) {
                        System.err.println("Invalid pixel format in row " + (row + 1) + ", column " + (col + 1));
                        System.exit(1);
                    }
                    int r = Integer.parseInt(rgb[0]);
                    int g = Integer.parseInt(rgb[1]);
                    int b = Integer.parseInt(rgb[2]);
                    if (!isValidColor(r, g, b)) {
                        System.err.println("Pixel color out of range in row " + (row + 1) + ", column " + (col + 1));
                        System.exit(1);
                    }
                    image[row][col] = new Pixel(r, g, b);
                }
                row++;
            }
            if (row < rows) {
                System.err.println("Not enough rows in the input image");
                System.exit(1);
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void writeImage(String filename) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    writer.write(image[i][j].r + "," + image[i][j].g + "," + image[i][j].b + " ");
                }
                writer.newLine();
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void processAndSave(String outputFilename) {
        if (favorite == null) {
            System.err.println("Favorite color not set");
            System.exit(1);
        }
        // Check if unfavorite color is provided and if it is present in the image
        if (unfavorite != null) {
            boolean unfavColorFound = false;
            for (Pixel[] row : image) {
                for (Pixel pixel : row) {
                    if (pixel != null && pixel.equals(unfavorite)) {
                        unfavColorFound = true;
                        break;
                    }
                }
                if (unfavColorFound) {
                    break;
                }
            }
            if (!unfavColorFound) {
                System.err.println("Unfavorite color not found in the image");
                System.exit(1);
            }
        }
        // Processing the image
        processImage();
        // Saving the processed image
        writeImage(outputFilename);
    }
}

public class Main {
    public static void main(String[] args) {
        if (args.length != 5 && args.length != 8) {
            System.err.println("Usage: java Main input_file favorite_r favorite_g favorite_b output_file [unfavorite_r unfavorite_g unfavorite_b]");
            System.exit(1);
        }

        String inputFilename = args[0];
        int favR = Integer.parseInt(args[1]);
        int favG = Integer.parseInt(args[2]);
        int favB = Integer.parseInt(args[3]);
        String outputFilename = args[4];

        ImageProcessor processor = new ImageProcessor(16, 16);
        processor.setFavoriteColor(favR, favG, favB);
        
        File inputFile = new File(inputFilename);
        if (!inputFile.exists()) {
            System.err.println("Input file does not exist");
            System.exit(1);
        }
        
        processor.readImage(inputFilename);

        if (args.length == 8) { // If unfavorite color provided
            int unfavR = Integer.parseInt(args[5]);
            int unfavG = Integer.parseInt(args[6]);
            int unfavB = Integer.parseInt(args[7]);
            processor.setUnfavoriteColor(unfavR, unfavG, unfavB);
            
            // Check if the unfavorite color matches the favorite color
            if (favR == unfavR && favG == unfavG && favB == unfavB) {
                System.err.println("Unfavorite color is the same as the favorite color");
                System.exit(1);
            }
        }

        processor.processAndSave(outputFilename);
    }
}
