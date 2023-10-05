#include <iostream>
#include <vector>
#include <random>

// Define the MNIST dataset size
const int numInputs = 784; // 28x28 pixels
const int numHidden = 128; // Number of neurons in the hidden layer
const int numOutputs = 10; // 0-9 digits

// Define the neural network structure
struct NeuralNetwork {
    std::vector<std::vector<double>> weightsIH; // Input to Hidden Layer Weights
    std::vector<double> biasH; // Hidden Layer Bias
    std::vector<std::vector<double>> weightsHO; // Hidden to Output Layer Weights
    std::vector<double> biasO; // Output Layer Bias
};

// Activation function (sigmoid)
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Feedforward pass
std::vector<double> feedforward(const NeuralNetwork& network, const std::vector<double>& input) {
    // Calculate the hidden layer outputs
    std::vector<double> hidden(numHidden);
    for (int i = 0; i < numHidden; i++) {
        hidden[i] = 0.0;
        for (int j = 0; j < numInputs; j++) {
            hidden[i] += input[j] * network.weightsIH[i][j];
        }
        hidden[i] += network.biasH[i];
        hidden[i] = sigmoid(hidden[i]);
    }

    // Calculate the output layer outputs
    std::vector<double> output(numOutputs);
    for (int i = 0; i < numOutputs; i++) {
        output[i] = 0.0;
        for (int j = 0; j < numHidden; j++) {
            output[i] += hidden[j] * network.weightsHO[i][j];
        }
        output[i] += network.biasO[i];
        output[i] = sigmoid(output[i]);
    }

    return output;
}

int main() {
    // Initialize the neural network with random weights and biases
    NeuralNetwork network;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    network.weightsIH.resize(numHidden, std::vector<double>(numInputs));
    network.biasH.resize(numHidden);
    network.weightsHO.resize(numOutputs, std::vector<double>(numHidden));
    network.biasO.resize(numOutputs);

    for (int i = 0; i < numHidden; i++) {
        for (int j = 0; j < numInputs; j++) {
            network.weightsIH[i][j] = dist(gen);
        }
        network.biasH[i] = dist(gen);
    }

    for (int i = 0; i < numOutputs; i++) {
        for (int j = 0; j < numHidden; j++) {
            network.weightsHO[i][j] = dist(gen);
        }
        network.biasO[i] = dist(gen);
    }

    // Test the network with an example input
    std::vector<double> input(numInputs, 0.0);
    // Set the input values (you should load actual MNIST data here)

    std::vector<double> output = feedforward(network, input);

    // Print the output
    std::cout << "Output: ";
    for (int i = 0; i < numOutputs; i++) {
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
