#include <stdio.h>

#include "eval.h"

int main (int argc, char** argv) {

    int error = 0;
    char message [20];
    char error_message [100];

    error_message [0] = message [0] = '\0';

    

    char equation [1000];
    //sprintf (equation, "(2 ^ 2) + sin (3x*4 + ln(e))");

    if (argc > 1) sprintf (equation, argv[1]);
    else fgets (equation, 999, stdin);

    //printf (equation);

    Expr* w = parse (equation, &error, message);

    if (!error) printf ("%s\n", to_string (w));
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

    double result = eval (w, 1, &error, message);

    if (!error) printf ("Result: %f\n", result);
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

    return 0;
}