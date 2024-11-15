document.addEventListener("DOMContentLoaded", function () {
	const fileList = document.getElementById("fileList");

	setTimeout(() => {
		loadFiles();
		const loading = document.getElementById("loading-bar-spinner");
		loading.style.display = "none";
	}, 500);

	function loadFiles() {
		fetch("/static/del/list.json")
			.then((response) => response.json())
			.then((files) => {
				files.forEach((file) => {
					const div = document.createElement("div");
					const input = document.createElement("input");
					const label = document.createElement("label");
					const i = document.createElement("i");
					const link = document.createElement("a");
					link.id = "downloadButton";
					link.href = `/public/${file}`;
					link.download = file;
					i.classList.add("fa-solid", "fa-download");
					input.type = "radio";
					input.name = "file";
					input.value = file;
					input.id = file;
					label.htmlFor = file;
					input.textContent = file;
					label.textContent = file;
					div.appendChild(input);
					div.appendChild(label);
					div.appendChild(link);
					link.appendChild(i);
					fileList.appendChild(div);
				});
			})
			.catch((error) => console.error("Error loading files:", error));
	}

	const deleteButton = document.getElementById("submit");
	deleteButton.addEventListener("click", function () {
		const selectedRadio = document.querySelector('input[name="file"]:checked');
		if (selectedRadio) {
			const selectedFile = selectedRadio.value;
			console.log("Selected file:", selectedFile);

			fetch(`/public/${selectedFile}`, {
				method: "DELETE",
			})
				.then((response) => {
					if (response.ok) {
						confetti({
							particleCount: 100,
							spread: 70,
							origin: { y: 0.6 },
						});

						confetti();
						alert("File deleted successfully.");
						setTimeout(() => {
							location.reload();
						}, 500);
					} else {
						alert("Error deleting file.");
					}
				})
				.catch((error) => {
					console.error("Error:", error);
					alert("Error deleting file.");
				});
		} else {
			console.log("No file selected");
		}
	});
});
