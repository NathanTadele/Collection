#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "album.h"
#include "array.h"

int option;

int userOption(){
  printf("Welcome to album collection! What would you like to do?\n");
  printf("1. Do you want to add an album?\n");
  printf("2. Do you want to edit an album?\n");
  printf("3. Do you want to delete an album?\n");
  printf("4. Do you want view a list of albums?\n");
  printf("5. Do you want to view the details of one album?\n");
  printf("6. Would you like to sort your collection?\n");
  printf("7. Search for an artsit.\n");
  printf("8. Quit\n");
  printf("Choose a number from the above options.\n");
  scanf("%d", &option);
  return 1;
}

int execute(array *Collection) {
  if (option == 1) newAlbum(Collection);
  if (option == 2) edit(Collection);
  if (option == 3) deleteAlbum(Collection);
  //if (option == 4) printInfo(Collection);
  if (option == 5) printInfo(Collection);
  if (option == 7) search (Collection);
  if (option == 8) return 0;
  return 1;
}

int main(){
  /*char deletetitle [50];
  array *Collection = newArray();
  int option;
  printf("Welcome to album collection! What would you like to do?\n");
  printf("1. Do you want to add an album?\n");
  printf("2. Do you want to edit an album?\n");
  printf("3. Do you want to delete an album?\n");
  printf("4. Do you want view a list of albums or details of one?\n");
  printf("5. Would you like to sort your collection?\n");
  printf("Choose a number from the above options.\n");

  scanf("%d", &option);
  switch(option){
    case 1:  newAlbum(Collection);
    case 2:  edit(Collection);
    case 3:  printf("Enter the title of the album you want to delete.\n");
             scanf("%s", deletetitle);
             deleteAlbum(Collection, deletetitle);
    case 4:printInfo(Collection);
    //case '5':sort(Collection);
}*/
  array *Collection = newArray();
  while (userOption() && execute(Collection));
  return 0;
}
