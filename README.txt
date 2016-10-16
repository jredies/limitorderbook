1) Compiling and Testing

Create Makefile with CMake:

cmake -DCMAKE_BUILD_TYPE=Release .


Compiling:

make

Testing:

Assuming the input files have been unpacked into the folder ./logs/ the following command will
create all output files:

./test.sh

Then, none of these should be different:

diff logs/small.out.200 logs/small_my.out.200
diff logs/pricer.out.1 logs/pricer_my.out.1
diff logs/pricer.out.200 logs/pricer_my.out.200
diff logs/pricer.out.10000 logs/pricer_my.out.10000


2) Performance

On my machine (MacBook Pro 2016), I get the following run times (with compiler optimiser flags).

You can get the numbers by changing the #define DEBUG false to true. Keep in mind that this
switches off the actual STDOUT to get a more representative number for the simulation.

$ cat logs/pricer.in | ./pricer 1
Read 1.57919 s
Parsing 2.17874 s
Simulation 0.53016 s

$ cat logs/pricer.in | ./pricer 200
Read 1.58274 s
Parsing 2.18435 s
Simulation 0.59895 s

$ cat logs/pricer.in | ./pricer 10000
Read 1.58356 s
Parsing 2.20527 s
Simulation 0.856476 s

Most of the time is lost in IO and Parsing.

Reading from STDIN has to be done sequentially. This could be improved by reading directly from a
file instead.

There are a couple of ways to make the parsing faster. The slow operations in parsing are the
conversions from string to long and the string splitting. For conversion I opted for
boost spirit qi (cf. [1]). I think there is more room for improvement, see for example [2].
For the string splitting I used boost::split which turned out to be faster than boost::tokenizer.
There are several threads (cf. [3]) and discussions whether or not to use strtok. I made the
decision to stay with a more C++11/Boost design.

For the simulation part we could experiment with different data structures. The slow part is the
map that orders the price levels. In most C++ implementations map is implemented as a Red-Black
Tree. There could be a performance boost in using something different (like Treap [4]).

3) Theoretical Performance

The insert and find  average complexity is O(log n) for map and O(1) for unordered_map
respectively. The insert and find worst case complexity is O(log n) for map and O(n) for
unordered_map respectively.

Let p be the number of distinct prices, and n be the of number orders in the book:

For insert and remove into the Book:

Average: O(log p) * O(1)
Worst: O(log p) * O(n)

For the worst case, a majority of the orders are on one price level and there are collisions that
result in linear performance in the HashMap. The latter is statistically very unlikely.

Worst case complexity to find the best price is O(p).


[1] http://alexott.blogspot.co.uk/2010/01/boostspirit2-vs-atoi.html
[2] https://tombarta.wordpress.com/2008/04/23/specializing-atoi/
[3] http://stackoverflow.com/questions/9378500/why-is-splitting-a-string-slower-in-c-than-python
[4] https://en.wikipedia.org/wiki/Treap
