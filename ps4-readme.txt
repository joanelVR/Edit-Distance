1;3201;0c/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name:   Joanel Vasquez
Login:    jvasque1


Hours to complete assignment (optional):  It took me about  a whole day to complete everything. 
												I used Needleman-Wunsch implementation


/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/

To find the alignment, I first looked at the characters at the [0][0] position and if they matched, 
then I move diagonally (i++,j++). If not, then I look to the right and down and if either of those 
positions + 2 matched the current position, I would add them to the string and a "-" depending 
on which way it chose, and either move to the right or down. If non of these were met, then I 
moved diagonally . 

/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
:w
Input: endgaps7.txt 

Expected output: 4

What happened: 
My code worked! The edit distance obtained from this was 4, which matched 
the expected output, with execution time of 0.000316 seconds.

/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2 GB to 16 GB.
 **********************************************************************/

My computer has 8 GB of ram, but I only allocated 3 GB for 
VirtualBox (Lubuntu used for this assignment). 

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 4.341
b = 1.9853
largest N = 46457 (rounded)

In order to get the numbers above, I used ecoli2500.txt, ecoli5000.txt, ecoli7000.txt, 
ecoli10000.txt and ecoli20000.txt because these provide N=M size for the strings. 
I used the numbers obtained for the memory of each of these text files and plotted
them in excel against their respective size. I fit a power function as the best fit line and 
got the values for "a" and "b" above. In order to solve for N, I solved the equation y = a*N^b
for N and got N = (y/a)^(1/b). I used this equation for y = 8GB to solve for N.
--------------------------------FOR EXCEL FILE, SEE THE PROVIDED FILES---------------------------------------

/**********************************************************************
 *  Were you able to run Valgrind's massif tool to verify that your
 *  implementation uses the expected amount of memory?
 *
 *  Answer yes, no, I didn't try, I tried and failed, or I used a 
 *  different tool.
 *
 *  If yes, paste in the ms_print top chart of memory use over time,
 *  and also indicate which file your code was solving.
 * 
 *  Explain if necessary.
/**********************************************************************
1 - Yes! I used valgrind's massiff too

2- The following top chart is for endgaps7.txt (massif.out.1764)
----------------------------------------------------------------------------------------------------------------------------------
  n        time(i)         	   total(B)   		useful-heap(B) 	extra-heap(B)    	stacks(B)
----------------------------------------------------------------------------------------------------------------------------------
  0              0                		0               	 	     0             			    0          		      0
  1      2,217,776           72,712           		72,704             		    8           		      0
  2      2,364,064           72,784           		72,768            		   16 		              0
  3      2,364,120           72,824           		72,800           		   24	   	              0
  4      2,364,175           72,864           		72,832            		   32		              0
  5      2,364,230           72,904           		72,864          		   40 		              0
  6      2,364,285           72,944           		72,896           		   48 		              0
  7      2,364,340           72,984           		72,928            		   56		              0
  8      2,364,395           73,024           		72,960            		   64        		      0
  9      2,364,450           73,064           		72,992            		   72      			      0


/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           		     distance       time (seconds)     memory (MB)	  massif.out.
--------------------------------------------------------------------------------------------------------------------------------
ecoli2500.txt			 118		     0.050291	 	    24.08	    		1774
ecoli5000.txt			 160		     0.106328		    95.78			1781
ecoli7000.txt			 194		     0.120841		    187.5			1789
ecoli10000.txt		 223		     0.185124	   	    382.2			1797
ecoli20000.txt		3135		     0.343525		    1491				1804
ecoli28284.txt		8394		     0.506139 	     	    2982 				1811

Fill out the data here first, then go to the assignment web page for
instructions on sharing your data on iSENSE.

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730

/**********************************************************************
 *  Enter your data onto iSENSE per the directions on the course web
 *  site. Then, paste a URL to your data set here.
 *
 *  YOU WILL ONLY RECEIVE CREDIT FOR YOUR iSENSE WORK IF YOU PROVIDE
 *  THE URL HERE.
 *
 *  e.g.: http://isenseproject.org/projects/871/data_sets/7893
 ************************************************************************/

THIS WAS NOT REQUIRED BY THE INSTRUCTOR FOR OUR CLASS

/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 4.00E-05
b = 0.9116
largest N = 17363518182 (Exact) 

I applied the doubling method to the data points by only taking the data points 
in which N would double. This means that the files that I used were ecoli2500.txt, 
ecoli5000.txt, ecoli10000.txt and ecoli20000.txt. Once I knew which files to use, I
used their respective running time and I plotted them in excel against their string 
size(N). The same steps taken in order to calculate  "the largest N that my program 
can handle if it is limited to 8GB (billion bytes) of memory" in the section above were
taken in order to calculate the largest N of my program if it's limited to 1 day of computation.
--------------------------------FOR EXCEL FILE, SEE THE PROVIDED FILES---------------------------------------

/**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/

I recieved some help from a friend with the alignment function.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

One problem that I encountered was that I was getting a core dump error. This
was because I was using the wrong size. The  implementation of the alignment 
function also created some problems for me.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A
