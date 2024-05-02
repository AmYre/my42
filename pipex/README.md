# Pipex

This project is about being able to reproduce the pipe command.

<p align="center">
  <img src="https://i.ytimg.com/vi/edsLBz0_DUc/maxresdefault.jpg" width="100%"/>
</p>

## How was it?

To execute a command on a program you will have to use the execve() function.
Using the execve function _"destroys"_ the main process the execve was in.
So you will have to create and _"sacrifice"_ another process using the fork() function.
The problem is, if I have two complete different processes now, how can I communicate between them to share data ??
That's when the pipes comes in ! See how everything makes sense 😁

I loved the way all this notions were introduced in this project.
Even if it was a lot to take in, and felt like a big step up compared to push_swap/so_long.
It was very interesting to make all the puzzle come together piece by piece.

## How about the bonuses?

The difference between the mandatory and the bonuses is huge. It is like two different projects. I had to re-wrote 80% of my mandatory to achieve the bonuses.
The mandatory part only expects ONE pipe. So it do not take you to the full comprehension of the dynamic between multiple pipes, closing fds and waitpid...
The mandatory gives the illusion of piping being very straightforward. But the bonuses reveals the concurrency to be very specific to handle.
And going to minishel without taking the time to understand that concept could be overwhelming.

## The Ressources used

To grasp all the new functions we discover in this project (dup2, fork, pipe, exec, waitpid) i used this fantastic playlist :

-   [Youtube - CodeVault](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY) join them on Discord => https://discord.com/invite/NFxT8NY

And to be able to found the architecture to achieve the multipipe bonuses, i was un-blocked by this brilliant article :

-   [Medium - Herbie](https://reactive.so/post/42-a-comprehensive-guide-to-pipex)
