/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

Code added by Shivali 9/16/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};

void find_track_regex(char pattern[])
{
    regex_t rt;
    if (regcomp(&re, pattern, REG_EXTENDED|REG_ICASE) != 0) //Only returns if case is correct
		return  0;
	int rf = regcomp(&re, pattern, REG_EXTENDED|REG_ICASE);
	char buf[80]; //buffer character array
	if (rf != 0) { //print error if any
		regerror(rf, &rt, buf, 80);
		printf("recomp failure: '%s'\n", buf);
		exit(EXIT_FAILURE);
	}
	int i;
	for (i = 0; i < NUM_TRACKS; i++) { //print tracks
		int state = regexec(&rt, tracks[i], (size_t) 0, NULL, 0);
	}
}

/*void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
		if (strstr(tracks[i], search_for)) {
			printf("Track %i: '%s'\n", i, tracks[i]);
		}
    }
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
		*ptr = '\0';
    }
}*/

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    //rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}


