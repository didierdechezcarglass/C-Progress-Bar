# include "ProgressBar.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>

ProgressBar InitProgressBar(char * name, unsigned long long int duration){
    assert(duration > 0);
    ProgressBar pbar;
    int length = strlen(name);
    if (length > 0){
        // sets the name of the pbar if it has any
        pbar.name = (char *)malloc(length * sizeof(char));
        strcpy(pbar.name, name);
    } else
        pbar.name = NULL;
    pbar.duration = duration;
    pbar.start = 0;
    pbar.current_percentage = 0.0;
    pbar.displayname = 1;
    pbar.displaypercentage = 1;
    pbar.displayratio = 1;
    pbar.totalbars = 10;
    pbar.displaychar = '-';
    return pbar;
}

void TickProgressBar(ProgressBar * pbar){
    pbar->start++;
    pbar->current_percentage = (float) pbar->start / pbar->duration;
}

void SetProgressBarValue(ProgressBar * pbar, unsigned long long int val){
    pbar->start = val;
    pbar->current_percentage = (float) pbar->start / pbar->duration;
}

void SetProgressBarSettings(ProgressBar * pbar, int displayname, int displaypercentage, int displayratio, int totalbars, char displaychar){
    assert(pbar->totalbars > 0);
    pbar->displayname = displayname;
    pbar->displaypercentage = displaypercentage;
    pbar->displayratio = displayratio;
    pbar->totalbars = totalbars;
    pbar->displaychar = displaychar;
}

void DisplayProgressBar(ProgressBar pbar){
    if (pbar.displayname)
        printf("Process %s : ", pbar.name);
    printf("|");
    int bars_to_display = pbar.totalbars * pbar.current_percentage;
    for (int i = 0; i < pbar.totalbars; i++)
        if (i <= bars_to_display)
            printf("%c", pbar.displaychar);
        else 
            printf(" ");
    printf("| ");
    if (pbar.displayratio)
        printf("-> %lld / %lld ", pbar.start, pbar.duration);
    if (pbar.displaypercentage)
        printf("-> (%f%%) ",  100 * pbar.current_percentage);
    fflush(stdout);
    printf("\r");
}

void DestroyProgressBar(ProgressBar pbar){
    free(pbar.name);
}

void CleanPrint(ProgressBar pbar, char * currentprint){
    char buffer[BUFFER_SIZE];
    int current_length = 0;
    if (pbar.displayname){
        sprintf(buffer, "Process : %s", pbar.name);
        current_length += strlen(buffer);
    }
    // the 3 stands for the '|' and "| " present at the end of the print
    current_length += pbar.totalbars + 3;
    if (pbar.displayratio){
        sprintf(buffer, " -> %lld / %lld", pbar.start, pbar.duration);
        current_length += strlen(buffer);
    }
    if (pbar.displaypercentage){
        sprintf(buffer, "-> (%f%%) ",  100 * pbar.current_percentage);
        current_length += strlen(buffer);
    }
    printf("%s", currentprint);
    for (int j = strlen(currentprint); j < current_length; j++){
        printf(" ");
    }
}
