#include <stdio.h>
#include <stdlib.h>
#include <ti/screen.h>

#include <vsepr.h>
#include <core.h>

void get_vsepr_geometry(int electron_groups, int lone_pairs);

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

    // validate number of atoms bonded
    if (atoms_bonded > 6 || atoms_bonded <= 0)
    { 
        throw_error();
        return;
    }
    // validate lone pairs
    if (lone_pairs > 4 || lone_pairs < 0)
    {
        throw_error();
        return;
    }

    int electron_groups = atoms_bonded + lone_pairs;

    // validate total
    if (electron_groups > 6 || electron_groups <= 0 )
    {
        throw_error();
        return;
    }

    get_vsepr_geometry(electron_groups, lone_pairs);
}

void get_vsepr_geometry(int electron_groups, int lone_pairs)
{
    os_ClrHome();

    if (electron_groups == 1 && lone_pairs == 0)
    {
        printf("Electron Geometry: linear\n");
        printf("Molecular Geometry: linear\n");
        printf("Bond angle: 180\n");
        printf("Polarity: symmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 1 && lone_pairs == 1)
    {
        printf("Electron Geometry: linear\n");
        printf("Molecular Geometry: linear\n");
        printf("Bond angle: 180\n");
        printf("Polarity: symmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 2 && lone_pairs == 0)
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
    else if (electron_groups == 3 && lone_pairs == 1)
    {
        printf("Electron Geometry: bent\n");
        printf("Molecular Geometry: bent\n");
        printf("Bond angle: 119\n");
        printf("Polarity: unsymmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 3 && lone_pairs == 2)
    {
        printf("Electron Geometry: linear\n");
        printf("Molecular Geometry: linear\n");
        printf("Bond angle: 180\n");
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
    else if (electron_groups == 4 && lone_pairs == 1)
    {
        printf("Electron Geometry: \ntrigonal pyramidal\n");
        printf("Molecular Geometry:\trigonal pyramidal\n");
        printf("Bond angle: 107\n");
        printf("Polarity: unsymmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 4 && lone_pairs == 2)
    {
        printf("Electron Geometry: bent\n");
        printf("Molecular Geometry: bent\n");
        printf("Bond angle: 104.5\n");
        printf("Polarity: unsymmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 4 && lone_pairs == 3)
    {
        printf("Electron Geometry: linear\n");
        printf("Molecular Geometry: linear\n");
        printf("Bond angle: 180\n");
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
    else if (electron_groups == 5 && lone_pairs == 1)
    {
        printf("Electron Geometry: seesaw\n");
        printf("Molecular Geometry: seesaw\n");
        printf("Bond angle: 90/120/180\n");
        printf("Polarity: unsymmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 5 && lone_pairs == 2)
    {
        printf("Electron Geometry: \nt-shaped");
        printf("Molecular Geometry: \nt-shaped\n");
        printf("Bond angle: 90/180\n");
        printf("Polarity: unsymmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 5 && lone_pairs == 3)
    {
        printf("Electron Geometry: linear\n");
        printf("Molecular Geometry: linear\n");
        printf("Bond angle: 180\n");
        printf("Polarity: symmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 5 && lone_pairs == 4)
    {
        printf("Electron Geometry: linear\n");
        printf("Molecular Geometry: linear\n");
        printf("Bond angle: 180\n");
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
    else if (electron_groups == 6 && lone_pairs == 1)
    {
        printf("Electron Geometry: \nsquare pyramidal\n");
        printf("Molecular Geometry: \nsquare pyramidal\n");
        printf("Bond angle: < 90\n");
        printf("Polarity: unsymmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 6 && lone_pairs == 2)
    {
        printf("Electron Geometry: \nsquare planar\n");
        printf("Molecular Geometry: \nsquare planar\n");
        printf("Bond angle: 90/180\n");
        printf("Polarity: symmetrical\n");

        press_to_exit();
    }
    else if (electron_groups == 6 && lone_pairs == 3)
    {
        printf("Electron Geometry: \nt-shaped");
        printf("Molecular Geometry: \nt-shaped\n");
        printf("Bond angle: < 90/180\n");
        printf("Polarity: unsymmetrical\n");

        press_to_exit();
    }
    else
    {
        throw_error();
    }
}
