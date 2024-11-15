#!/usr/bin/env node

const querystring = require("querystring");
const fs = require("fs");
const logFile = fs.createWriteStream("./log.txt", { flags: "a" });

let body = "";
process.stdin.setEncoding("utf8");

process.stdin.on("data", (chunk) => {
	body += chunk;
});

process.stdin.on("end", () => {
	logFile.write(`Received data: ${body}\n`);
	const postData = querystring.parse(body);

	const name = postData.name || "Unknown";
	const login = postData.login || "Unknown";
	const like = postData.like || "Unknown";

	fs.readFile("./static/post/post.html", "utf8", (err, template) => {
		if (err) {
			console.error("Failed to read template:", err);
			process.exit(1);
		}

		let htmlContent = template.replace("{{name}}", name).replace("{{login}}", login).replace("{{like}}", like);

		process.stdout.on("error", (err) => {
			if (err.code === "EPIPE") {
				logFile.write("Client closed the connection\n");
			} else {
				logFile.write(`Error: ${err}\n`);
			}
			logFile.end();
			process.exit(1);
		});

		process.stdout.write("HTTP/1.1 200 OK\r\n");
		process.stdout.write("Content-Length: " + Buffer.byteLength(htmlContent) + "\r\n");
		process.stdout.write("Content-Type: text/html\r\n");
		process.stdout.write("\r\n");
		process.stdout.write(htmlContent);
	});
});
