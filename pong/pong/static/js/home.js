let AppState = {
	currentStep: 0,
	user: {},
	score: 0,
	user2: "",
	score2: 0,
	user3: "",
	score3: 0,
	mode: "",
	winner: "",
	game: 0,
	leftScore: 0,
	rightScore: 0,
	options: {},
};

// Views configuration
let views = {
	1: { path: "/static/pages/mode.html" },
	2: { path: "/static/pages/game.html" },
	3: { path: "/static/pages/results.html" },
};

// Fetch and render HTML content
async function fetchView(path) {
	try {
		const response = await fetch(path);
		if (!response.ok) throw new Error(`HTTP error! status: ${response.status}`);
		return await response.text();
	} catch (error) {
		console.error("Error loading view:", error);
		return "<p>Error loading content</p>";
	}
}

// Execute scripts in the content
function execScripts(content) {
	const scripts = content.getElementsByTagName("script");
	Array.from(scripts).forEach((script) => {
		const newScript = document.createElement("script");
		Array.from(script.attributes).forEach((attr) => newScript.setAttribute(attr.name, attr.value));
		newScript.textContent = script.textContent;
		script.parentNode.replaceChild(newScript, script);
	});
}

// State management functions
async function updateState(newState) {
	Object.assign(AppState, newState);
	localStorage.setItem("pongAppState", JSON.stringify(AppState));

	// If the step is changing, update browser history
	if (newState.currentStep !== undefined) {
		window.history.pushState({ step: newState.currentStep }, "", "/");
	}

	await renderCurrentStep(newState.currentStep);
}

async function renderCurrentStep(step) {
	let state = JSON.parse(localStorage.getItem("pongAppState"));
	if (!state || !state.user || !state.user.login || !state.user.login.length) {
        localStorage.clear();
        window.history.replaceState(null, "", "/");
        window.location.reload();
        return;
    }

	const mainContent = document.body;
	const view = views[step];
	if (!view) return;

	const html = await fetchView(view.path);
	mainContent.innerHTML = html;
	execScripts(mainContent);
}

async function renderStep(step) {
	const mainContent = document.body;
	const view = views[step];
	if (!view) return;
	Object.assign(AppState, { currentStep: step });
	localStorage.setItem("pongAppState", JSON.stringify(AppState));
	window.history.pushState({ step: step }, "", "/");
	// Fetch and process the HTML content
	const html = await fetchView(view.path);
	mainContent.innerHTML = html;
	execScripts(mainContent);
}

// Navigation functions
function nextStep() {
	if (AppState.currentStep < Object.keys(views).length) {
		updateState({ currentStep: AppState.currentStep + 1 });
	}
}

function previousStep() {
	if (AppState.currentStep > 0) {
		updateState({ currentStep: AppState.currentStep - 1 });
	}
}

async function logOut() {
	fetch("/api/logout/", {
		method: "POST",
		credentials: "include",
		headers: {
			"Content-Type": "application/json",
			"X-CSRFToken": getCookie("csrftoken"),
		},
	})
		.then(() => {
				localStorage.clear();
				sessionStorage.clear();
				window.history.replaceState(null, "", "/");
				window.location.href = "/";
			})
		.catch((error) => {
			console.error("Error:", error);
		});
}

function logOutDash() {
	fetch("/api/logout/", {
		method: "POST",
		credentials: "include",
		headers: {
			"Content-Type": "application/json",
			"X-CSRFToken": getCookie("csrftoken"),
		},
	})
		.then(() => {
				localStorage.clear();
				sessionStorage.clear();
				window.history.replaceState(null, "", "/");
				window.location.href = "/";
			})
		.catch((error) => {
			console.error("Error:", error);
		});
}

function optionsDash() {
	let state = JSON.parse(localStorage.getItem("pongAppState"));
	if (!state || !state.user || !state.user.login || !state.user.login.length) {
		logOut();
		return;
	}
	state.currentStep = 1;
	localStorage.setItem("pongAppState", JSON.stringify(state));
	window.history.pushState({ step: 1 }, "", "/");
	window.location.href = "/";
}

// Handle browser back/forward buttons
window.addEventListener("popstate", (event) => {
	// Get the step from the event state, fallback to 0 if not found
	const step = event.state?.step ?? 0;

	// Update AppState without pushing to history (to avoid loops)
	Object.assign(AppState, { currentStep: step });
	renderCurrentStep(step);
});
