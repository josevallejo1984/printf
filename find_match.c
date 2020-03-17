#include "holberton.h"
#include <string.h>
/**
 * find_match - find mathc of src in dest
 *
 */
int print_str(va_list data_string)
{
	/* declaration of all var */
	char *p, c;
	int len_string, i;
	
	/* inicialice all var */
	len_string = 0;
	p = va_arg(data_string, char *);
	
	/* code */
	for (i = 0; *(p + i) != '\0'; ++i)
	{
		c = p[i];
		len_string += write(1, &c, 1);
	}

	return (len_string);
}



int (*find_match(const char *s, int *z))(va_list)
{
	/*Declaring structure*/
	int i;
	int aux;

	aux = (*z + 1);

	/* Declaring structure */
	op_fmt options[] = {
		/* {"i", print_int},
		{"d", print_dec},
		{"c", print_char},
		{"f", print_float}, */
		{"s", print_str},
		/* {"x", print_hexa},
		{"X", print_HEXA},
		{"o", print_octal},
		{"p", print_adress},
		{"u", print_unsigned},
		{"%%", print_porcentage},
		{"r", print_unknow},*/
		{NULL, NULL}
	};

	/*Check NO NULL*/
	while (s != NULL && s[aux] != '\0')
	{
		i = 0; /*Reset variable i*/
		while (i < 2)/*While for evaluate each format*/
		{
			if (s[aux] == options[i].fmt[0])
			{
				aux = (*z + 2);
				return (options[i].p); /*Assign values*/
			}

			else
			{
				aux = (*z + 1);
				return (NULL);
			}

			i++;
		}

	}/*End principal WHILE*/

	return (0);
}
