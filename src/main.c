#include <stdio.h>
#include <stdlib.h>
#include <ti/screen.h>
#include <ti/getcsc.h>

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

void get_vsepr_geometry(int electron_groups, int lone_pairs)
{
    os_ClrHome();

    if (electron_groups == 2 && lone_pairs == 0)
    {
        printf("Electron Geometry: linear\n");
        printf("Molecular Geometry: linear\n");
        printf("Bond angle: 180\n");
        printf("Polarity: symmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 3 && lone_pairs == 0)
    {
        printf("Electron Geometry: \ntrigonal planar\n");
        printf("Molecular Geometry: \ntrigonal planar\n");
        printf("Bond angle: 120\n");
        printf("Polarity: symmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 4 && lone_pairs == 0)
    {
        printf("Electron Geometry: \ntetrahedral\n");
        printf("Molecular Geometry:\ntetrahedral\n");
        printf("Bond angle: 109.5\n");
        printf("Polarity: symmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 5 && lone_pairs == 0)
    {
        printf("Electron Geometry: \ntrigonal bipyramidal\n");
        printf("Molecular Geometry: \ntrigonal bipyramidal\n");
        printf("Bond angle: 90/120\n");
        printf("Polarity: symmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 6 && lone_pairs == 0)
    {
        printf("Electron Geometry: \noctohedral\n");
        printf("Molecular Geometry: \noctohedral\n");
        printf("Bond angle: 90\n");
        printf("Polarity: symmetrical\n");

        press_to_exit();
    }
    else
    {
        throw_error();
    }
}

// vsepr function
void vsepr()
{
    char input_1[3];
    char input_2[3];

    os_ClrHome();

    printf("VSEPR\n\n");

    // abstract this portion later
    printf("Atoms bonded to the \n");
    os_GetStringInput("central atom: ", input_1, 3);
    int atoms_bonded = atoi(input_1); // validate values at this layer?
    printf("\n");

    os_GetStringInput("Lone pairs on the central atom: ", input_2, 3);
    int lone_pairs = atoi(input_2); // validate values at this layer?
    printf("\n\n");

    // validate values before adding
    if (atoms_bonded > 6 || atoms_bonded <= 0)
    { 
        throw_error();
        return;
    }
    if (lone_pairs > 3 || lone_pairs < 0)
    {
        throw_error();
        return;
    }

    int electron_groups = atoms_bonded + lone_pairs;

    if (electron_groups > 6 || electron_groups <= 0 )
    {
        throw_error();
        return;
    }

    get_vsepr_geometry(electron_groups, lone_pairs);
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
