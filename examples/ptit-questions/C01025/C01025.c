#include <stdio.h>
#include <stdint.h>

typedef struct
{
	uint16_t x_ul;
	uint16_t y_ul;
	uint16_t x_tr;
	uint16_t y_tr;
} rectangle_t;

void input_data(rectangle_t *r1, rectangle_t *r2);
uint16_t area_square(rectangle_t *r1, rectangle_t *r2);

int main()
{
	rectangle_t r1, r2;
	input_data(&r1, &r2);

	uint16_t area = area_square(&r1, &r2);
	printf("S = %hd", area);

	return 0;
}

void input_data(rectangle_t *r1, rectangle_t *r2)
{
	printf("Please enter data (x_ul, y_ul, x_tr, y_tr)!\n");
	printf("Rectangle 1: ");
	scanf("%hd %hd %hd %hd", &r1->x_ul, &r1->y_ul, &r1->x_tr, &r1->y_tr);
	printf("Rectangle 2: ");
	scanf("%hd %hd %hd %hd", &r2->x_ul, &r2->y_ul, &r2->x_tr, &r2->y_tr);

	printf("\nData:\n");
	printf("%hd - %hd, %hhd - %hd\n%hd - %hd, %hd - %hd",
		   r1->x_ul, r1->y_ul, r1->x_tr, r1->y_tr,
		   r2->x_ul, r2->y_ul, r2->x_tr, r2->y_tr);

	printf("\n--------------------------------\n\n\n");
}

uint16_t area_square(rectangle_t *r1, rectangle_t *r2)
{
	uint16_t x_min = r1->x_ul < r2->x_ul ? r1->x_ul : r2->x_ul; 
	uint16_t x_max = r1->x_tr > r2->x_tr ? r1->x_tr : r2->x_tr;
	uint16_t y_min = r1->y_ul < r2->y_ul ? r1->y_ul : r2->y_ul;
	uint16_t y_max = r1->y_tr > r2->y_tr ? r1->y_tr : r2->y_tr;

	uint16_t area_1 = (x_max - x_min)*(x_max - x_min);
	uint16_t area_2 = (y_max - y_min)*(y_max - y_min);

	if (area_1 > area_2)
		return area_1;
	else
		return area_2;
}