# Philosophers

This project is about eating with two forks (i.e. using Threads and Mutexes).
<p align="center">
  <img src="https://raw.githubusercontent.com/AmYre/my42/master/philo.png" width="100%"/>
</p>

## How was it?

It felt nice to do a 'regular' project after minishell. Learning new things again ! Or should I say, complete our knowledge on concurrency.
We saw forks and pipes previously. Here we see another way to do parrallel computing with threads that can share data between them.
This sharing of ressources is a big plus compared to the isolated processes. But it needs to be handled with care. Since threads could read an write the same variables at the same time,
you will have to protect their access with "locks".

## The pitfalls you want to know about and will encounter

-  Conceptualize a struct or structs that can handle both forks for each philo and shared data
-  Calculation with long ints have a special LL syntax : current_time() * 1000LL
-  Be able to end the simulation when a philo died in less than 10ms but leave the simulation live if a max_meals option is set
-  Not be fooled by the sleep function, and rewrite a function that can sleep + can check every so often the state of the simulation
-  Create a separated monitor that has his own infinite while loop to check the state of the simulation frequently without messing with the frequence of the threads.
-  Passing valgrind hellgrind warnings by shifting the order of the forks the philo takes to eat (even philos take their forks and their neighbours for example, and odd takes their neighbours first ans then their own)


## The Ressources used

To grasp all the new functions we discover in this project i went to my favorite C love provider :

-   [Youtube - CodeVault](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY) join them on Discord => https://discord.com/invite/NFxT8NY
