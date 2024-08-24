
#include <iostream>
using namespace std;


struct Vector
{
    int* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
    Vector() {
        m_nMax = 1;
        m_pVect=new int[m_nMax];
        m_nCount = 0;
        m_nDelta = 5;
    }
};    
void Resize(Vector* pThis)
    {
        int* pTemp, i;
        pTemp = new int[pThis->m_nMax + pThis->m_nDelta]; // Alloc a new vector
        for(i = 0 ; i < pThis->m_nMax; i++)
         pTemp[i] = pThis->m_pVect[i];
        delete [ ] pThis->m_pVect;
        pThis->m_pVect = pTemp;
        pThis->m_nMax += pThis->m_nDelta;
    }
   void Insert(Vector* pThis, int elem)
    {
       if (pThis->m_nCount == pThis->m_nMax) {
           Resize(pThis);
        }
        
        if (pThis->m_nCount == 0) {
            pThis->m_pVect[pThis->m_nCount] = elem;
            pThis->m_nCount++;
        }
        else {
            pThis->m_pVect[pThis->m_nCount++] = elem;
        }
    }
   void print(Vector* pThis) {
       for (int i = 0; i < pThis->m_nCount; i++)
       {
           cout<<pThis->m_pVect[i]<<" ";
       }
   }



int main()
{
    Vector owo;
    for (int i = 0; i < 10; i++)
    {
        Insert(&owo, i);
    }
    print(&owo);
}

