# CP Program

### 【CSES】 Maximum Subarray Sum

**Solved**

* keypoint: kadane's algorithm
    1. 概念：目前陣列和 ＋ 新數字 > 新數字，把新數字放進陣列和裡，不然就把新數字當作開頭
    2. 作法：max_sum 紀錄當前最大和， cur 紀錄目前陣列和
    cur = max(arr[i], arr[i] + cur); 如果陣列和 ＋ 新數字 > 新數字，cur 就會再加上這個數字，否則更新成新數字，代表從這個數字開始計算
* time complex: O(n)

### feat: Modify .gitignore

### feat: Create .gitignore and Remove Some Excute File and Folder

### feat: change the content of Set.cpp

* left things i'll use >>

### feat: Push All of the Previous Code

### 【CSES】 Coin Piles

**Solved**

* a + b 不是三的倍數就無法剛好拿完
* 2b = a or a = ab 才會拿的玩

### 【CSES】 Trailing Zeros

**Solved**

* 不用真的算出 n! , 10 = 2 * 5 (找有幾個五的因數)
* ans = (ans * 2) % MOD;，確保不會超過 long long 的範圍

### 【AtCoder】 Beginner Contest 397 - D. Cubes

**Solved**

。Mathematics + Binary Search - O($\sqrt[3]{N}log\sqrt{N}$)

* Complexity Analysis
    * Iterating over $d$ takes at most ⮕ O($\sqrt[3]{N}$)
    * Binary search over $y$ runs in ⮕ O($log\sqrt{N}$)
    * Overall complexity ⮕ O($\sqrt[3]{N}log\sqrt{N}$)
* Mathematical Derivation
    1. We start by factorizing the given equation using the identity for the difference of cubes $x^{3} - y^3 = (x - y)(x^2 + xy + y^2)$
    2. Define $d = x - y$, so that  $N = d(x^2 + xy + y^2)$
    3. Rewriting in terms of $d$ and $y$ </br>
        $N = d[(y+d)^2 + y(y+d) + y^2]$ </br>
        &nbsp; &nbsp; $\Longrightarrow d[y^2 + 2dy + d^2 + y^2 + dy + y^2]$ </br>
        &nbsp; &nbsp; $\Longrightarrow dy^2 + 2d^2y + d^3 + dy^2 + d^2y + dy^2$ </br>
        &nbsp; &nbsp; $\Longrightarrow 3dy^2 + 3d^2y + d^3$
* Solution Strategy
    1. Determine the range for $d = x - y$
        * At $x^2 + xy + y^2 \geq (x - y)^3$, it follows that $(x - y)^3 \leq N$, that is $d \leq \sqrt[3]{N}$, which allowing us to conclude that the enumeration of $d$ is O($\sqrt[3]{N}$)
    2. Find valid integer values of $y$ given $d$
        1. The judgment can be completed using the quadratic formula, and the time complexity is O(1); however, its implementation is more complicated to implement
        2. Considering that the coefficients of both the quadratic and linear terms are positive, the formula is monotonically increasing when $x > 0$. Therefore, we can apply binary search. Obviously, we only need to perform binary search within the interval $[1, \sqrt{N}]$, resulting in a time complexity of O($log\sqrt{N}$), which is relatively straightforward to implement
3. Binary Search Optimization
   * Instead of explicitly solving the quadratic equation, we can use **binary search** on $y$, since the function is monotonic for positive $y$
   * Given that $y$ is at most O($\sqrt{N}$), binary search runs in O($\sqrt[3]{N}log\sqrt{N}$)
4. Checking for Integer Solutions
   * If a valid $y$ is found for any $d = x - y$, output $x$ and $y$
   * If no such pair exists, return $-1$

### feat: Initialize

> [!NOTE]
> How To Push Code
> * git add `<File's name you want to push>`
>   * OR git add .
> * git commit -m "`<Commit Message>`"
> * git push