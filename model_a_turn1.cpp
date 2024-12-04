#include <iostream>
#include <fstream>
#include <vector>

struct Point {
    int x;
    int y;
};

// Serialize a Point object to a binary file
void serializePoint(const Point& point, std::ofstream& out) {
    out.write(reinterpret_cast<const char*>(&point), sizeof(Point));
}

// Deserialize a Point object from a binary file
void deserializePoint(Point& point, std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&point), sizeof(Point));
}

int main() {
    Point point = {10, 20};

    // Serialize to binary file
    std::ofstream outFile("point.bin", std::ios::binary);
    serializePoint(point, outFile);
    outFile.close();

    // Deserialize from binary file
    std::ifstream inFile("point.bin", std::ios::binary);
    Point deserializedPoint;
    deserializePoint(deserializedPoint, inFile);
    inFile.close();

    // Output the deserialized point
    std::cout << "Deserialized point: (" << deserializedPoint.x << ", " << deserializedPoint.y << ")" << std::endl;

    return 0;
}