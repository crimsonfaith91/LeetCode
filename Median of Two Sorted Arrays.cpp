class Solution {
public:
    double fmsRecur(int A[], int m, int B[], int n, int size) {
        if(m > n) return fmsRecur(B, n, A, m, size);
        
        if(m == 0) return B[size - 1];
        if(size == 1) return min(A[0], B[0]);
        int lenA = min(size / 2, m);
        int lenB = size - lenA;
        
        if(A[lenA - 1] <= B[lenB - 1]) {
            return fmsRecur(A + lenA, m - lenA, B, n, size - lenA);
        }   
        else {
            return fmsRecur(A, m, B + lenB, n - lenB, size - lenB);
        }
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int totalSize = m + n;
        
        if(totalSize % 2 != 0) {
            return fmsRecur(A, m, B, n, totalSize / 2 + 1);
        }
        else {
            return (fmsRecur(A, m, B, n, totalSize / 2) + fmsRecur(A, m, B, n, totalSize / 2 + 1)) / 2;
        }
    }
};