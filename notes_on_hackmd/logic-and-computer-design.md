*How to do effective study:*
![](https://i.imgur.com/BZTEuVR.png)

[TOC]

# Logic and Computer Design Fundamentals (3rd Edition) 
M. Morris Mano, Charles R. Kime; Person Prentice Hall, 2003

## Section
1. 觀察(Survey)
2. 提問(Question)
3. 閱讀(Read) 
4. 回想(Recall)
5. 複習(Review)

## Chapter 5 / Arithmetic functions and circuit
### §5.3 Binary Substration
此節先從`unsigned number addition and substration`開始介紹，因為`unsigned number arithmetic`在計算上和計算機硬體設計上仍扮演著重要的角色；用於`floating-point units`, **signed-magnitude addition and substration algorithm**, 和`extending the precision of fixed-point numbers`.

於§1.3 Arithmetic Operations，介紹substration of two binary numbers的部份；其中一個「被減數(Minuend)」的值比「減數(Subtrahend)」小的例子：

:notes: 此例的numbers皆為unsigned且有簡化成4-bit。

```
Borrows into: *1(2->1)* 1(2) 0 0      // The borrow `1` should 
                                      // be treated as 2 units,
                                      // shown in ().
Minuend:            0     0  1 1 [3]  // The number in backets `[]` is
Subtrahend:       - 1     1  1 0 [14] // corresponding Decimal number. 
                  --------------
Difference:         0     1  0 1 [5]
```
> 
> 由上例，若用小的值減去大的值，得到的結果不如預期的結果，-(11)；**問題是出在most significant position發生borrow，與超出可表示的bit借了2的單位的值** 
> > 目前已將`borrow`改稱為`EXCHANGE`, `EXCHANGE`當作名詞的其中一個解釋如下：
> >
> > 2. the changing of money to its equivalent in the currency of another country.
> > --> 中文解釋是：「換匯」
> >
> > 在減法的應用上，可以解釋成「將欲被借位的一個值兌換成使用的number system的單位（此例為binary，故為`2`）給借位的位元使用」
> > > ref. [Subtraction (Decomposition method) – Sheet 1](https://currieprimary.files.wordpress.com/2015/01/subtraction1.pdf)
> [name=asahsieh] [color=red] 

比較簡單的減法運算是，減數與被減數互換，計算的結果再加上負號；改用此方法套用到上述例子的結果如下：
  ```
  Borrows into:         0011
  Minuend:              1110
  Subtrahend:           0011
                        ----
  Correct Difference: -(1011) [-11] 
  ```
  
在most significant position發生借位的情況，計算結果可表示為:
$M - N + 2^n$

其中額外加上的$2^n$為借位到most significant position的值。接著，我們想要的數量(magnitude)是$N-M$；可以透過$2^n$減掉上式得到：
$2^n - (M-N+2^n) = N-M$
> :thinking_face: 上式是不是很面熟？
> 回憶在此補充的開頭, 提到[可用一個圓來表示可表示的值](https://hackmd.io/kKdARrp2RaGL6vIjqifwjw?both#Figure-21-depicts-the-assignment-of-values-to-bit-patterns-for-a-4-bit-signed-magnitude-format):
> > 如[^first]於§2.4 TWO's- AND 1'S-COMPLEMENT NUMBERS的附圖 Fig. 2.5:
![](https://hackmd.io/_uploads/SkQqxClDq.jpg)

:star: 小結兩個n-digit numbers的減法的步驟如下：
:::success
$M-N$, in base *2* can be done as follows: 
  1. Subtract the subtrahead $N$ from the minuend $M$
  2. **If no end borrow occurs**, $M \geq N$, and the result is nonnegtive and correct
  3. **If an end borrow occurs**, then $N > M$, and different, $M - N + 2^n$, is substracted from $2^n$, and a minus sign different to the result 
:::
  
:thinking_face: 此方法硬體如何實作呢？

需要一個減法器(subtractor)來做初始的減法；此外，當最高位發生借位時，為了更正數量(利用$N-M$)，需要再次使用減法器，或是另外提供一個2's complemeter circuit。

介紹至此(thus far), 實作**加法**和**減法**, 我們會需要一個減法器(subtractor), 一個加法器(adder)，可能還需要一個2's complementer。對應的block diagram如下：
![](https://hackmd.io/_uploads/By-yx1ZP9.jpg)
從上圖；值得一提的是inputs A與B是一起應用在adder及substractor，所以兩個運算可以同時進行。最後再透過multiplexer來決定要用哪邊的輸出。
- :::info
  此circuit是否有機會可以再簡化呢？可以的。我們想要共用同一個logic來實現addr及substrator，==可以利用`complement`的想法(notion)==，讓我們繼續看下去。
  :::
  
--- 

==**Complements**==
> 理論的部份可參考閱讀Jserv老師的[解讀計算機編碼](https://hackmd.io/@sysprog/binary-representation#tip1)
> 此筆記列出老師沒提及的部份或補充，主要著重在如何用硬體實作`complements`

There are two types of complements for each base-*r* system:
- the *radix complement*, which we saw earlier for base 2, is referred to *r's complment*; and
- the *diminished* radix complement, as the *(r-1)'s complement* 
  > diminished: *to make something smaller or less*
  
**1's complement**
- ++Definition++: given a number *N* in binary having n digits, the *1's complement of N* is defined as $(2^n - 1) - N$
  - :thinking_face: (recall) representation of the 1's complement is −(2^N−1^ − 1) to (2^N−1^ − 1)
    > 其中正數與負數各`-1`的部份是用來表示`+0`和`-0`
  - 於[^first] §2.4 TWO's- AND 1'S-COMPLEMENT NUMBERS，另一個用圓表示1's complement的附圖 Fig. 2.6:
    ![](https://i.imgur.com/ebBx9eb.jpg)
    > 從該分隔線可以觀察到正負兩邊的補數相加的值為(2^n - 1),
    > 例如： $-0 + 0 = 1111 + 0000 = 1111$；故`-0`的補數為$1111 - 1111 = 0000 = 0$。
- ++Hardware implementation++ 
  承上述，因為(2^n^ - 1)為一個*n*個1組成的二進數；對欲計算補數的二進數*N*做bitwise減法，每個位元值計算是$1 - 0 = 1$或$1 - 1 = 0$，也就是將原來的bit從`1`變成`0`或從`0`變成`1`。
  --> 可應用**NOT 或 compelement 運算**來實作
  
**2's complement**
- ++Definition++: given an *n*-digit number N in binary, the 2's complement of N is defined as $2^n - N\ for\ N\neq0\ and\ 0\ for\ N= 0$.
  > repost: Fig. 2.5 A 4-bit, 2's-complement number representation system for integers in [^first] 
  > ![](https://hackmd.io/_uploads/SkQqxClDq.jpg)
  > > 除了`0`(唯一且無補數)，從該分隔線可以觀察到正負兩邊的補數相加的值為(2^n),
  > > 例如： $1 + (-1) = 0001 + 1為$10000 - 0001 = 1111 = (-1)$。

- ++The reason for the special case of N = 0++ 
  is that the result must have n bits, and subtraction of 0 from 2^n^ gives an (*n* + 1)-bit result, 100...0. 
  > 以4-bit為例，$2^n - 0 = 1_0000 - 0_0000 = 1_0000$
  
  此special case可以用一個*n*-bit subtractor或是drop掉超出範圍的`1`。

- Comparing with the 1's complement
  2's complement can be obtained by *adding 1 to the 1's complement value*, since $2^n - N = {[(2^n - 1) - N] + 1}$, noting that `[(2^n - 1) - N]` is 1's complement of *N*。
  
- 上述觀念在其他bases上亦適用，更可用於簡化2's complement及減法的硬體 

- 有另一個方式亦可求出2's complement
  從最低位往最高位，找到第一個1的所在位元；該位元與比它低位的0's(least significant 0's)都不需變動，而比該位元高的位元(all other higher significant bits)，做位元反轉。如下例:
  ```
  N:                   1101*1*00
  2's complement of N: 0010 1 00    
  ```
  - [ ] How to prove this method?

### (TO-STUDY) §5.4

[^first]: _Computer Arithmetic: Algorithms and Hardware Designs_, B. Parhami; Oxford University Press, 2001

###### tags: `note` `logic-design`
