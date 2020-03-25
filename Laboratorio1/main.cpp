#include <stdlib.h>
#include <iostream>
#include "math_tools.h"
#include "display_tools.h"

int main(void) {
  /*
  Matrix my_matrix, cof_matrix, adj_matrix, answer_matrix;

  zeroes(my_matrix, 3);

  my_matrix.at(0).at(0) = 2; my_matrix.at(0).at(1) = 2; my_matrix.at(0).at(2) = 3;
  my_matrix.at(1).at(0) = 4; my_matrix.at(1).at(1) = 5; my_matrix.at(1).at(2) = 6;
  my_matrix.at(2).at(0) = 7; my_matrix.at(2).at(1) = 8; my_matrix.at(2).at(2) = 9;

  float det = determinant(my_matrix);

  if(det == 0){
    exit(EXIT_FAILURE);
  }
  else{
    cofactors(my_matrix, cof_matrix);
    transpose(cof_matrix, adj_matrix);
    //Matriz adjunta: adj_matriz
    //Dividir adjunta entre determinante
    inversa(adj_matrix, det, answer_matrix);
    showMatrix(answer_matrix);
  }

  */
  
  Matrix my_matrix, answer_matrix;

  zeroes(my_matrix, 3);

  my_matrix.at(0).at(0) = 2; my_matrix.at(0).at(1) = 2; my_matrix.at(0).at(2) = 3;
  my_matrix.at(1).at(0) = 4; my_matrix.at(1).at(1) = 5; my_matrix.at(1).at(2) = 6;
  my_matrix.at(2).at(0) = 7; my_matrix.at(2).at(1) = 8; my_matrix.at(2).at(2) = 9;

  inversa(my_matrix, answer_matrix);

  showMatrix(answer_matrix);
  
  return 0;
}