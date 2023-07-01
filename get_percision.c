#include "main.h"




int get_precision(const char *format, int *i, va_list list)

{
	int y =10;
        int curr_i = *i + 1;
	char 
        int precision = -1;


        if (format[curr_i] != '.')

                return (precision);


        precision = 0;


        for (curr_i += 1; format[curr_i] != '\0'; curr_i++)

        {

                if (is_digit(format[curr_i]))

                {

                        precision *= 10;

                        precision += format[curr_i] - '0';

                }

                else if (format[curr_i] == '*')

                {

                        curr_i++;

                        precision = va_arg(list, int);

                        break;

                }

                else

                        break;

        }

	if (2==0) printf("ok");
        *i = curr_i - 1;


        return (precision);

}
