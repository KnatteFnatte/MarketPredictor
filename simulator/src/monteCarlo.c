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

 int main(int argc, char *argv[]) {
    FILE *fp;
    char *end;
    int num_points = 1000;
    float sigma = 0.1;

    if (argc < 2) {
        fprintf(stderr, "Error in program usage: monteCarlo outfile");
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-h") == 0) {
        fprintf(stdout, "Usage of the program: monteCarlo outfile\n"
                        "potential arguments:\n"
                        "\t-n num_points; sets the number of points to be generated.\n"
                        "\t-f function; sets the function bias for the monte carlo generation - use x notation and one-dimensional functions.\n"
                        "\t-r sigma; sets the random variation bias for the monte carlo generation"); return 0;
    }

    for (int i = 2; i < argc; i += 2) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'n':   num_points = (int) strtol(argv[i+1], &end, 10); break;
                case 'f': break; //Function algorithm still to be implemented.
                case 'r': sigma = (float) strtof(argv[i+1], &end); break;
            }
        }
    }

    if ((fp = fopen(argv[1], "w")) == NULL) {
        fprintf(stderr, "Error opening outfile %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("num_points: %d\nsigma: %f", num_points, sigma);

    return 0;
 }