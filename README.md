Here's the translation of the Markdown file into English:

```markdown
# Curve Fitting

Below we show the result of fitting the curve $f(x) = \sin(2x) \cos(x/2)$ in the interval $x \in [-5, 5]$. The sequence was created using degrees $n = 3, 5, 7, 9, 11, 13, \text{ and } 15$.

<p align="center">
  <img width="320" height="240" src="curve_animation.gif">
</p>

In this work, we chose the **canonical basis = { $1, x, x^2, \dots, x^n$ }** of the space $\mathbb{P}_n(x)$.

Thus, we have $$f(x) \approx a_0 + a_1 x + a_2 x^2 + \dots + a_n x^n$$

The value of each coefficient is given by the system

<p align="center">
<img src="https://latex.codecogs.com/gif.latex?%5Cbegin%7Bpmatrix%7D%20%3C1%2C1%3E%20%26%20%3C1%2Cx%3E%20%26%20%3C1%2Cx%5E2%3E%20%26%5Cdots%20%26%20%3C1%2Cx%5En%3E%20%5C%5C%20%3Cx%2C1%3E%20%26%20%3Cx%2Cx%3E%20%26%20%3Cx%2Cx%5E2%3E%20%26%20%5Cdots%20%26%20%3Cx%2Cx%5En%3E%5C%5C%20%3Cx%5E2%2C1%3E%20%26%20%3Cx%5E2%2Cx%3E%20%26%20%3Cx%5E2%2Cx%5E2%3E%20%26%20%5Cdots%20%26%20%3Cx%5E2%2Cx%5En%3E%5C%5C%20%5Cvdots%26%5Cvdots%26%5Cvdots%26%5Cddots%26%5Cvdots%5C%5C%20%3Cx%5En%2C1%3E%20%26%20%3Cx%5En%2Cx%3E%20%26%20%3Cx%5En%2Cx%5E2%3E%20%26%20%5Cdots%20%26%20%3Cx%5En%2Cx%5En%3E%20%5Cend%7Bpmatrix%7D%20%5Cbegin%7Bpmatrix%7D%20a_o%5C%5Ca_1%5C%5Ca_2%5C%5C%5Cvdots%5C%5Ca_n%20%5Cend%7Bpmatrix%7D%3D%20%5Cbegin%7Bpmatrix%7D%20%3Cf%28x%29%2C1%3E%5C%5C%20%3Cf%28x%29%2Cx%3E%5C%5C%20%3Cf%28x%29%2Cx%5E2%3E%5C%5C%20%5Cvdots%5C%5C%20%3Cf%28x%29%2Cx%5En%3E%20%5Cend%7Bpmatrix%7D">
</p>

Remember that as we are fitting the function $f(x)$ in the interval $x \in [-5,5]$, the inner product will be given by the formula

<p align="center">
<img src="https://latex.codecogs.com/gif.latex?%3Cf%2Cg%3E%3D%5Cint_%7B-5%7D%5E5%20f%28x%29g%28x%29%20dx">
</p>
```