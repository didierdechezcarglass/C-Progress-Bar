# ifndef PROGRESSBAR_H
# define PROGRESSBAR_H
# define BUFFER_SIZE 500

typedef struct pbar{
    char * name;
    unsigned long long int duration;
    unsigned long long int start;
    float current_percentage;
    int displayname;
    int displaypercentage;
    int displayratio;
    int totalbars;
    char displaychar;
} ProgressBar;

/**
 * @brief initialises the progress bar
 * 
 * @param name the name of the progressbar, leave empty for no name
 * @param duration the ammount of iterations
 * @return ProgressBar (makes an error if duration is <= 0)
 */
ProgressBar InitProgressBar(char * name, unsigned long long int duration);

/**
 * @brief ticks the progress bar (adds +1 to it's current duration) and updates it's current percentage
 * 
 * 
 */
void TickProgressBar(ProgressBar * pbar);

/**
 * @brief Sets the Progress Bar to a specific value
 * 
 * @return void 
 */
void SetProgressBarValue(ProgressBar * pbar, unsigned long long int val);

/**
 * @brief Sets the progress to the available settings
 * 
 * @param pbar the progress bar
 * @param displayname will not show the bar's name if this variable is set to 0, will show it if set to anything else
 * @param displaypercentage will not show the bar's current percentage if this variable is set to 0, will show it if set to anything else
 * @param displayratio will not show the bar's current ratio if this variable is set to 0, will show if it is set to anything else
 * @param totalbars the total ammount of bars the progress bar should show, will make an error if set to a value that is <= 0
 * @param displaychar the character to use to print the bar, default is '-'
 */
void SetProgressBarSettings(ProgressBar * pbar, int displayname, int displaypercentage, int displayratio, int totalbars, char displaychar);

/**
 * @brief display the progress bar
 * 
 */
void DisplayProgressBar(ProgressBar pbar);

/**
 * @brief free's the malloc'd parts of the ProgressBar in InitProgressBar
 * 
 */
void DestroyProgressBar(ProgressBar pbar);

/**
 * @brief prints to the terminal an object and makes sure to clear what was drawn before.
 * 
 * @param pbar the progress bar
 * @param currentprint the thing you want to print
 */
void CleanPrint(ProgressBar pbar, char * currentprint);

# endif