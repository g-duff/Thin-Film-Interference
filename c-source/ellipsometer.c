#include<stdio.h>
#include<math.h>

static float DEGREES = M_PI/180;

int main(){
	const int NUMBER_OF_LAYERS = 4;
	const int NUMBER_OF_FINITE_LAYERS = NUMBER_OF_LAYERS - 2;

	const float LAYER_THICKNESSES[NUMBER_OF_FINITE_LAYERS] = {220, 3000};
	const float LAYER_REFRACTIVE_INDICES[NUMBER_OF_LAYERS] = {1.0, 3.8, 1.45, 3.8};
	
	float incidentAngle = 65*DEGREES;
	float rayAngles[NUMBER_OF_LAYERS];

	// Calculate transmission angles
	rayAngles[0] = incidentAngle;
	float currentAngle, previousRefractiveIndex, nextRefractiveIndex, sinOfTransmissionAngle;
	for (int i=1; i<NUMBER_OF_LAYERS;i++) {
		currentAngle = rayAngles[i-1];
		previousRefractiveIndex = LAYER_REFRACTIVE_INDICES[i-1];
		nextRefractiveIndex = LAYER_REFRACTIVE_INDICES[i];
		
		sinOfTransmissionAngle = sin(currentAngle) * previousRefractiveIndex / nextRefractiveIndex;
		rayAngles[i] = asin(sinOfTransmissionAngle);
	}
}
