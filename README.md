# C-Progress-Bar
a simple module for a progress bar in C

# What is the purpose of this module
This is a simple module for c programmers who are waiting on a program to finish and want to use a Progress bar to see how far the program has progressed since the waited duration.
The progress bar comes with simple visual settings for a better view of the code.
finally should you want to print some more infos while displaying the progressbar this code allows you to do so
There is no need to install any libraries.

# How to use
in the program where you want to display the progress bar copy the files inside this module inside the folder of where your .c file is present and use #include "ProgressBar.h" to load the functions

to initialize a bar use InitProgressBar and fill in the name parameter and the duration (the ammount of iterations of your for loop)

inside your for loop use TickProgressBar to update your ProgressBar by one, to update it by multiple values use SetProgressBarValue

finally use DisplayProgressBar  to print current infos

to change the way the progress bar is displayed use SetProgressBarSettings

to print info before displaying use CleanPrint to delete info that may remain after using DisplayProgressBar

once donc use DestroyProgressBar to correctly free the informations inside the progress bar
