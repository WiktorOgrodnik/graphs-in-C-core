#include <stdio.h>
#include <unistd.h>

#include "eval.h"

int main (int argc, char** argv) {

    int error = 0;
    char message [20];
    char error_message [100];
    char equation [1000];
    char fileName [100];
    error_message [0] = message [0] = '\0';

    int opt;

    bool gflag = false, eflag = false, fflag = false, pflag = false;
    int measurements = 400, interval = 10;

    FILE* file;

    while ((opt = getopt (argc, argv, "e:gm:i:f:hp")) != -1) {
        if (opt == 'g') gflag = true;
        else if (opt == 'e') {
            eflag = true;
            sprintf (equation, optarg);
        }
        else if (opt == 'm') measurements = atoi (optarg);
        else if (opt == 'i') interval = atoi (optarg);
        else if (opt == 'f') {
            fflag = true;
            sprintf (fileName, optarg);
        }
        else if (opt == 'p') pflag = true;
        else if (opt == 'h') {
            printf ("Usage: math [options] [target] ...\n");
            printf ("Options:\n");
            printf ("-e STRING           Load equation.\n");
            printf ("-g                  Graph mode.\n");
            printf ("-m NUMBER           Number of measurements.\n");
            printf ("-i NUMBER           Interval (from -n to n).\n");
            printf ("-f STRING           File to write result.\n");
            printf ("-p                  Print parsed expression.\n");
            printf ("-h                  Help menu.\n");

            return 0;
        }
    }

    if (!eflag) fgets (equation, 999, stdin);

    if (fflag) file = fopen(fileName, "w");
    
    Expr* w = parse (equation, &error, message);

    if (!error && pflag) {
        if (fflag) fprintf (file, "%s\n", to_string (w));
        else printf ("%s\n", to_string (w));

        return 0;
    }
    else if (error) {
        switch (error)
                {
                    case 1:
                        sprintf (error_message, "PARSE ERROR: Can not find: %s", message);
                    break;
                    case 2:
                        sprintf (error_message, "PARSE ERROR: expected number or '(', or '|', or '{', or '['");
                    break;
                    case 3:
                        sprintf (error_message, "PARSE ERROR: Incorrect parenthesis, expected: '%s'", message);
                    break;
                    case 4:
                        sprintf (error_message, "RUNTIME ERROR: Critical error, can not allocate memory!");
                    break;
                    case 5: 
                        sprintf (error_message, "PARSE ERROR: Empty string!");
                    break;
                    default:
                        sprintf (error_message, "PARSE ERROR: Unknown error!");
                    break;
                }
        printf ("%s\n", error_message);
        return EXIT_FAILURE;  
    }

    error = 0;
    error_message [0] = message [0] = '\0';

    if (!gflag) {

        double result = eval (w, 1, &error, message);

        if (!error) 
            if (fflag) fprintf (file, "Result: %f\n", result);
            else printf ("Result: %f\n", result);
        else {
            switch (error)
                    {
                        case 1:
                            sprintf (error_message, "EVAL ERROR: Invalid equation node! Node id: %s", message);
                        break;
                        case 2:
                            sprintf (error_message, "EVAL ERROR: Not a number!");
                        break;
                        case 3:
                            sprintf (error_message, "EVAL ERROR: Can not divide by zero!");
                        break;
                        case 4:
                            sprintf (error_message, "EVAL ERROR: Can not raise 0 to the 0 power!");
                        break;
                        default:
                            sprintf (error_message, "EVAL ERROR: Unknown error!");
                        break;
                    }

            printf ("%s\n", error_message);
            return EXIT_FAILURE;
        }
    } else {

        double l = (double) -interval;
        double delta = (2.0 * (double) interval) / (double) measurements;
        
        for (int i = 0; i < measurements; i++) {
            double res = eval (w, l, &error, message);

            if (!error) 
                if (fflag) fprintf (file, "%d %f %f\n", i, l, res);
                else printf ("%d %f %f\n", i, l, res);
            else {
                error = 0;
                if (fflag) fprintf (file, "%d %f\n", i, l);
                else printf ("%d %f\n", i, l);
            }

            l += delta;
        }
    }

    if (fflag) fclose (file);

    return 0;
}