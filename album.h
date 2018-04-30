#ifndef ALBUM_H_
#define ALBUM_H_

typedef struct _album album;
typedef struct _array array;



/*returns a pointer to an album if successful or NULL if it fails */
int newAlbum(array * a);
/*Free album a. */
int deleteAlbum(array * a);
/*change the title of album al
Returns 0 if successful and -1 if unsuccessful*/
int editTitle(array *a, char * title);
/*change the artist of album al
Returns 0 if successful and -1 if unsuccessful*/
int editArtist(array *a, char * title);
/*change the year of album al
Returns 0 if successful and -1 if unsuccessful*/
int editYear(array *a, char * title);
/*print the title of album al
Returns 0 if successful and -1 if unsuccessful*/
//int printTitle(array *a, char * title);
/*prints the artist of album al
Returns 0 if successful and -1 if unsuccessful*/
//int printArtist(array *a, char * title);
/*prints the year of album al
returns 0 if successful and -1 if unsuccessful*/
//int printYear(album *al);

album * findAlbum(array *a, char * e);

int edit(array *a);

int userInput(char *i);

int printInfo(array *a);

int printList(array *a);

int printAlbum(array *a,char * title);

int printAlbums(array *a);


int titleCompare(const void *, const void *);

int sort(array *a);

void* sortByTitle(const void *a, const void *b);

int sortByArtist(array *a);

int sortByYear(array *a);

int search(array *a);

int searchArtist(array *a, char *title);


#endif
