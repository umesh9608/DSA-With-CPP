
---

## 💡 Explanation

This pattern is divided into **two parts**:

### 🔹 Upper Part
- Rows: `1 → n`
- Stars increase (`1 → n`)
- Spaces decrease

### 🔹 Lower Part
- Rows: `n-1 → 1`
- Stars decrease
- Spaces increase

---

## 🧠 Logic

Each row has 3 sections:
1. Left Stars  
2. Middle Spaces  
3. Right Stars  

---

## 💻 C++ Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 4;

    // Upper Part
    for (int row = 1; row <= n; row++)
    {
        // Left stars
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        // Spaces
        for (int col = 1; col <= 2 * (n - row); col++)
        {
            cout << "  ";
        }

        // Right stars
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    // Lower Part
    for (int row = n - 1; row >= 1; row--)
    {
        // Left stars
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        // Spaces
        for (int col = 1; col <= 2 * (n - row); col++)
        {
            cout << "  ";
        }

        // Right stars
        for (int col = 1; col <= row; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}