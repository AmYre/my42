#!/usr/bin/env node

const fs = require("fs");

function listFiles(directory) {
	return new Promise((resolve, reject) => {
		fs.readdir(directory, (err, files) => {
			if (err) {
				return reject(err);
			}
			const fileList = [];
			files.forEach((file) => {
				if (fs.statSync(directory + file).isFile()) {
					fileList.push(file);
				}
			});
			resolve(fileList);
		});
	});
}

listFiles("./public/")
	.then((files) => {
		fs.writeFile("./static/del/list.json", JSON.stringify(files, null, 2), (err) => {
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
