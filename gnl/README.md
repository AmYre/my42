# GetNextLine

This project is about learning to handle how to read files properly on a system.
You will have to read content from a file descriptor and returning it line by line.


## What take away ?

For me that was the use of a linked list. As main data structure storage to be the core of the function. 
The project let you choose your own approach. Linked list seemed very appropriate to handle the mechanism of gathering all the chunks of a line.
I wanned to decompose each chunk of a line in their own node list. That list when completed means that we have a line. And push that new line in an other list who stores the actual lines.
Having those two entities, made sense for me and gave the code a nice reabability. But the project is constrained by having only 2 files, with 5 functions each, less than 25 lines each...

So i had to rewrote it a second time, using a more concise way, less readable and less meaningfull. I guess in tech we have a habit of concise code being "better code".
But either way, it was very satisfynig to really use linked list, as we just had been introduced to it in the libft's bonuses.


## The Ressources used

### For a visual explanation of what is expected from you

-   [Nikito Youtube](https://www.youtube.com/watch?v=-Mt2FdJjVno&)

### For a version with one linked list and norm ready

-   [Nikito Y](https://www.youtube.com/watch?v=xgDSXNOHTIA) - I feel very lucky to have this guy one year ahead, with his very well produced youtube videos and normal stud tone. Just casualy sharing his stud experience.
