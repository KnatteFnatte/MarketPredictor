/******************************************************************************************************************************************************************************************
 * This is the main program for the simulation of the market evaluation.                                                                                                                  *
 *                                                                                                                                                                                        *
 * The program produces a csv output file which has the format                                                                                                                            *
 * t, v\n                                                                                                                                                                                 *
 * where t is the timestamp and v is the value at the market at the given time.                                                                                                           *
 *                                                                                                                                                                                        *
 * The model is implemented using a bias function, provided via the command line argument.                                                                                                *
 * The bias function is used to generate points with forward-euler and stochastic variation sigma around the new point, sigma being a scalar float provided by the command line argument. *
 *                                                                                                                                                                                        *
 * The usage of the program is:                                                                                                                                                           *
 * monteCarlo outfile -n num_points -f function_bias(one-dimensional x-notation) -r random_scaling(float)                                                                                    *
 ******************************************************************************************************************************************************************************************/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
 #include <limits.h>
 #include "monteCarlo.h"

 int main(int argc, char *argv[]) {
    FILE *fp;
    char *end, out_filename[_MAX_FNAME] = "out.csv";
    int num_points = 1000;
    float sigma = 0.1;
    float dt = 1.0;
    srand((unsigned int) time(NULL));

    if (argc > 1) {
    if (strcmp(argv[1], "-h") == 0) {
        fprintf(stdout, "Usage of the program: monteCarlo outfile\n"
                        "potential arguments:\n"
                        "\t-n num_points; sets the number of points to be generated.\n"
                        "\t-f function; sets the function bias for the monte carlo generation - use x notation and one-dimensional functions.\n"
                        "\t-o output_name; sets the name of the output file. Default: out.csv"
                        "\t-r sigma; sets the random variation bias for the monte carlo generation"); return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'n':   num_points = (int) strtol(argv[++i], &end, 10); break;
                case 'f': break; //Function algorithm still to be implemented.
                case 'r': sigma = (float) strtof(argv[++i], &end); break;
                case 'o': strcpy(out_filename, argv[++i]); break;
                case 'd':   if (strcmp(&argv[i][1], "dt") == 0) {
                                dt = strtof(argv[++i], &end);
                                break;
                            } 
                default: printf("Argument %s not parsed correctly.\n", argv[i]);
            }
        }
    }

    if ((fp = fopen(out_filename, "w")) == NULL) {
        fprintf(stderr, "Error opening outfile %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    }



    printf("num_points: %d\nsigma: %f\nout_filename: %s\ndt: %f\n", num_points, sigma, out_filename, dt);

    return 0;
 }

 void randomize_double_value(double sigma, double *value) {
    //Create a random number between -1 and 1:
    int rng = rand();
    *value += ((((double) rng) / RAND_MAX)*2.0-1.0)*sigma;
    return;
 }