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
    char title[500];
    char artist[500];
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
  strcpy(al->artist, artist);// stores what they typed in title in the album struct
  strcpy(al->title, title);//stores what they typed in artist in the album struct
  al->year = year;//stores what they typed in year in the album struct
  err = arrayPushBack(a, al);//puts the album struct into the array struct
  //arrayPut(a, sizeof(album), al);
  sort(a);
  // saveAlbum();

  if (err) return -1;
return 0;
}

int sort(array *a){
  if(!a) return -1;
  if(a->inUse <= 1) return -1;
  album *al = NULL;
  album *aj = NULL;
  album *temp = NULL;
  for(unsigned i = 0; i < a->inUse; i++){
    for(unsigned j = i+1; j <= a->inUse; j++){
      arrayGet(a, i, (void*) &al);
      arrayGet(a, j, (void*) &aj);
      if(al->year > aj->year){
        temp =  al;
        al = aj;
        aj = temp;
        arrayPut(a, j, (void*) aj);
        arrayPut(a, i, (void*) al);
      }
    }
  }
  return 0;
}

int userInput(char *input){
  fgets(input, 10*sizeof(input),stdin);
  //scanf("%s/n", input);
  if (*input == ' '|| input[1] == '\0'){
    // printf("error\n");
    return 1;
  }
  return 0;
}

int deleteAlbum(array *a){
  if(!a) return -1;//checks for null pointers
  album *al = NULL;
  char e[50];
  int err;
  int l;
  printf("Which album do you want to delete?\n");
  while(userInput(e));
  for(unsigned i = 0; i <= a->inUse; i++){
    arrayGet(a, i, (void*) &al);//gets information from each album in the array struct
    err = strcmp(e,al->title);// finds an album title that directly matches the title that the user netered in
    if(err == 0){
      l=i;
      free(a->data[l]);//deletes the album the user entered in
      printf("album deleted.\n");
      return 0;
    }
}
printf("didn't find album\n");
return -1;
}


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
    while(userInput(e));
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
void printString(album * e){

  printf("%s\n", e->title);
}

void printAlbums(array *a){

  for(size_t i = 0; i < a->inUse; i++){
    album *al = a->data[i];
    printf("\n%s", al->title);
    printf("%s", al->artist);
    printf("%d\n", al->year);

  }
}

int printInfo(array *a){
  printf("What would you like to print?\n");
  printf("1. Details of a specific album\n");
  printf("2. Full list of albums\n");
  printf("3. List of albums by one artist\n");
  int option3;
  char e[50];
  scanf("%d/n", &option3);
  if (option3 == 1){
    printf("Enter the album you want to see.\n");
    while(userInput(e));
    printAlbum(a, e);
  }
  if (option3 == 2) printAlbums(a);
  if (option3 == 3){
    search(a);
  }
return 0;
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
    arrayGet(a, i, (void *) &al);
    err = strcmp(artist, al->artist);
    if(err == 0){
      printf("%s\n", al->title);
    }
  }
  return 0;
}



album * findAlbum(array *a, char * title){
  if(!a || !title) return NULL;
  album *al = NULL;
  int err;
  for(unsigned i = 0; i < a->inUse; i++){
    arrayGet(a, i, (void *) &al);
    err = strcmp(title, al->title);
    if(err == 0){
      return al;
    }
  }
  printf("Error: album you have searched for does not currently exist.\n");
  return NULL;
}



int printAlbum(array * a, char * title){
  if(!a) return -1;
  album *al;
  al = findAlbum(a, title);
    printf("%s\n", al->title);
    printf("%s\n", al->artist);
    printf("%d\n", al->year);
  return 0;
}


int editArtist(array * a, char * title){
  if (!a || !title) return -1;
  album *al = NULL;
  char newartist [50];
  int err;
  for (unsigned i = 0; i <= a->inUse; i++){
    arrayGet(a, i, (void*) &al);
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
  for(unsigned i = 0; i < a->inUse; i++){
    arrayGet(a, i, (void*) &al);
    err = strcmp(title, al->title);
    if(err == 0){
      printf("What is the new title?\n");
      userInput(newtitle);
      strcpy(al->title, newtitle);
      printf("new:%s\n",al->title);
      break;
    }
    else printf("Title was not found!\n");
  }
  return 0;
}

int editYear(array * a, char * title){
  if(!a || !title) return -1;
  album *al = NULL;
  int newYear, err;
  for (unsigned i = 0; i < a->inUse; i++){
    arrayGet(a, i,(void*) &al);
    err = strcmp(title, al->title);
    if (err == 0){
      break;
    }
  }
  printf("What is the new year?\n");
  while(scanf("%d", &newYear) != 1);
  al->year = newYear;
  return 0;
}
