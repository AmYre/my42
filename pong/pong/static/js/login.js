document.addEventListener("DOMContentLoaded", () => {
	const urlParams = new URLSearchParams(window.location.search);
	const code = urlParams.get("code");

	function getCookie(name) {
		let cookieValue = null;
		if (document.cookie && document.cookie !== "") {
			const cookies = document.cookie.split(";");
			for (let i = 0; i < cookies.length; i++) {
				const cookie = cookies[i].trim();
				if (cookie.substring(0, name.length + 1) === name + "=") {
					cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
					break;
				}
			}
		}
		return cookieValue;
	}

	const savedState = localStorage.getItem("pongAppState");
	if (savedState) {
		const parsedState = JSON.parse(savedState);
		Object.assign(AppState, parsedState);
		renderStep(AppState.currentStep);
	} else {
		if (code) {
			fetch("/api/auth/", {
				method: "POST",
				credentials: 'include',
				headers: {
					"Content-Type": "application/json",
					"X-CSRFToken": getCookie("csrftoken"),
				},
				body: JSON.stringify({ code: code }),
			})
			.then((response) => response.json())
			.then((data) => {
				if (data.error) {
					console.error("Error:", data.error);
				} else {
					console.log("Success:", data);
					localStorage.setItem("user", JSON.stringify(data));
					updateState({ currentStep: 1, user: data});
				}
			})
			.catch((error) => {
				console.error("Error:", error);
			});
		}
	}
});
