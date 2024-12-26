#include <stdio.h>
#include <strings.h>
#include <ctype.h>

int main(int argc, char* argv[]){
  if (argc != 2) {
    printf("Usage: %s <string>.\n", argv[0]);
    return 1;
  } 

  const char* string = argv[1];

  int hashmap[26];
  for (int index = 0; index < 26; index++) {
    hashmap[index] = 0;
  }

  int hash_index; // aka hash, hash_value

  for(int index = 0; string[index] != '\0'; index++) {
    
    char letter = tolower(string[index]);
    hash_index =  letter - 'a'; // no need for typecasting
    
    // Skipping non-alphabets
    if (0 > hash_index && hash_index > 26) continue;
    
    //Increamenting the count value;
    hashmap[hash_index]++;
  }

  int count;
  //Printing all the alphabet count 
  for (int index = 0; index < 26; index++ ) {

    //Skipping if Zero
    int count = hashmap[index];
    if (count == 0) continue;

    printf("Character %c : %i\n", 'a' + index , count);
  }
}
