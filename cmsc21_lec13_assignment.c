#include <stdio.h>
#include <math.h>

struct line
{
    struct point
    {
		float x;
		float y;
	} point1, point2;
	float *midpoint;
	float slope;
	float distance;
};

float solveSlope(struct line line1);
float *solveMidpoint(struct line line1);
float solveDistance(struct line line1);
void getSlopeInterceptForm(struct line line1);

int main() // main function
{
	struct line line1;

	printf("Enter the x and y for point1: ");         // ask the user to enter x and y point 1
	scanf("%f %f", &line1.point1.x, &line1.point1.y); // takes an input from the user

	printf("Enter the x and y for point2: ");         // ask the user to enter x and y point 2
	scanf("%f %f", &line1.point2.x, &line1.point2.y); // takes an input from the user

	printf("\nSlope: %f", solveSlope(line1));         // print the expected output of slope
    
    solveMidpoint(line1);                             // call the solveMidpoint function
    printf("\nMidpoints: %f, %f", line1.midpoint[0], line1.midpoint[1]); // print the expected output of midpoints
	
	printf("\nDistance between 2 points: %f", solveDistance(line1));   // print the expected output of distance
	getSlopeInterceptForm(line1);                     // call the getSlopeInterceptForm function

	return 0;
}

float solveSlope(struct line line1){ // solve for slope
        
    line1.slope = ((line1.point1.y - line1.point2.y) / (line1.point1.x - line1.point2.x)); // formula to get the slope
    
    return line1.slope; // return line1.slope

    // x1 = x2
    // x2 - x1 == 0
}

float *solveMidpoint(struct line line1){  // solve for midpoint

	line1.midpoint[2]; // number of midpoints

	line1.midpoint[0] = ((line1.point1.x + line1.point2.x)/2);  // formula to get the midpoints
	line1.midpoint[1] = ((line1.point1.y + line1.point2.y)/2);

	return line1.midpoint; // return line1.midpoint

}

float solveDistance(struct line line1){ // solve for distance

	line1.distance = sqrt(((line1.point1.x - line1.point2.x)*(line1.point1.x - line1.point2.x)) + ((line1.point1.y - line1.point2.y)*(line1.point1.y - line1.point2.y)));  // formula to get the distance

	return line1.distance; // return line.distance
}

void getSlopeInterceptForm(struct line line1){ //get the slope intercept form

		float slope = line1.slope;
	    float interceptb = line1.point1.y - (slope * line1.point1.x); // solve for y-intercept
 
		printf("\ny = %fx + %f", slope, interceptb);

		
}