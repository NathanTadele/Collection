#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "album.h"
#include "array.h"

  struct _array{
    size_t capacity;//how much space is in the collection array
    size_t inUse;//how much space is being used in the collection array
    void ** data;//data that is in each element of the collection array
  };

  struct _album{
    char title[50];
    char artist[50];
    int year;
  };


int newAlbum(array *a) {
  if(!a) return -1;//gives error if the array is null
  int err;
  album * al;
  al = malloc(sizeof(album));//allocates memory for an album
  char title[50];
  char artist[50];
  int year;
  printf("What is the title of the album?\n");
  while (userInput(title));//lets the user input an album name
  printf("Who is the artist?\n");
  while (userInput(artist));//  lets user input artist for an album
  printf("What year was this album released?\n");
  scanf("%d", &year);// lets user input year that an album was released
  strcpy(al->title, title);// stores what they typed in title in the album struct
  strcpy(al->artist, artist);//stores what they typed in artist in the album struct
  al->year = year;//stores what they typed in year in the album struct
  err = arrayPushBack(a, (void*) al);//puts the album struct into the array struct
  arrayPut(a, sizeof(album), (void*) al);
  if (err) return -1;
return 0;
}


int userInput(char *input){
  fgets(input, sizeof(input),stdin);
  if (*input == ' '|| input[1] == '\0'){
    // printf("error\n");
    return 1;
  }
  return 0;
}
/*
int userInput(char * destination){//this code was written because scanf stops after it encounters a space and we needed to combat that
  int i = 0;
  while(scanf("%c", destination) != '\n'){
    i++;
    if(i >= 48){
      printf("Exceeded character limit: Note that some characters have been cut off.\n");
      break;
  }
  }
destination[i] = '\0';
  return 0;
}
*/
//have some way for the user

album * findAlbum(array *a, char * title){
  if(!a || !title) return NULL;
  album *al = NULL;
  int err;
  for(unsigned i = 0; i <= a->inUse; i++){
    arrayGet(a, i, (void **) al);
    err = strcmp(title, al->title);
    if(err == 0){
      return al;
    }
  }
  printf("Error: album you have searched for does not currently exist.\n");
  return NULL;
}

int search(array *a){
  if(!a) return -1;
  char e[50];
  printf("Which artist would you like to search for?\n");
  while (userInput(e));
  printf("Input: %s\n", e);
  searchArtist(a,e);
  return 0;
}

int searchArtist(array * a, char * artist){
  if(!a || !artist) return -1;
  album *al = NULL;
  int err;
  for (unsigned i = 0; i < a->inUse; i++){
    arrayGet(a, i, (void **) al);
    err = strcmp(artist, al->artist);
    if(err == 0){
      printf("%s\n", al->title);
    }
  }
  return 0;
}

album * findArtist(array * a, char * artist){
  if(!a || !artist) return NULL;
  album *al = NULL;
  int err;
  for (unsigned i = 0; i <= a->capacity -1; i++){
    arrayGet(a, i, (void**)al);
    err = strcmp(artist, al->artist);
    if(err == 0){

    }
  }
  return NULL;
}



int deleteAlbum(array *a){
  if(!a) return -1;//checks for null pointers
  album *al = NULL;
  char e[50];
  int err;
  printf("Which album do you want to delete?\n");
  while(userInput(e));
  for(unsigned i = 0; i <= a->inUse; i++){
    arrayGet(a, i, (void**) al);//gets information from each album in the array struct
    err = strcmp(e,al->title);// finds an album title that directly matches the title that the user netered in
    if(err == 0){
      free(a[i].data);//deletes the album the user entered in
      return 0;
    }
}
return -1;
}
/*
int editTitle(album *al, char * title){
  if (!al || !title) return -1;//checks if NULL
  char newtitle[50];
  printf("What is the new title?\n");
  userInput(newtitle);
  strcpy(al->title, newtitle);
  return 0;
}
*/

int edit(array *a){
  printf("What would you like to edit?\n");
  printf("1. Title\n");
  printf("2. Artist\n");
  printf("3. Year\n");
  int option2;
  char e[50];
  scanf("%d/n", &option2);
  if (option2 == 1){
    printf("Enter the title of the album you want to edit.\n");
    while (userInput(e));
    editTitle(a,e);
  }
  if(option2 == 2){
    printf("Enter the title of the album you want to edit.\n");
    while (userInput(e));
    editArtist(a,e);
  }
  if(option2 == 3){
    printf("Enter the title of the album you want to edit.\n");
    while (userInput(e));
    editYear(a,e);
  }
return 0;
}
/*  switch(option2){
    case 1: printf("Enter what title you want to edit\n");
              userInput(e);
              editTitle(a, e);
    case 2: printf("What is the title of the album\n");
              userInput(e);
              editArtist(a,e);
    case 3: printf("What is the title of the album\n");
              userInput(e);
              editYear(a, e);

  }
return 0;
}
*/

void printString(void const * e){
  char * music = (char *) e;
  printf("%s\n", music);
}

int printInfo(array *a){
  printf("What would you like to print?\n");
  printf("1. Details of a specific album\n");
  printf("2. Full list of albums\n");
  int option3;
  char e[50];
  scanf("%d/n", &option3);
  if (option3 == 1){
    printf("Enter the album you want to see.\n");
    while(userInput(e));
    printAlbum(a,e);
  }
  if (option3 == 2) printArray(a, printString);
return 0;
}




  /*switch (option3) {
    case 1 :printf("Enter what album you want to see the details of\n");
              userInput(e);
              printAlbum(a, e);
    case 2 :printList(a);
  }
  return 0;
}

int printList(array *a){
  if (!a) return -1;
  album *al = NULL;
  //int err;
  for (unsigned i = 0; i <= a-> inUse; i++){

    printf("%s\n", al[i].title);
  }
  return 0;
}
*/

/*
int editTitle(array * a, char * title){
  if (!a || !title) return -1;//checks if NULL
  album *al;
  char newtitle[50];
  int err;
  for(int i = 0; i <= a->capacity -1; i++){
    arrayGet(a, i, &al);
    err = strcmp(title, al->title);
    if(err == 0){
      break;
    }
  }
  printf("What is the new title?\n");
  userInput(newtitle);
  strcpy(al->title, newtitle);
  return 0;
}

*/



int printAlbum(array *a, char *title){
  if(!a) return -1;
  album *al = NULL;
  int err;
  for(unsigned i = 0; i <= a->inUse; i++){
  arrayGet(a, i, (void**) al);
  err = strcmp(title, al->title);
  if(err == 0){
    break;
  }
  }
  printf("%s\n", al->title);
  printf("%s\n", al->artist);
  printf("%d\n", al->year);
  return 0;
}



/*

int printAlbums(array *a){
  if(!a) return -1;
  for(int i = 0; i <= a->inUse; i++){
      printf("%s\n", a->data[i]->title);
  }
return 0;
}

*/

int printTitle(array *a, char * title){
  if(!a || !title) return -1;
  album *al = NULL;
  int err;
  for(unsigned i = 0; i < a->inUse; i++){
    arrayGet(a, i, (void**) al);
    err = strcmp(title,al->title);
    if(err == 0){
      break;
      }
    else
        return -1;
  }
  printf("%s\n", title);
return 0;
}


int editArtist(array * a, char * title){
  if (!a || !title) return -1;
  album *al = NULL;
  char newartist [50];
  int err;
  for (unsigned i = 0; i <= a->inUse; i++){
    arrayGet(a, i, (void**) al);
    err = strcmp(title, al->title);
    if(err == 0){
      break;
    }
  }
  printf("Enter new artist\n");
  userInput(newartist);
  strcpy(al->artist, newartist);
  return 0;
}

int editTitle(array * a, char * title){
  if (!a || !title) return -1;//checks if NULL
  album *al = NULL;
  char newtitle[50];
  int err;
  for(unsigned i = 0; i <= a->inUse; i++){
    arrayGet(a, i, (void**) al);
    err = strcmp(title, al->title);
    if(err == 0){
      break;
    }
  }
  printf("What is the new title?\n");
  userInput(newtitle);
  strcpy(al->title, newtitle);
  return 0;
}

int editYear(array * a, char * title){
  if(!a || !title) return -1;
  album *al = NULL;
  int newYear, err;
  for (unsigned i = 0; i <= a->inUse; i++){
    arrayGet(a, i,(void**) al);
    err = strcmp(title, al->title);
    if (err == 0){
      break;
    }
  }
  printf("What is the new year?\n");
  while(scanf("%d", &newYear) != EOF);
  al->year = newYear;
  return 0;
}


int printArtist(array *a, char * title){
  if(!a || !title) return -1;
  album *al = NULL;
  int err;
  for(unsigned i = 0; i <= a->inUse; i++){
    arrayGet(a, i,(void**) al);
    err = strcmp(title,al->title);
    if(err == 0){
      break;
      }
    else
        return -1;
  }
  printf("%s\n", title);
return 0;
}


/*
int editYear(array *a, char * title){
  if (!a || !title) return -1;
  album *al;
  int newyear;
  int err;
  for (int i = 0; i <= a->capacity -1; i++){
    arrayGet(a, i, &al);
    err = strcmp(title,al->title);
    if(err == 0){
      break;
    }
  }
  printf("Enter new year:\n");
  scanf("%s", newyear);
  strcpy(al->year, newyear);
  return 0;
}
*/
/*
int sort(array * a){
  if (!a) return -1;
  album *al;
  int option4;
  printf("What would you like to sort the albums by?\n");
  printf("1. By title\n");
  printf("2. By artist\n");
  printf("3. By year\n");
  scanf("%d", &option4);
  if (option4 == 1) sortArray(a, sortByTitle);
  if (option4 == 2) sortArrayt(a, sortByArtist);
  if (option4 == 3) sortArray(a, sortByYear);
return 0;
}

int titleCompare(const void *p, const void *q){

}

int sortByTitle(array *a, array *b){

*/
