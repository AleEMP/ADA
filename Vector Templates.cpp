
#include <iostream>
using namespace std;

template <typename Type>
class CVector
{
private:
    Type* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
    void Init(Type delta); // Init our private variables, etc
    void Resize(); // Resize the vector when occurs an overflow
public:
    CVector(Type delta = 10);
    void print();
    void Insert(Type elem); // Insert a new element
    // More methods go here
};
template <typename Type> CVector<Type>::CVector(Type delta) {
    m_nDelta = delta;
    m_nCount = 0;
    m_nMax = 1;
    m_pVect = new Type[m_nMax];
}
template <typename Type> void CVector<Type>::Init(Type delta) {
    m_nDelta = delta;
}
template <typename Type> void CVector<Type>::Resize() {
    Type* pTemp, i;
    pTemp = new Type[m_nMax + m_nDelta]; // Alloc a new vector
    for (i = 0; i < m_nMax; i++)
        pTemp[i] = m_pVect[i];
    delete[] m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}
template <typename Type> void CVector<Type>::Insert(Type elem) {
    if (m_nCount == m_nMax) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}
template <typename Type> void CVector<Type>::print() {
    for (Type i = 0; i < m_nCount; i++)
    {
        cout << m_pVect[i] << " ";
    }
}
int main()
{
    CVector<int>owo;
    for (int i = 0; i < 10; i++)
    {
        owo.Insert(i);
    }
    owo.print();
}

