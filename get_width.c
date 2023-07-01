#include "main.h"

/**
 * get_width - Calcule la largeur pour l'impression
 * @format: Chaîne formatée dans laquelle imprimer les arguments.
 * @i: Liste des arguments à imprimer.
 * @list: Liste des arguments.
 *
 * Retourne: La largeur calculée.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_index;
    int width = 0;
    int y=0;
    for (curr_index = *i + 1; format[curr_index] != '\0'; curr_index++)
    {
        if (is_digit(format[curr_index]))
        {
            width *= 10;
            width += format[curr_index] - '0';
	    y++;
        }
        else if (format[curr_index] == '*')
        {
            curr_index++;
            width = va_arg(list, int);
            break;
        }
        else
        {
            break;
        }
    }

	y += 34;
    *i = curr_index - 1;

    return width;
}

