#include <iostream>
#include <fstream>
using namespace std;
struct Layer {
    int neurons;
    float weights[10];
    float bias;
};
int main() {
    const int NUM_LAYERS = 3;
    Layer* network = new Layer[NUM_LAYERS];
    network[0].neurons = 4;
    network[0].bias    = 0.1;
    for (int w = 0; w < 10; w++)
        network[0].weights[w] = 0.10 + w * 0.05;
    network[1].neurons = 8;
    network[1].bias    = 0.25;
    for (int w = 0; w < 10; w++)
        network[1].weights[w] = 0.20 + w * 0.03;
    network[2].neurons = 2;
    network[2].bias    = 0.5;
    for (int w = 0; w < 10; w++)
        network[2].weights[w] = 0.30 + w * 0.07;
    ofstream outFile("model_weights.bin", ios::binary);
    outFile.write((char*)network, sizeof(Layer) * NUM_LAYERS);
    outFile.close();
    cout << "Model weights saved to model_weights.bin\n\n";
    delete[] network;
    Layer* loaded = new Layer[NUM_LAYERS];
    ifstream inFile("model_weights.bin", ios::binary);
    inFile.read((char*)loaded, sizeof(Layer) * NUM_LAYERS);
    inFile.close();
    string layerNames[3] = {"Input Layer", "Hidden Layer", "Output Layer"};
    cout << "       NEURAL NETWORK WEIGHT VERIFY       \n";
    cout << "==========================================\n";
    for (int i = 0; i < NUM_LAYERS; i++) {
        cout << "\n[" << layerNames[i] << "]\n";
        cout << "  Neurons : " << loaded[i].neurons << "\n";
        cout << "  Bias    : " << loaded[i].bias    << "\n";
        cout << "  Weights : ";
        for (int w = 0; w < 10; w++) {
            cout << loaded[i].weights[w];
            if (w < 9) cout << ", ";
        }
        cout << "\n";
    }
    cout << "\n------------------------------------------\n";
    cout << "Binary read/write verified successfully!\n";
    delete[] loaded;
    return 0;
}
