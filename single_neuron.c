//IMPORTS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//TRAINING DATA
float training_data[][2] = {
	{0, 0},
	{1, 5},
	{2, 10},
	{3, 15},
	{4, 20},
	{5, 25}
};

//DEFINE TRAINING DATA COUNT
#define training_data_count (sizeof(training_data) / sizeof(training_data[0]))

//GENERATE RANDOM FLOAT
float random_float(void)
{
	return (float) rand() / (float) RAND_MAX;
}

//LOSS FUNCTION
float loss_function(float w)
{
	//INITIAL LOSS
	float loss = 0.0f;

	//ITERATE THROUGH TRAINING DATA
	for (size_t i = 0; i < training_data_count; ++i)
	{
		float x = training_data[i][0];
		float y = x * w;
		float error = y - training_data[i][1];
		loss += error*error;
		//printf("True Value: %f, Predicted Value: %f\n", training_data[i][1], y);
	}

	loss /= training_data_count;
	return loss;
}

//ENTRY
int main()
{
	//SEED THE RANDOM NUMBER GENERATOR
	srand(13);

	//BUMP WEIGHT
	float bump = 1e-3;

	//DERIVATIVE RATE
	float rate = 1e-3;

	//GENERATE RANDOM WEIGHT
	float w = random_float() * 10.0f;
	
	//TRAIN
	for (size_t i = 0; i < 500; ++i) 
	{
		float derivate_loss_function = (loss_function(w + bump) - loss_function(w))/bump;
		w -= rate*derivate_loss_function;
	}

	//PREDICTED VALUE
	printf("%f\n", w);

	return 0;
}