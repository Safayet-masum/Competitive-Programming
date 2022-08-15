struct Matrix
{
    long long v[64][64];
    int row, col;
    Matrix(int n, int m, long long a = 0)
    {
        memset(v, 0, sizeof(v));
        row = n, col = m;
        for(int i = 0; i < row && i < col; i++)
            v[i][i] = a;
    }
    Matrix operator*(const Matrix& x) const
    {
        Matrix ret(row, x.col);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < x.col; j++)
                for(int k = 0; k < col; k++)
                    ret.v[i][j] += v[i][k] * x.v[k][j] %mod,
                                   ret.v[i][j] %= mod;
        return ret;
    }
    Matrix operator^(const int& n) const
    {
        Matrix ret(row, col, 1), x = *this;
        int y = n;
        while(y)
        {
            if(y&1)
                ret = ret * x;
            y = y>>1, x = x * x;
        }
        return ret;
    }
};
