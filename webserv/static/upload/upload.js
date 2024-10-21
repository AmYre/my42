document.addEventListener("DOMContentLoaded", function () {
	document.getElementById("uploadForm").addEventListener("submit", function (event) {
		event.preventDefault();
		const fileInput = document.getElementById("fileInput");
		const file = fileInput.files[0];

		const formData = new FormData();
		formData.append("file", file);

		fetch("/upload", {
			method: "POST",
			body: formData,
		})
			.then((response) => {
				if (!response.ok) {
					console.error("Error uploading file:", response);
					alert("Error uploading file.");
				} else {
					confetti({
						particleCount: 100,
						spread: 70,
						origin: { y: 0.6 },
					});
					let h2 = document.getElementById("response");
					h2.textContent = "File uploaded successfully.";
					confetti();
					setTimeout(() => {
						location.reload();
					}, 1000);
				}
			})
			.catch((error) => {
				console.error("Error uploading file:", error);
				alert("Error uploading file.");
			});
	});
});
