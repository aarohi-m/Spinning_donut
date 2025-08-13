#include <stdio.h>
#include <string.h>
#include <math.h>
int k; //loop counter



int main()
{
    float A = 0,B = 0, i, j, z[1760]; //zbuffer
    char b[1760]; //framebuffer
   
    printf("\x1b[?25l"); //hides cursor in hexadecimal 
    for(;;)
    {
        //memset sets memory to a character?
        memset(b, 32, 1760); //1760 total size, 32 is set which is equivalent of space
        memset(z, 0,7040);// 7040 is memory n 1760 is size of screen for z
        for( j = 0; 6.28 > j; j += 0.04) //angle of rotation  y axis , 2pi is 6.28 and 0.04 is the taken speed
        {
            for( i = 0; 6.38 > i; i += 0.05) //angle of rotation x axis
            {
                float c = sin(i), d= cos(j), e = sin(A), f = sin(j), g = cos(A),
                      h = d + 2, D = 1/ (c * h * e + f * g + 5), l = cos(i),
                      m = cos(B), n = sin(B),
                      t = c * h * g - f * e;
                int x = 48 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m), o = x + 80 * y,
                    N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if(22 > y && y > 0 && 80 > x && x > 0 &&  D > z[o]) //checks if its within screen
                {
                    z[o] = D;
                    b[o] = " .,-~:;=!*#$@:"[N > 0 ? N : 0];
                }
            }
         
        }
           printf("\x1b[H");
            for(k = 0; 1761 > k; k++)
            putchar(k % 80 ? b[k] : 10);
            A += 0.04;
            B += 0.02;
    }
}