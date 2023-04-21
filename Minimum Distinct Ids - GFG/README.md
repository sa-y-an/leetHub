# Minimum Distinct Ids
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array of items, the i'th index element denotes the item id’s and given a number m, the task is to remove m elements such that there should be minimum distinct id’s left. Print the number of distinct id’s.</span></p>

<p><span style="font-size:18px"><strong>Example 1 -</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>:
n = 6
arr[] = {2, 2, 1, 3, 3, 3}
m = 3
<strong>Output</strong>:
1
<strong>Explanation :</strong> 
Remove 2,2,1</span></pre>

<p><span style="font-size:18px"><strong>Example 2 -</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>:
n = 8
arr[] = {2, 4, 1, 5, 3, 5, 1, 3}
m = 2
<strong>Output</strong>:
3
<strong>Explanation</strong>:
Remove 2,4</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. You don't have to take any input. Your task is to complete the <strong>distinctIds</strong>() which takes sorted array, its size n, and m as its parameter. You only need to find the minimum number of distinct IDs&nbsp;and return it. The driver code will print the returned value.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity</strong>: O(n log(n))<br>
<strong>Expected Auxillary Space</strong>: O(n)</span></p>

<p><span style="font-size:18px"><strong>Constraints</strong>:<br>
1 ≤ n ≤ 10<sup>5</sup><br>
1 ≤ arr[i] ≤ 10<sup>6</sup><br>
1 ≤ m ≤ 10<sup>3</sup></span></p>
 <p></p>
            </div>