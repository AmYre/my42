# WEBSERV

A deep dive into sockets, CGI and HTTP protocol

<p align="center">
  <img src="https://raw.githubusercontent.com/AmYre/my42/master/home.png" width="100%"/>
</p>

## How was it?

What a project. The best I had to do yet. I learned so much about something we use everyday without really noticing how it works.<br/>
In Webserv we had to create a HTTP Server that listens to client requests, handles them and gives them a response back. <br/><br/>
To keep the server at high availability, we want it to focus on just one task: serving the requested resources.<br/>
So if something else has to be done, like large upload files or any other heavy lifting, we used external scripts called CGI for Common Gateway Interface. <br/>
They use ENV or STDIN/STDOUT to share data and are universal enough to be done in any language you want. <br/><br/>
One of the challenges was the config file which complexified the whole project. Taking inspiration from NGNIX, we had to make every element of our server customisable depending on the config chosen by the user. <br/>

<p align="center">
  <img src="https://raw.githubusercontent.com/AmYre/my42/master/get.png" width="50%"/>
</p>
<p align="center">
  <img src="https://raw.githubusercontent.com/AmYre/my42/master/post.png" width="50%"/>
</p>
<br/><br/>
