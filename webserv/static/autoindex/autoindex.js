document.addEventListener("DOMContentLoaded", function () {
	const path = window.location.pathname;
	const segments = path.split("/");
	const dir = segments[segments.length - 1] || segments[segments.length - 2];
	const ul = document.getElementById("list");
	const h1 = document.getElementsByTagName("h1")[0];
	h1.textContent = "Index of /" + dir;

	const loadingLi = document.createElement("li");
	loadingLi.textContent = "Loading...";
	ul.appendChild(loadingLi);

	function loadFiles() {
		setTimeout(() => {
			fetch("/static/autoindex/list.json")
				.then((response) => {
					if (!response.ok) {
						throw new Error(`HTTP error! status: ${response.status}`);
					}
					return response.json();
				})
				.then((files) => {
					ul.innerHTML = "";

					if (Object.keys(files).length === 0) {
						const emptyLi = document.createElement("li");
						emptyLi.textContent = "No files found.";
						ul.appendChild(emptyLi);
						return;
					}

					Object.entries(files).forEach(([file, type]) => {
						const li = document.createElement("li");
						const a = document.createElement("a");
						if (["static", "public", "assets"].includes(dir)) {
							a.href = file;
						} else if (path.endsWith("/")) {
							a.href = file;
						} else {
							a.href = `${dir}/${file}`;
						}

						a.textContent = `  ${file}`;

						const i = document.createElement("i");
						i.classList.add("fa-solid");

						if (type === "file") {
							i.classList.add("fa-file");
						} else if (type === "dir") {
							i.classList.add("fa-folder");
						}

						a.prepend(i);
						li.appendChild(a);
						ul.appendChild(li);
					});
				})
				.catch((error) => {
					console.error("Error loading files:", error);
					ul.innerHTML = `<li>Error loading files: ${error.message}</li>`;
				});
		}, 100);
	}

	loadFiles();
});
