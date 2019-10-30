#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Below, x and y are defined as coordinates.
struct coor {
	double x;
	double y;
};

// This is an equation of triangle which is given with coordinates. 
// Funktion is [Area = (x1 * y2) + (x2 * y3) + (x3 * y1) - (x2 * y1) - (x3 * y2) - (x1 * y3)]
double area_of_triangle(struct coor n1 ,struct coor n2, struct coor n3)
{
  double h = (n1.x) * (n2.y) + (n2.x) * (n3.y) + (n3.x) * (n1.y) - (n2.x) * (n1.y) - (n3.x) * (n2.y) - (n1.x) * (n3.y);
  h = (h < 0) ? (-1 * h) : (h);
  h /= 2;
  return h;
}

int main()
{
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
	printf("\nPerimetr: %f \n", perimetr);


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
	printf("Area: %lf\n\n", area);
  
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
		
		printf("The %d . angle is %f . \n", i, angle1);
	}
  return 0;
}