#include "11920.h"
#include <iostream>
#include <stdio.h>
using namespace std;

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
  int r = m.get_size_row();
  int c = m.get_size_col();
  for (int i = 0; i < r; i++) {
    int* tmp = m.get_row(i);
    for (int j = 0; j < c; j++) {
      os << tmp[j] << " ";
    }
    os << "\n";
  }
  return os;
}

int main() {
  int Mat_num, row, col, val;
  cin >> Mat_num;
  MatrixChain MCChen(Mat_num);
  for (int i = 0; i < Mat_num; i++) {
    cin >> row >> col;
    Matrix* now = MCChen.setMatrix(i, row, col);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cin >> val;
        now->set_value(i, j, val);
      }
    }
  }
  int l, r;
  cin >> l >> r;
  Matrix m(MCChen.arr[l]->get_size_row(), MCChen.arr[r - 1]->get_size_col());
  m = MCChen.calc(l, r);
  cout << m;
}
Matrix Matrix::operator=(const Matrix &a){
    size_col=a.size_col;
    size_row=a.size_row;
    int i,j;
    for(i=0;i<size_row;i++){
        for(j=0;j<size_col;j++){
            arr[i][j]=a.arr[i][j];
        }
    }
    return *this;
}
Matrix Matrix::operator*(const Matrix &a) const{
    Matrix C(size_row,a.size_col);
    //printf("row=%d col=%d\n", size_row, a.size_col);
    int i, j, k;
    for(i=0;i<size_row;i++){
        for(j=0;j<a.size_col;j++){
            C.arr[i][j]=0;
        }
    }
    for(i=0;i<size_row;i++){
        for(j=0;j<a.size_col;j++){
            for(k=0;k<size_col;k++){
                C.arr[i][j]+=arr[i][k]*a.arr[k][j];
                //printf("C.arr[%d][%d]=%d arr[%d][%d]*a.arr[%d][%d]\n",i,j,C.arr[i][j],i,k,k,j);
            }
        }
    }
    return C;
}
Matrix MatrixChain::calc(int l, int r) const{
    Matrix m(arr[l]->get_size_row(), arr[l]->get_size_row());
    //printf("M row=%d M col=%d\n", arr[l]->get_size_row(),arr[r - 1]->get_size_col());
    if(l==r-1){
        m=(*arr[l]);
        return m;
    }
    int i;
    for(i=l;i<r;i++){
        m=m*(*arr[i]);
    }
    return m;
}
