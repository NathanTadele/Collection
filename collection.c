#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "album.h"
#include "array.h"

int option;

int arianaGrande(){
  printf(
  "Title: Best Mistakes\n"
  "Artist: Ariana Grande ft. Big Sean\n"
  "Year: 2014\n"

  "How soon do we forget how we felt?\n"
"Dealing with emotions that never left\n"
"Playing with the hand that we were dealt in this game\n"
"Maybe I'm the sinner and you're the saint\n"
"Gotta stop pretending what we ain't\n"
"Why we pointing fingers anyway when we're the same?\n"

"[Pre-Chorus: Ariana Grande]\n"
"Break up, make up\n"
"Total waste of time\n"
"Can we please make up our minds and stop acting like we’re blind?\n"
"Cause if the water dries up and the moon stops shining\n"
"Stars fall, and the world goes blind\n"
"Boy, you know I'll be savin' my love for you, for you\n"

"[Chorus: Ariana Grande]\n"
"Cause you're the best mistake I've ever made\n"
"But we hold on, hold on\n"
"There's no pot of gold in the rainbows we chase\n"
"But we hold on, hold on, yeah\n"

"[Verse 2: Big Sean]\n"
"I guess time's wasting\n"
"Tick-tocking, lip locking\n"
"How can we keep the feelings fresh?\n"
"How do we zip lock it?\n"
"Wear your heart up on your sleeve\n"
"So watch out for pickpockets\n"
"I guess to go the distance we might need to pit stop it\n"
"Hold up, I know love can be a beach with no shore\n"
"I done count to ten, lost my temper and went back to four\n"
"I know sometimes it's hard to realize I'm the man that you need\n"
"I had a dream we branched out, started a family tree, huh\n"
"And I feel like that everything we do is overdue\n"
"You asked why I love your mom so much, 'cause she's a older you\n"
"I wish that you were happy\n"
"I guess that's the one thing I should be providing\n"
"Ain't no number twos\n"
"We both ones of ones, and we the oddest couple\n"
"Only humans, 'cept you, you a goddess\n"
"Only lying to you when I lie you down, just being honest\n"
"When you start as friends, its hard to say youre never going back\n"
"If Im not the one, then Im the best mistake you ever had\n"
"\n"
"\n");
return 0;
}

int userOption(){
  printf("Welcome to album collection! What would you like to do?\n");
  printf("1. Do you want to add an album?\n");
  printf("2. Do you want to edit an album?\n");
  printf("3. Do you want to delete an album?\n");
  printf("4. Do you want to view the info about your albums?\n");
  printf("5. Best Mistakes by Ariana Grande\n");
  printf("6. Quit\n");
  printf("Choose a number from the above options.\n");
  scanf("%d", &option);
  return 1;
}

int execute(array *Collection) {
  if (option == 1) newAlbum(Collection);
  if (option == 2) edit(Collection);
  if (option == 3) deleteAlbum(Collection);
  if (option == 4) printInfo(Collection);
  if (option == 5) arianaGrande();
  if (option == 6) return 0;
  return 1;
}

int main(){

  array *Collection = newArray();
  while (userOption() && execute(Collection));
  return 0;
}
