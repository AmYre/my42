#!/usr/bin/env node

const { log } = require("console");
const process = require("process");
// const fs = require("fs");

// const logFile = fs.createWriteStream("./log.txt", { flags: "a" });
const path = process.env.PATH_INFO;

console.log(`CGI - GET method : access granted for : ${path}`);

// while (true) {}

// fs.readFile("do not exist path", "utf8", (err, data) => {
// 	logFile.write(err.toString() + "\n");
// });
