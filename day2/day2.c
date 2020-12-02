#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int part1_policy_check(const char *in_line) {
  // Copy argument string 
  void* lptr = malloc(strlen(in_line));
  char* line = (char*)lptr;
  strcpy(line, in_line);
  int strpos = 0;
  
  // Calculate lower bound of policy
  while ( line[strpos] != '-' ) { strpos++; }
  char* lower_bound = (char*)malloc(strpos+1);
  strncpy(lower_bound, line, strpos);
  lower_bound[strpos] = 0;
  int lb = atoi(lower_bound);
  free(lower_bound);
  //printf("Lower Bound: %i\n", lb);
  line += strpos+1;
  
  // Calculate upper bound of policy
  strpos = 0;
  while ( line[strpos] != ' ' ) { strpos++; }
  char* upper_bound = (char*)malloc(strpos+1);
  strncpy(upper_bound, line, strpos);
  upper_bound[strpos] = 0;
  int ub = atoi(upper_bound);
  free(upper_bound);
  //printf("Upper Bound: %i\n", ub);
  line += strpos;

  // Pick character from password policy
  strpos = 1;
  char cval = line[strpos];
  //printf("Character in policy: %c\n", cval);
  line += strpos;
  
  // Calculate compliance with policy
  int occurrences = 0;
  for (strpos = 1; strpos < strlen(line); strpos++) {
    if (line[strpos] == cval) { occurrences++; }
  }
  printf("Occurrences of character: %i\n", occurrences);
  
  free(lptr);
  return(occurrences <= ub && occurrences >= lb);
}

int part2_policy_check(const char *in_line) {
  // Copy argument string 
  void* lptr = malloc(strlen(in_line));
  char* line = (char*)lptr;
  strcpy(line, in_line);
  int strpos = 0;
  
  // Calculate lower bound of policy
  while ( line[strpos] != '-' ) { strpos++; }
  char* lower_bound = (char*)malloc(strpos+1);
  strncpy(lower_bound, line, strpos);
  lower_bound[strpos] = 0;
  int lb = atoi(lower_bound);
  free(lower_bound);
  //printf("Lower Bound: %i\n", lb);
  line += strpos+1;
  
  // Calculate upper bound of policy
  strpos = 0;
  while ( line[strpos] != ' ' ) { strpos++; }
  char* upper_bound = (char*)malloc(strpos+1);
  strncpy(upper_bound, line, strpos);
  upper_bound[strpos] = 0;
  int ub = atoi(upper_bound);
  free(upper_bound);
  //printf("Upper Bound: %i\n", ub);
  line += strpos;

  // Pick character from password policy
  strpos = 1;
  char cval = line[strpos];
  //printf("Character in policy: %c\n", cval);
  line += strpos;
  
  // Calculate compliance with policy
  int occurrences = 0;
  int pos1, pos2;
  for (strpos = 3; strpos < strlen(line); strpos++) {
    //printf("At position %i, current char is %c\n", strpos, line[strpos]);
    if (strpos-2 == lb) { pos1 = line[strpos] == cval ? 1 : 0; }
    if (strpos-2 == ub) { pos2 = line[strpos] == cval ? 1 : 0; }    
  }
  //printf("Pos1 match? %i, Pos2 match? %i\n", pos1, pos2);
  
  free(lptr);
  return(pos1 ^ pos2);
}

int part1(FILE *db) {
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  int passed_policy = 0;
  while ((nread = getline(&line, &len, db)) != -1) {
    //passed_policy += part1_policy_check(line);
    passed_policy += part2_policy_check(line);
  }
  free(line);
  fclose(db);

  printf("Passed policy: %i\n", passed_policy);
  return(1);
}

int main() {
  FILE *password_db;
  password_db = fopen("input", "r");
  return part1(password_db);
}


