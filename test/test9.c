#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car
{
int year;
char model[10];
char plate[7];
int odometer;
double engine_size;
};

int main(void)
{
    struct car mycar;
// field accessing
mycar.year = 2011;
// strcpy(mycar.plate, "CS50");
mycar.plate = "HI";
mycar.odometer = 50505;

printf("%s\n", mycar.plate);
}
