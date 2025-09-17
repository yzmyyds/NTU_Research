#include <iostream>
#include <vector>
using namespace std;

struct Image{
    int width;
    int height;
    vector<vector<int>> pixels;
    vector<vector<bool>> flooded;
    Image(vector<vector<int>> p): pixels(p) {
        height = pixels.size();
        width = pixels[0].size();
        flooded = vector<vector<bool>>(height, vector<bool>(width, false));
    }
};

void floodFill(Image &img, int x, int y, int newcolor, int oldcolor) {
    if (x < 0 || x >= img.width || y < 0 || y >= img.height) return;
    if (img.flooded[y][x] || img.pixels[y][x] != oldcolor) return;

    img.pixels[y][x] = newcolor;
    img.flooded[y][x] = true;

    floodFill(img, x+1, y, newcolor, oldcolor);
    floodFill(img, x-1, y, newcolor, oldcolor);
    floodFill(img, x, y+1, newcolor, oldcolor);
    floodFill(img, x, y-1, newcolor, oldcolor);
}

int main() {
    // convert gray scale image to 2D matrix
    vector<vector<int>> pixels = {
        {1, 1, 1, 0, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 0, 1, 0}
    };

    Image img(pixels);
    int oldcolor = img.pixels[2][2];
    floodFill(img, 2, 2, 2,oldcolor); // Start flood fill at (2,2) with new color 2

    for (const auto &row : img.pixels) {
        for (const auto &pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    // output flooded matrix
    cout << "Flooded Matrix:" << endl;
    for (const auto &row : img.flooded) {
        for (const auto &flood : row) {
            cout << flood << " ";
        }
        cout << endl;
    }
    return 0;
}