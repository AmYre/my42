# NetPractice

This project is about connecting people (i.e. Network and Subnetting). Sponsored by Nokia_3310
<p align="center">
  <img src="(https://raw.githubusercontent.com/AmYre/my42/master/netpractice/giphy.gif)" width="100%"/>
</p>

## How was it?

I always feared network infra, sysadmin stuff. It feels like it is to low level for me, unreachable.
But this project proved once again, that Knowledge is Fear's greatest enemy. I loved this project !
It was very didactic. I was playing found the subnet game all along 😁.
Plus, it was a good pretext to see all about OSI layer model, the different protocols, and globally how internet magic works behind the scene.

The evaluation in the other hand can be quite stressfull. You only have 15 minutes to achieve live 3 subnetting exercices.
So master this one skill and you will be fine :
IP address : 124.145.110.28
Subnet mask: 255.255.255.128

1 - You go from the subnet mask number of interest (not 255, not 0), in our case => 128
2 - From it you go to 256. So 128 to go to 256 there is 128 to add. You have your magic number.
3 - Ask yourself in what range of 128 the number of interest of the ip address (parallel to the mask => 28) can be on ?
=> 28 can be contained between 0-128. So you have it.
Network address   = 124.145.110.0
Broadcast address = 124.145.110.128
Usable range addresses = 124.145.110.1 --- 124.145.110.127



## Another example to do Subnetting with the Magic Number

You open your subnetting exercice and it gives you this :
IP address : 153.63.181.254
Subnet mask: 255.255.192.0

1 - You go from the subnet mask number of interest (not 255, not 0), in our case => 192
2 - From it you go to 256. So 192 to go to 256 there is 64 to add. You have your magic number => 64.
3 - Ask yourself in what range of 64 the number of interest of the ip address (parallel to the mask => 181) can be on ?
The ranges of 64 you have to imagine in your mind : 0-64-128-192-256
=> 181 can be contained between 128-192. So you have it.
Network address   = 153.63.128.0
Broadcast address = 153.63.192.0
Usable range addresses = 124.145.128.1 --- 124.145.191.255

With this technique the apparent mystical shenanigans of Netpractice becomes crystal clear. You see everything.


## The Ressources used

To grasp all the kmowledge around Subnetting, like Binary conversion, CIDR table etc.. i found an amazing playlist
that talks about network with refreshing pov. The ressources in this filed are so dusty. People so not fun... This playlist is quite unique :
-   [Youtube - You Suck at Subnetting](https://www.youtube.com/watch?v=5WfiTHiU4x8&list=PLIhvC56v63IKrRHh3gvZZBAGvsvOhwrRF)

I learned the magic recipe in here :
-   [Youtube - Magic Number](https://www.youtube.com/watch?v=XMzLpGKTu50&t=851s)
