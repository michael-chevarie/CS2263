//Author: Michael Chevarie (3528829)
//Date: 02/10/2017
//Functionality: Randomly walks across an nxn array labelling each
//               element traversed with a character (starting A-Z)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void traverse(char[], char, int);
int isValid(char[], int, int);
int isEdge(int, int);
int main(){
  //creating array of chars in alphabetical order
  char alphabet = 'A';

  //getting user input for dimension of array
  int n;
  printf("Enter the dimension of the square array that you would like to create: ");
  scanf("%d", &n);

  //creating random number generator
  time_t timeSeed;
  srand((unsigned) time(&timeSeed));

  //creating an nxn array of characters and filling it with '.'
  int i;
  char grid[n*n];
  for(i = 0; i < n*n; i++){
    grid[i] = '.';
  }

  traverse(grid, alphabet, n);
}

//traverses the graph as directed
void traverse(char gridIn[], char letter, int size){
    //randomWalk always starts at position 0
    int position = 0;
    gridIn[position] = 'A';

    //setting status to an integer between 0-3
    //0-->UP, 1-->DOWN, 2-->LEFT, 3-->RIGHT
    int status = rand()%4;

    while((isValid(gridIn, position, size) == 1 || isEdge(position, size) == 1) && letter != 'Z'){

      //if block for travelling up
      if(status == 0){
        int add = size*size-size;
        if(position < size && gridIn[position + add] != '.' && isValid(gridIn, position, size) == 0){
          letter = 'Z';
        }
        //if position is less than size, then it is along top row
        if(position < size && gridIn[position + add] == '.'){
          position += add;
          letter++;
          gridIn[position] = letter;
        }else if(gridIn[position - size] == '.'){
          position = position - size;
          letter++;
          gridIn[position] = letter;
        }
      }

      //if block for travelling down
      if(status == 1){
        int add = size*size-size;
        if(position >= add && gridIn[position - add] != '.' && isValid(gridIn, position, size) == 0){
          letter = 'Z';
        }
        //if position is on bottom row
        if(position >= add && gridIn[position - add] == '.'){
          position = position - add;
          letter++;
          gridIn[position] = letter;
        }else if(position < add && gridIn[position + size] == '.'){
          position += size;
          letter++;
          gridIn[position] = letter;
        }
      }

      //if block for travelling left
      if(status == 2){
        int add = size - 1;
        if(position%size == 0 && gridIn[position + add] != '.' && isValid(gridIn, position, size) == 0){
          letter = 'Z';
        }
        //if position is on left edge
        if(position%size == 0 && gridIn[position + add] == '.'){
          position = position + add;
          letter++;
          gridIn[position] = letter;
        }else if(position%size != 0 && gridIn[position - 1] == '.'){
          position = position - 1;
          letter++;
          gridIn[position] = letter;
        }
      }

      //if block for travelling right
      if(status == 3){
        int add = size - 1;
        int test = position + 1;
        if(test%size == 0 && gridIn[position - add] != '.' && isValid(gridIn, position, size) == 0){
          letter = 'Z';
        }
        //if position is on right side
        if(test % size == 0 && gridIn[position - add] == '.'){
          position = position - add;
          letter++;
          gridIn[position] = letter;
        }else if(test % size != 0 && gridIn[position + 1] == '.'){
          position = position + 1;
          letter++;
          gridIn[position] = letter;
        }
      }
      status = rand()%4;
  }

    //initializing counters
    int counter = 0;
    int p = 0;
    int q = 0;

    //printing array
    while(p < size){
      printf("\n");
      q = 0;
      while(q < size){
        printf("%c ", gridIn[counter]);
        counter++;
        q++;
      }
      p++;
    }
}

//checks to see if current position is able to traverse any further
int isValid(char isGrid[], int curr, int dimension){
  if(isGrid[curr + 1] == '.' || isGrid[curr -1] == '.' || isGrid[curr + dimension] == '.' || isGrid[curr - dimension] == '.'){
    return 1;
  }else{
    return 0;
  }
}

int isEdge(int curr, int dimension){
  int bottomTest = dimension*dimension - dimension;
  int currPlus = curr + 1;
  if(curr < dimension || curr >= bottomTest || curr%4 == 0 || currPlus%4 == 0){
    return 1;
  }else{
    return 0;
  }
}
