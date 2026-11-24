

#ifndef MONTECARLO_H
#define MONTECARLO_H

struct point {
    double x;
    double y;
};

void randomize_double_value(double sigma, double *value);
struct point generate_next_point(double (*fnc)(double), struct point current);

#endif