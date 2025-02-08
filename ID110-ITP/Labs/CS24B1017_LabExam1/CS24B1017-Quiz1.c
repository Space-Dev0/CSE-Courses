#include <stdio.h>
#include <stdlib.h>

void forward_propogation(float *input_layer, float ***weights, int *layer_sizes, int q);
void neural_network(float *input_layer, float ***weights, int *layer_sizes, int hidden_layer_count);
float ReLU(float);

int main()
{
    // Inputs and initiallizing variables and arrays

    int input_size, hidden_layer_count;

    printf("Enter number of input layer neurons: ");
    scanf("%d", &input_size);

    float input_layer[input_size];
    printf("Enter values for each input layer neuron: ");
    for (int i = 0; i < input_size; i++)
        scanf("%f", input_layer + i);

    printf("Enter hidden layer count: ");
    scanf("%d", &hidden_layer_count);

    int layer_sizes[hidden_layer_count + 2];
    layer_sizes[0] = input_size;
    layer_sizes[hidden_layer_count + 1] = 1;
    printf("Enter sizes of hidden layers");
    for (int i = 1; i < hidden_layer_count + 1; i++)
        scanf("%d", layer_sizes + i);
 
    printf("Enter weights: ");
    float ***weights = (float ***)malloc((hidden_layer_count + 1) * sizeof(float *));
    for (int i = 0; i < hidden_layer_count + 1; i++)
    {
        weights[i] = (float **)malloc((layer_sizes[i]) * (sizeof(float *)));

        for (int j = 0; j < layer_sizes[i]; j++)
        {
            weights[i][j] = (float *)malloc((layer_sizes[i + 1]) * sizeof(float));
            for (int k = 0; k < layer_sizes[i + 1]; k++)
            {
                scanf("%f", &weights[i][j][k]);
            }
        }
    }

    neural_network(input_layer, weights, layer_sizes, hidden_layer_count);

    printf("Output: %f", input_layer[0]);
}

void forward_propogation(float *input_layer, float ***weights, int *layer_sizes, int q)
{
    //Matrix Multiplication and forwarding
    float temp[layer_sizes[q + 1]];
    for (int i = 0; i < layer_sizes[q + 1]; i++)
    {
        float sum = 0;
        for (int j = 0; j < layer_sizes[0]; j++)
        {
            sum = sum + ((*(*(*(weights + q) + j) + i)) * (input_layer[j]));
        }
        temp[i] = ReLU(sum);
    }

    for (int i = 0; i < layer_sizes[q + 1]; i++)
        input_layer[i] = temp[i];
    layer_sizes[0] = layer_sizes[q + 1];
}

void neural_network(float *input_layer, float ***weights, int *layer_sizes, int hidden_layer_count)
{
    for (int i = 0; i < hidden_layer_count + 1; i++)
    {
        forward_propogation(input_layer, weights, layer_sizes, i);
    }
}

float ReLU(float a)
{
    if (a < 0)
    {
        return 0;
    }
    else
        return a;
}