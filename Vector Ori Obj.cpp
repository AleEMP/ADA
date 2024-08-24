
#include <iostream>
using namespace std;


class CVector
{
private:
    int* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
    void Init(int delta); // Init our private variables, etc
    void Resize(); // Resize the vector when occurs an overflow
public:
    CVector(int delta = 10);
    void print();
    void Insert(int elem); // Insert a new element
    // More methods go here
};
CVector::CVector(int delta) {
    m_nDelta = delta;
    m_nCount = 0;
    m_nMax = 1;
    m_pVect = new int[m_nMax];
}
void CVector::Init(int delta) {
    m_nDelta = delta;
}
void CVector::Resize() {
    int* pTemp, i;
    pTemp = new int[m_nMax + m_nDelta]; // Alloc a new vector
    for (i = 0; i < m_nMax; i++)
        pTemp[i] = m_pVect[i];
    delete[] m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}
void CVector::Insert(int elem) {
    if (m_nCount == m_nMax) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}
void CVector::print() {
    for (int i = 0; i < m_nCount; i++)
    {
        cout << m_pVect[i] << " ";
    }
}
int main()
{
    CVector owo;
    for (int i = 0; i < 10; i++)
    {
        owo.Insert(i);
    }
    owo.print();
}

