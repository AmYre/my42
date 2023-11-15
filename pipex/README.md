# Pipex

This project is about being able to reproduce the pipe command.

<p align="center">
  <img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.deviantart.com%2Fmomitty%2Fart%2FWelcome-to-Warp-Zone-20235236&psig=AOvVaw0w49cNuswK7kvfhwGbi2eX&ust=1700161048569000&source=images&cd=vfe&ved=0CBEQjRxqFwoTCPDHns3XxoIDFQAAAAAdAAAAABAT" width="100%"/>
</p>

## How was it?
To execute a command on a program you will have to use the execve() function.
Using the execve function *"destroys"* the main process the execve was in.
So you will have to create and *"sacrifice"* another process using the fork() function.
The problem is, if i have two complete diffrente processes now, how can i communicate between them to share data ??
That when the pipes come in ! See how everything makes sense 😁

I loved the way all this notions are introduced in this project.
Even if it was a lot to take in, and felt like a big step up compared to push_swap/so_long.
It was very interesing to make all the puzzle come together piece by piece.

## How about the bonuses?
The difference between the mandatory and the bonuses is huge. It is like two different projects. I had to re-wrote 80% of my mandatory to achive the bonuses.
The madatory part only expects two commands to pipe. So it do not take you to the full comprehension of the dynamic between pipes, closing fds and waitpid...
The mandatory gives the illusion of piping being very straightforward. But the bonuses reveals the concurrency to be very specific to handle.
And going to minishel without taking the time to understand that concept could be overwhelming.

## The Ressources used

To grasp all the new functions we discover in this project (dup2, fork, pipe, exec, waitpid) i used this fantastic playlist :
-   [Youtube - CodeVault](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY) join them on Discord => https://discord.com/invite/NFxT8NY

And to be able to found the architecture to achieve the multipipe bonuses, i was un-blocked by this brilliant article :
-   [Medium - Herbie](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY) 
