#include <stdio.h>
#include <ti/screen.h>
#include <ti/getcsc.h>

#include <vsepr.h>

int menu_selection()
{
    printf("Press 1 for VSEPR\n");
    printf("Press 2 for Molar Mass\n");
    printf("\nPress clear to exit.");

    while (true)
    {
        uint8_t key = os_GetCSC();
        if (key == sk_1)
        {
            return 1;
        }
        if (key == sk_2)
        {
            return 2;
        }

        if (key == sk_Clear)
        {
            return 0;
        }
    }
}

int main()
{
    os_ClrHome();

    printf("Welcome to CHEME!\n\n");
    
    int choice = menu_selection();

    if (choice == 1)
    {
        vsepr();
    }
    if (choice == 2)
    {

    }

    return 0;
}
