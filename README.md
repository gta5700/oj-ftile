# oj-ftile

ftile(fixed_count) 
  simple postgresql window function, 
  integer counting from 1, dividing the partition in "subpartitions" each with fixed_count rows

compiled and tested on win7 and postgresql 9.6,
but shoud work on other versions too.


SELECT  x,  ftile(3) OVER () as ftile
FROM generate_series(1, 15) x
ORDER BY x


x   ftile
1     1

2     1

3     1

4     2
5     2
6     2
7     3
8     3
9     3
10    4
11    4
12    4
13    5  
14    5
15    5


SELECT  x, (x % 2) as part, ftile(4) OVER (PARTITION BY (x % 2) ORDER BY random()) as ftile
FROM generate_series(1, 15) x
ORDER BY part, ftile

x   part  ftile
14		0		  1
12		0		  1
2		  0		  1
6		  0		  1
10		0	  	2
8		  0		  2
4		  0		  2
11		1		  1
1		  1	  	1
13		1		  1 
3		  1		  1
9		  1	  	2
15		1		  2
5		  1		  2
7		  1		  2




