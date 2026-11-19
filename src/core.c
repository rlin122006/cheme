#include <stdio.h>
#include <ti/screen.h>
#include <ti/getcsc.h>

#include "core.h"

void press_to_exit()
{
    printf("\nPress clear to exit.");

    while (true)
    {
        uint8_t key = os_GetCSC();

        if (key == sk_Clear)
        {
            return;
        }
    }   
}

void throw_error()
{
    os_ClrHome();

    printf("ERROR THROWN\n");
    press_to_exit();
}
