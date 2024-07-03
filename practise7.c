#include <stdio.h>
#include <math.h>
int main() {
    double x1, y1, r1, x2, y2, r2;
    printf("Введіть координати центру першого кола (x1, y1) та його радіус (r1): ");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    printf("Введіть координати центру другого кола (x2, y2) та його радіус (r2): ");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    
    //обчислення к-сті точок перетину
    int result = countIntersectionPoints(x1, y1, r1, x2, y2, r2);
    if (result == -1) {
        printf("Кількість точок перетину: безкінечно багато\n");
    } else {
        printf("Кількість точок перетину: %d\n", result);
    }
    return 0;
}
//обчислення к-сті точок перетину двох кіл
int countIntersectionPoints(double x1, double y1, double r1, double x2, double y2, double r2) {
    //відстань між центрами кіл
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    //центри співпадають
    if (d == 0) {
        if (r1 == r2) {
            //багато точок перетину
            return -1;
        } else {
            //не перетинаються
            return 0;
        }
    }
    //відстань > суми радіусів або < їх -
    if (d > r1 + r2 || d < fabs(r1 - r2)) {
        return 0; // Кола не перетинаються
    }
    //відстань дорівнює + радіусів або -
    if (d == r1 + r2 || d == fabs(r1 - r2)) {
        return 1; 
    }
    //кола перетинаються у двох точках
    return 2;
}