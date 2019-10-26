#include <stdio.h>
#include <stdlib.h>

struct coor {
	double x;
	double y;
};

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
	
	printf("Enter sides of shape: ");
	scanf("%u", &n);
  
	struct coor coordinates[n];
	struct coor center;
	
  int i = 0;
  while(i < n){
      printf("Enter the coordinates:\n");
      scanf("%lf,%lf", &coordinates[i].x, &coordinates[i].y);
      i++;
  }
	
	center.x = 0;
	center.y = 0;
	
	for(i = 0; i < n; i++){
		center.x += coordinates[i].x;
		center.y += coordinates[i].y;
	
	}
	center.x = center.x/n;
	center.y = center.y/n;

	for(i = 0; i < n; i++){
		area += area_of_triangle(coordinates[i], coordinates[(i + 1) % n], center);
	}
	printf("Area: %lf\n", area);

  return 0;
}











