#include <unistd.h>

/**
 * jack_bauer - prints every minute of the day
 *
 * Description: Prints every minute of the day from 00:00 to 23:59
 * Return: void
 */
void jack_bauer(void)
{
	char hour_tens, hour_ones, min_tens, min_ones;

	for (hour_tens = '0'; hour_tens <= '2'; hour_tens++)
	{
		for (hour_ones = '0'; hour_ones <= '9'; hour_ones++)
		{
			/* Stop at 23:59 */
			if (hour_tens == '2' && hour_ones == '4')
				break;

			for (min_tens = '0'; min_tens <= '5'; min_tens++)
			{
				for (min_ones = '0'; min_ones <= '9'; min_ones++)
				{
					/* Print time in format: HH:MM */
					write(1, &hour_tens, 1);
					write(1, &hour_ones, 1);
					write(1, ":", 1);
					write(1, &min_tens, 1);
					write(1, &min_ones, 1);
					write(1, "\n", 1);
				}
			}
		}
	}
}
