#!/usr/bin/env node
const { log } = require("console");
const fs = require("fs");
const process = require("process");

const dir = process.env.DIR;
console.log("ENV", dir);

function listFiles(directory) {
	return new Promise((resolve, reject) => {
		fs.readdir(directory, (err, items) => {
			if (err) {
				return reject(err);
			}
			const itemList = {};
			items.forEach((item) => {
				const itemPath = directory + "/" + item;
				const stats = fs.statSync(itemPath);
				if (stats.isFile()) {
					itemList[item] = "file";
				} else if (stats.isDirectory()) {
					itemList[item] = "dir";
				}
			});
			resolve(itemList);
		});
	});
}

listFiles("." + dir)
	.then((files) => {
		fs.writeFile("./static/autoindex/list.json", JSON.stringify(files, null, 2), (err) => {
			if (err) {
				console.error("Error writing JSON file:", err);
			} else {
				console.log(JSON.stringify({ message: "JSON file created successfully", files: files }));
			}
		});
	})
	.catch((err) => {
		console.error("Error listing files:", err);
	});
