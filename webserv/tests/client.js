const http = require("http");

const numRequests = 1000; // Nombre total de requêtes à envoyer
const concurrency = 100; // Nombre de requêtes concurrentes
const url = "http://localhost:5000"; // URL de votre serveur web

let completedRequests = 0;

function sendRequest() {
	http.get(url, (res) => {
		res.on("data", () => {}); // Consommer les données de réponse
		res.on("end", () => {
			completedRequests++;
			if (completedRequests % concurrency === 0) {
				console.log(`Completed ${completedRequests} requests`);
			}
			if (completedRequests < numRequests) {
				sendRequest();
			}
		});
	}).on("error", (e) => {
		console.error(`Got error: ${e.message}`);
	});
}

// Lancer les requêtes concurrentes
for (let i = 0; i < concurrency; i++) {
	sendRequest();
}
