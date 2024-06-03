import java.io.*;
import java.util.*;

class Pixel {
    int r, g, b;

    Pixel(int r, int g, int b) {
        this.r = r;
        this.g = g;
        this.b = b;
    }

    boolean equals(Pixel other) {
        return this.r == other.r && this.g == other.g && this.b == other.b;
    }
}

class ImageProcessor {
    private List<List<Pixel>> image;
    private Pixel favorite;
    private Pixel unfavorite;
    private int rows;
    private int cols;

    ImageProcessor(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        image = new ArrayList<>(rows);
        for (int i = 0; i < rows; i++) {
            List<Pixel> row = new ArrayList<>(cols);
            for (int j = 0; j < cols; j++) {
                row.add(new Pixel(0, 0, 0));
            }
            image.add(row);
        }
    }

    void setFavoriteColor(int r, int g, int b) {
        favorite = new Pixel(r, g, b);
    }

    void setUnfavoriteColor(int r, int g, int b) {
        unfavorite = new Pixel(r, g, b);
    }

    void readImage(String filename) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename));
            String line;
            int i = 0;
            while ((line = reader.readLine()) != null && i < rows) {
                String[] pixels = line.split(" ");
                int j = 0;
                for (String pixel : pixels) {
                    String[] rgb = pixel.split(",");
                    int r = Integer.parseInt(rgb[0]);
                    int g = Integer.parseInt(rgb[1]);
                    int b = Integer.parseInt(rgb[2]);
                    image.get(i).set(j, new Pixel(r, g, b));
                    j++;
                }
                i++;
            }
            reader.close();
        } catch (IOException e) {
            System.err.println("Error reading file: " + filename);
            e.printStackTrace();
            System.exit(1);
        }
    }

    void processImage() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Pixel current = image.get(i).get(j);
                if (current.equals(unfavorite)) {
                    image.get(i).set(j, favorite);
                }
            }
        }
    }

    void writeImage(String filename) {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
            for (List<Pixel> row : image) {
                for (Pixel pixel : row) {
                    writer.write(pixel.r + "," + pixel.g + "," + pixel.b + " ");
                }
                writer.newLine();
            }
            writer.close();
        } catch (IOException e) {
            System.err.println("Error writing to file: " + filename);
            e.printStackTrace();
            System.exit(1);
        }
    }

    void processAndSave(String outputFilename) {
        processImage();
        writeImage(outputFilename);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter input file name: ");
        String inputFilename = scanner.nextLine();
        System.out.print("Enter favorite color (R G B): ");
        int favR = scanner.nextInt();
        int favG = scanner.nextInt();
        int favB = scanner.nextInt();
        System.out.print("Enter unfavorite color (R G B) (Optional, enter -1 -1 -1 if not needed): ");
        int unfavR = scanner.nextInt();
        int unfavG = scanner.nextInt();
        int unfavB = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        System.out.print("Enter output file name: ");
        String outputFilename = scanner.nextLine();

        ImageProcessor processor = new ImageProcessor(16, 16);
        processor.setFavoriteColor(favR, favG, favB);
        if (unfavR != -1 && unfavG != -1 && unfavB != -1) {
            processor.setUnfavoriteColor(unfavR, unfavG, unfavB);
        }
        processor.readImage(inputFilename);
        processor.processAndSave(outputFilename);

        scanner.close();
    }
}
