#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "album.h"
#include "array.h"

char option[3];

void userOption(){
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
}

int execute(array *Collection) {
  fgets(option, sizeof(option), stdin);
  if (option[0] == '1') newAlbum(Collection);
  else if (option[0] == '2') edit(Collection);
  else if (option[0] == '3') deleteAlbum(Collection);
  //if (option == 4) printInfo(Collection);
  else if (option[0] == '5') printInfo(Collection);
  else if (option[0] == '7') search (Collection);
  else if (option[0] == '8') return 0;
  else {
    userOption();
}
return 1;
}

int main(){

  array *Collection = newArray();
  userOption();
  while (execute(Collection));
  return 0;

}
