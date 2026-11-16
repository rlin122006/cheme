#include <stdio.h>
#include <stdlib.h>
#include <ti/screen.h>
#include <ti/getcsc.h>

// vsepr function
void vsepr()
{
    char input_1[3];
    char input_2[3];

    os_ClrHome();

    printf("VSEPR\n\n");

    printf("Atoms bonded to the \n");
    os_GetStringInput("central atom: ", input_1, 3);
    int atoms_bonded = atoi(input_1);
    printf("\n");

    os_GetStringInput("Lone pairs on the central atom: ", input_2, 3);
    int lone_pairs = atoi(input_2);
    printf("\n");
}

// prompt for what function
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
