#include <iostream>
#include <fstream>

int** read_matrix(int size, std::ifstream &matrixfile) {
  int** matrix = new int*[size];

  for (int i = 0; i < size; i++) {
    matrix[i] = new int[size];
    for (int j = 0; j < size; j++) {
      matrixfile >> matrix[i][j];
    }
  }
  return matrix;
}

void print_matrix(int** matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int** add_matrix(int** matrix1, int** matrix2, int size) {
  int** sum_matrix = new int*[size];
  for (int i = 0; i < size; i++) {
    sum_matrix[i] = new int[size];
    for (int j = 0; j < size; j++) {
      sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  std::cout << "The Sum of the two matrices is:" << std::endl;
  print_matrix(sum_matrix, size);
  return sum_matrix;
}

int** matmul(int** matrix1, int** matrix2, int size) {
  int** result = new int*[size];
  for (int i = 0; i < size; i++) {
    result[i] = new int[size];
    for (int j = 0; j < size; j++) {
      result[i][j] = 0;
      for (int k = 0; k < size; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  std::cout << "The Product of the two matrices is:" << std::endl;
  print_matrix(result, size);
  return result;
}

int** subtract_matrix(int** matrix1, int** matrix2, int size) {
  int** difference = new int*[size];
  for (int i = 0; i < size; i++) {
    difference[i] = new int[size];
    for (int j = 0; j < size; j++) {
      difference[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
  std::cout << "The Difference of the two matrices is:" << std::endl;
  print_matrix(difference, size);
  return difference;
}

void edit_matrix(int** matrix, int row, int column, int new_value, int size) {
  if (row >= 0 && row < size && column >= 0 && column < size) {
    matrix[row][column] = new_value;
  }
  else {
    std::cout << "Invalid index" << std::endl;
  }
  std::cout << "The edited matrix is:" << std::endl;
  print_matrix(matrix, size);
}

int get_max(int** matrix, int size) {
  int max = matrix[0][0];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (matrix[i][j] > max) {
        max = matrix[i][j];
      }
    }
  }
  std::cout << "The maximum value in the matrix is: " << max << std::endl;
  return max;
}

int** transpose(int** matrix, int size) {
  int** transposed = new int*[size];
  for (int i = 0; i < size; i++) {
    transposed[i] = new int[size];
    for (int j = 0; j < size; j++) {
      transposed[i][j] = matrix[j][i];
    }
  }
  std::cout << "The transposed matrix is:" << std::endl;
  print_matrix(transposed, size);
  return transposed;
}

int main() {
  int size;
  std::ifstream matrixfile;
  matrixfile.open("matrix_input.txt");
  matrixfile >> size;

  int** matrix1 = read_matrix(size, matrixfile);
  int** matrix2 = read_matrix(size, matrixfile);

  std::cout << "Matrix 1" << std::endl;
  print_matrix(matrix1, size);
  std::cout << "Matrix 2" << std::endl;
  print_matrix(matrix2, size);
  int** sum_matrix = add_matrix(matrix1, matrix2, size);
  int** product_matrix = matmul(matrix1, matrix2, size);
  int** difference = subtract_matrix(matrix1, matrix2, size);

  int row, column, new_value;
  std::cout << "Enter the row and column you want to edit: ";
  std::cin >> row >> column;
  std::cout << "Enter the new value: ";
  std::cin >> new_value;
  edit_matrix(matrix1, row, column, new_value, size);


  int max = get_max(matrix1, size);
  int** transposed = transpose(matrix1, size);
  return 0;
}