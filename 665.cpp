#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector< vector<int> > matrix_sum;

    NumMatrix(vector< vector<int> > matrix) {
        for (int i = 0; i < matrix.size(); i++)
        {
            vector<int> v;
            int sum = 0;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                sum += matrix[i][j];
                v.push_back(sum);
            }

            this->matrix_sum.push_back(v);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        for (int i = row1; i <= row2; i++)
        {
            sum += this->matrix_sum[i][col2] - this->matrix_sum[i][col1 - 1];
            printf("[%d][%d] - [%d][%d] = %d\n", i, col2, i, col1 - 1, this->matrix_sum[i][col2] - this->matrix_sum[i][col1 - 1]);
        } 

        return sum;
    }

    int printVector(vector< vector<int> > v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
                cout << v[i][j] << " ";
            cout << endl;
        }

        return 0;
    }

     int print1DVector(vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";

        return 0;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

/*
[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]
sumRegion(2, 1, 4, 3)
sumRegion(1, 1, 2, 2)
sumRegion(1, 2, 2, 4)

 */
int main2(int argc, char const *argv[])
{
    vector<int> v1,v2,v3,v4,v5;
    v1.push_back(3);v1.push_back(0);v1.push_back(1);v1.push_back(4);v1.push_back(2);
    v2.push_back(5);v2.push_back(6);v2.push_back(3);v2.push_back(2);v2.push_back(1);
    v3.push_back(1);v3.push_back(2);v3.push_back(0);v3.push_back(1);v3.push_back(5);
    v4.push_back(4);v4.push_back(1);v4.push_back(0);v4.push_back(1);v4.push_back(7);
    v5.push_back(1);v5.push_back(0);v5.push_back(3);v5.push_back(0);v5.push_back(5);

    vector< vector<int> > matrix;
    matrix.push_back(v1);matrix.push_back(v2);matrix.push_back(v3);matrix.push_back(v4);matrix.push_back(v5);

    NumMatrix *m = new NumMatrix(matrix);
    m->printVector(matrix);
    cout << "~~~" << endl;
    m->printVector(m->matrix_sum);

    cout << m->sumRegion(2,1,4,3) << endl;
    cout << m->sumRegion(1,1,2,2) << endl;
    cout << m->sumRegion(1,2,2,4) << endl;
 
    return 0;
}

int main(int argc, char const *argv[])
{
    // 11,23,11,19,8,15,7,18,9
    vector<int> v1;
    v1.push_back(11);
    v1.push_back(23);
    v1.push_back(11);
    v1.push_back(19);
    v1.push_back(8);
    v1.push_back(15);
    v1.push_back(7);
    v1.push_back(18);
    v1.push_back(9);

    vector< vector<int> > matrix;
    matrix.push_back(v1);

    NumMatrix *m = new NumMatrix(matrix);
    m->printVector(matrix);
    cout << "~~~" << endl;
    m->printVector(m->matrix_sum);

    cout << m->sumRegion(0,4,0,6) << endl;
 
    return 0;
}

