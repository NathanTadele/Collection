#include <stdio.h>
#include "album.h"
#include "array.h"
#include "saveAlbum.h"

char * filename = ".albumsSaved.txt";

FILE *albumFile;


void printAlbums() {
    // open albumsSaved.txt
    albumFile = fopen(fileName, "r");
    // increment through scores array and take name of player and their score
    for (unsigned i = 0; i < a->inUse; i++) {
        fscanf(albumFile, "%s", albums[i].title);
        fscanf(albumFile, "%s", &scores[i].artist);
        fscanf(albumFile, "%d", &scores[i].year);
    }
    // must close file after
    fclose(albumFile);

    // increment through scores array and print the names of the player
    // and their time formatted from seconds to minute second
    printf("Created Albums\n");
    int j = 0;
    for (unsigned i = 0; i < a->inUse; i++) {
        printf("%d. title:%s ",j+1 , albums[i].title);
        printf("    artist:%s ", albums[i].artist);
        printf("    year:%d ",albums[i].year);
        j++;
    }
}
