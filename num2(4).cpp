#include <iostream>
using namespace std;

struct Matrix {
  // двумерный массив с данными.
  int** data_=nullptr;
  // количество столбцов
  size_t n_=0u;
  // количество строк
  size_t m_ = 0u;
};

// Создает заполненную нулями матрицу n столбцов x m строк.
void Construct(Matrix& out, size_t n, size_t m){
  out.n_=n;
	out.m_=m;
	out.data_=new int* [m];
	
	
	for (int i=0;i<m;i++) {
		out.data_[i]=new int[n]();
		
	}
}

// Освобождает выделенную память.
void Destruct(Matrix& in){
  
  
    for (int i=0;i<in.m_;i++){
        delete in.data_ [i];
    }
    
    delete in.data_;
}

// Создает копию матрицы |matrix|.
Matrix Copy(const Matrix& matrix){
    Matrix mat;
    Construct(mat, matrix.n_, matrix.m_);
    
    for (int i=0; i<matrix.m_; i++){
      
        for (int j=0; j<matrix.n_; j++){
            mat.data_[i][j] = matrix.data_[i][j];
            
        }
    }
    return mat;
}

// Возвращает сумму двух матриц.
Matrix Add(const Matrix& a, const Matrix& b){
    Matrix mat;
    Construct(mat, a.n_, b.m_);
    
    for (int i=0; i<a.m_; i++){
      
        for (int j=0; j<a.n_; j++){
            mat.data_[i][j] = a.data_[i][j] + b.data_[i][j];
            
        }
    }
    return mat;
}

// Возвращает разницу двух матриц.
Matrix Sub(const Matrix& a, const Matrix& b){
    Matrix mat;
    Construct(mat, a.n_, a.m_);
    
    for (int i=0; i<a.m_; i++){
      
        for (int j=0; j<a.n_; j++){
            mat.data_[i][j] = a.data_[i][j] - b.data_[i][j];
            
        }
    }
    return mat;
}

// Возвращает произведение двух матриц.
Matrix Mult(const Matrix& a, const Matrix& b){
    Matrix mat;
    Construct(mat, a.n_, a.m_);
    
    for (int i=0; i<a.m_; i++){
      
        for (int j=0; j<a.n_; j++){
            mat.data_[i][j] = a.data_[i][j] * b.data_[i][j];
            
        }
    }
    return mat;
}

// Транспонирование матрицы.
Matrix Transposition(const Matrix& matrix){
    Matrix mat;
    Construct(mat, matrix.n_, matrix.m_);
    
    for (int i=0; i<matrix.m_; i++){
      
        for (int j=0; j<matrix.n_; j++){
            mat.data_[i][j] = matrix.data_[j][i];
            
        }
    }
    return mat;
}

// Сравнение двух матриц.
bool Operator(const Matrix& a, const Matrix& b){
    int damn = 1;
    
    for (int i=0; i<a.m_; i++){
      
        for (int j=0; j<a.n_; j++){
          
            if (a.data_[i][j] != b.data_[i][j]){
                damn=0;
            }
        }
    }
    return damn;
}

int main(){
    Matrix m;
    Construct (m, 3, 6);
    Destruct (m);
    
    Matrix m1; // Матрица 3 строки, 2 столбца
    Construct(m1, 2, 3);
    m1.data_[0][0] = 1;
    m1.data_[0][1] = 2;
    m1.data_[1][0] = 3;
    m1.data_[1][1] = 4;
    m1.data_[2][0] = 5;
    m1.data_[2][1] = 6;
    Matrix m_Copy = Copy(m1);
    Matrix m_Add = Add(m1, m1);
    Matrix m_Sub = Sub(m1, m1);
    Matrix m_Mult = Mult(m1, m1);
    Matrix m_Transposition = Transposition(m1);
    bool m_Operator = Operator(m1,m1);
}