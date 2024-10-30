document.addEventListener("DOMContentLoaded", function () {
	function getCookie(name) {
		let cookieArr = document.cookie.split(";");
		for (let i = 0; i < cookieArr.length; i++) {
			let cookiePair = cookieArr[i].split("=");
			if (name == cookiePair[0].trim()) {
				return decodeURIComponent(cookiePair[1]);
			}
		}
		return null;
	}

	let sessionId = getCookie("session_id");
	if (sessionId) {
		document.querySelector("h2.font").textContent = "Id is " + sessionId;
	}
});
