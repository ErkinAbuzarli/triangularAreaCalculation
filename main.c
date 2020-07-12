#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Below, x and y are defined as coordinates.
struct coor {
	double x;
	double y;
};

double area_of_triangle(struct coor n1 ,struct coor n2, struct coor n3);
void drawShape(struct coor coordinates[], int n);

void swap(struct coor *xp, struct coor *yp);
void sortY(struct coor coordinates[], int n);

int maxX(struct coor coordinates[], int n);
int minX(struct coor coordinates[], int n);

// This is an equation of triangle which is given with coordinates. 
// Funktion is [Area = (x1 * y2) + (x2 * y3) + (x3 * y1) - (x2 * y1) - (x3 * y2) - (x1 * y3)]
double area_of_triangle(struct coor n1 ,struct coor n2, struct coor n3){
	double h = (n1.x) * (n2.y) + (n2.x) * (n3.y) + (n3.x) * (n1.y) - (n2.x) * (n1.y) - (n3.x) * (n2.y) - (n1.x) * (n3.y);
 	h = (h < 0) ? (-1 * h) : (h);
 	h /= 2;
	return h;
}

// For swapping elements position in array.
void swap(struct coor *xp, struct coor *yp){
    struct coor temp;
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// This function sort array with Selection sort algorithm.
void sortY(struct coor coordinates[], int n){
    int min;

    for(int i = 0; i < n-1; i++){

        min = i;
        for(int j = i+1; j < n; j++){
            if (coordinates[j].y > coordinates[min].y){
                min = j;
            }
        }
        swap(&coordinates[min], &coordinates[i]);
    }
}

// Find out biggest number in x axis. 
int maxX(struct coor coordinates[], int n){
    int max = -100000;

    for(int i = 0; i < n; i++)
        max = (coordinates[i].x > max) ? coordinates[i].x : max;

    return max;
}

// Find out smallest number in x axis. 
int minX(struct coor coordinates[], int n){
    int min = 100000;

    for(int i = 0; i < n; i++)
        min = (coordinates[i].x < min) ? coordinates[i].x : min;

    return min;
}

// This function draw shape fundamentally input coordinates.
void drawShape(struct coor coordinates[], int n){
	
    struct coor coordinates_orginal[n];
    int is_a_point = 0;
    
    // Copy coordinates for usage again.
    for (int i = 0; i < n; i++){
        coordinates_orginal[i] = coordinates[i];
    }

    sortY(coordinates, n);      // Sorting.

    // Changing double numbers to integer for loop.
    int maximum_y = coordinates[0].y;   
    int minimum_y = coordinates[n].y;

    printf("\n\nShape like that:\n\n\n");

    // Control every y axis from min to max. 
    for(int i = maximum_y; i >= minimum_y; i--){
            
        printf("\t\t");
        
        // Control every x axis from min to max. 
        for(int j = minX(coordinates, n); j <= maxX(coordinates, n); j++){
            // Control every coordinate, if there are any coordinate print "."
            for(int k = 0; k < n; k++){
                if (j == coordinates_orginal[k].x && i == coordinates_orginal[k].y){
                    printf(".");
                    is_a_point = 1;
                }
            }
            // If point exist don't put anything else print space
            is_a_point == 1 ? printf("") : printf("  ");
            is_a_point = 0;
        }
        printf("\n");
    }
}

int main(){
  	unsigned int n;
	double area = 0;
	double perimetr = 0;

	// Sides of shape data is gotten from user.
	printf("Enter how many sides of shape: ");
	scanf("%u", &n);
  
	struct coor coordinates[n];
	struct coor center;
	
// And we get coordinates of this shape.
	int i = 0;
	
	while(i < n){
 		printf("Enter the coordinates:\n");
		scanf("%lf,%lf", &coordinates[i].x, &coordinates[i].y);
  		i++;
	}

// Perimeter is found in there.
	for(i = 0; i < n; i++){
		perimetr += sqrt(((coordinates[i+1].x - coordinates[i].x) * (coordinates[i+1].x - coordinates[i].x)) + 
				((coordinates[i+1].y - coordinates[i].y) * (coordinates[i+1].y - coordinates[i].y)));
	}
	printf("\nPerimetr: %.2f \n", perimetr);


// Variables.
	center.x = 0;
	center.y = 0;

// Below, the center of gravity is found.
	for(i = 0; i < n; i++){
		center.x += coordinates[i].x;
		center.y += coordinates[i].y;
	}

	center.x = center.x/n;
	center.y = center.y/n;

// And calculate the area of shape.
	for(i = 0; i < n; i++){
		area += area_of_triangle(coordinates[i], coordinates[(i + 1) % n], center);
	}
	
	printf("Area: %.2lf\n\n", area);
  
// Variables 
	double a = 0;
	double b = 0;
	double c = 0;
  	double alfa = 0;
  	double cosine = 0;
	double angle1 = 0;
	int angle = 0;

// Calculate of the angles is started. 
// Cosine Law is used in there.
	
	for(i = 1; i < n+1; i++){
	  
		// Lengths of sides are calculated with coordinates.
		a = sqrt(((coordinates[i-1].x - coordinates[i % n].x) * (coordinates[i-1].x - coordinates[i % n].x)) + 
			      ((coordinates[i-1].y - coordinates[i % n].y) * (coordinates[i-1].y - coordinates[i % n].y)));

		b = sqrt(((coordinates[(i+1) % n].x - coordinates[i % n].x) * (coordinates[(i+1) % n].x - coordinates[i % n].x)) + 
						((coordinates[(i+1) % n].y - coordinates[i % n].y) * (coordinates[(i+1) % n].y - coordinates[i % n].y)));

		c = sqrt(((coordinates[(i+1) % n].x - coordinates[i-1].x) * (coordinates[(i+1) % n].x - coordinates[i-1].x)) + 
						((coordinates[(i+1) % n].y - coordinates[i-1].y) * (coordinates[(i+1) % n].y - coordinates[i-1].y)));
				
		cosine = (((c * c) - (b * b) - (a * a)) / ((-2) * b * a));
		alfa = acos(cosine);
		
		// Radian is changed to degree.
		angle = ((alfa * 180) / 3.14159265359);
		angle1 = ((alfa * 180) / 3.14159265359);
		
		angle1 > (angle + 0.5) ? (angle + 1.0) : angle;
		
		printf("The %d . angle is %.2f \n", i, angle1);
	}
	
	drawShape(coordinates, n); 		// Print Shape
	
	return 0;
}
