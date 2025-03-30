function displayPlayers() {
	const versus = document.getElementById("versus");
	const p1 = document.getElementById("footerP1");
	const p2 = document.getElementById("footerP2");
	const p3 = document.getElementById("footerP3");
	const state = JSON.parse(localStorage.getItem("pongAppState"));
	if (!state || !state.user || !state.mode || !state.user.login.length) {
		logOut();
		return;
	}
	const mode = state?.mode;
	if (mode === "bot") versus.textContent = `🐵 ${state?.user?.login || "Player1"} VS Bot 🤖`;
	else if (mode === "human") {
		versus.textContent = `${state?.user?.login || "Player1"} VS ${state?.user2 || "Player2"}`;
	} else if (mode === "tourn") {
		p1.textContent = `${state?.user?.login.slice(0, 3).toUpperCase()} : 0000${state?.score}`;
		p2.textContent = `${state?.user2.slice(0, 3).toUpperCase()} : 0000${state?.score2}`;
		p3.textContent = `${state?.user3.slice(0, 3).toUpperCase()} : 0000${state?.score3}`;
		if (state.game == 0) versus.textContent = `${state?.user?.login || "Player1"} VS ${state?.user2 || "Player2"}`;
		else if (state.game == 1) versus.textContent = `${state?.user || "Player1"} VS ${state?.user3 || "Player3"}`;
		else if (state.game == 2) versus.textContent = `${state?.user2 || "Player2"} VS ${state?.user3 || "Player3"}`;
	}
}

function goToDash() {
	let stateG = JSON.parse(localStorage.getItem("pongAppState"));
	if (!stateG || !stateG.user || !stateG.mode || !stateG.user.login.length) {
		logOut()
	}
	else {
		window.location.href = `/dashboard/?user=${stateG.user.login}`;
	}
}

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

function initGame() {
	const canvas = document.getElementById("gameCanvas");
	const start = document.getElementById("start");
	const versus = document.getElementById("versus");
	const winner = document.getElementById("gameWin");
	const tournWin1 = document.getElementById("tournWin1");
	const tournWin2 = document.getElementById("tournWin2");
	const tournWin3 = document.getElementById("tournWin3");
	const p1 = document.getElementById("footerP1");
	const p2 = document.getElementById("footerP2");
	const p3 = document.getElementById("footerP3");
	const state = JSON.parse(localStorage.getItem("pongAppState"));
	if (!state || !state.user || !state.mode || !state.user.login.length) {
		logOut();
		return;
	}

	let scoreRight = document.getElementById("gameScoreRight");
	let scoreLeft = document.getElementById("gameScoreLeft");
	let reversed = false;

	let particles = [];
	let isColliding = false;
	let collisionPoint = { x: 0, y: 0 };
	let haloOpacity = 0;
	let paddleCollisionPoint = { x: 0, y: 0 };
	let paddleHaloOpacity = 0;

	const ACCELERATION_INTERVAL = 5000; // Accélération toutes les 5 secondes
	const SPEED_INCREMENT = 1.2; // Facteur d'accélération
	let lastSpeedIncrease = Date.now();

	// so ball is thrown in alternating directions
	let goingRight = Math.random() < 0.5;

	scoreLeft.textContent = 0;
	scoreRight.textContent = 0;
	canvas.style.zIndex = 1;
	winner.textContent = "";
	winner.style.display = "none";
	winner.classList.remove("text");

	function sortWinner(state) {
		const players = [
			{ player: state.user.login, score: state.score },
			{ player: state.user2, score: state.score2 },
			{ player: state.user3, score: state.score3 },
		];
		players.sort((a, b) => b.score - a.score);

		console.log("WINNER", players);
		return players;
	}

	class Particle {
		constructor(x, y) {
			this.x = x;
			this.y = y;
			this.speed = {
				x: (Math.random() - 0.5) * 8,
				y: (Math.random() - 0.5) * 8,
			};
			this.radius = Math.random() * 3;
			this.life = 1;

			const brightness = Math.floor(Math.random() * 256);
			this.color = `rgb(${brightness}, ${brightness}, ${brightness})`;
		}

		update() {
			this.x += this.speed.x;
			this.y += this.speed.y;
			this.life -= 0.02;
		}

		draw(ctx) {
			ctx.beginPath();
			ctx.arc(this.x, this.y, this.radius, 0, Math.PI * 2);
			ctx.fillStyle = this.color.replace(")", `, ${this.life})`);
			ctx.fill();
		}
	}

	if (canvas) {
		const ctx = canvas.getContext("2d");

		// Game settings
		let paddleWidth = 20;
		let paddleHeight = 100;
		let ballSize = 10;
		let paddleSpeed = 5;
		let initialBallSpeed = 7;

		let w = "w";
		let s = "s";
		let up = "ArrowUp";
		let down = "ArrowDown";

		if (state.options.pheight == "0") {
			paddleHeight = 10;
			paddleWidth = 2;
		} else if (state.options.pheight == "25") {
			paddleHeight = 50;
			paddleWidth = 10;
		} else if (state.options.pheight == "50") {
			paddleHeight = 100;
		} else if (state.options.pheight == "75") {
			paddleHeight = 200;
		} else if (state.options.pheight == "100") {
			paddleHeight = 300;
		}

		if (state.options.pspeed == "0") {
			paddleSpeed = 1;
		} else if (state.options.pspeed == "25") {
			paddleSpeed = 3;
		} else if (state.options.pspeed == "50") {
			paddleSpeed = 5;
		} else if (state.options.pspeed == "75") {
			paddleSpeed = 10;
		} else if (state.options.pspeed == "100") {
			paddleSpeed = 20;
		}

		if (state.options.bspeed == "0") {
			initialBallSpeed = 1;
		} else if (state.options.bspeed == "25") {
			initialBallSpeed = 3;
		} else if (state.options.bspeed == "50") {
			initialBallSpeed = 5;
		} else if (state.options.bspeed == "75") {
			initialBallSpeed = 15;
		} else if (state.options.bspeed == "100") {
			initialBallSpeed = 50;
		}

		if (state.options.bsize == "0") {
			ballSize = 1;
		} else if (state.options.bsize == "25") {
			ballSize = 5;
		} else if (state.options.bsize == "50") {
			ballSize = 12;
		} else if (state.options.bsize == "75") {
			ballSize = 30;
		} else if (state.options.bsize == "100") {
			ballSize = 100;
		}

		let player1Y = (canvas.height - paddleHeight) / 2;
		let player2Y = (canvas.height - paddleHeight) / 2;
		let ballX = canvas.width / 2;
		let ballY = canvas.height / 2;
		let ballSpeedX = goingRight ? initialBallSpeed : -initialBallSpeed;
		let ballSpeedY = initialBallSpeed;
		let ballAIX = ballX;
		let ballAIY = ballY;
		let ballSpeedAIY = ballSpeedY;
		let player1Score = 0;
		let player2Score = 0;
		let lastAIUpdate = 0;
		let lastAIReaction = 0;
		const AI_UPDATE_INTERVAL = 1000; // 1 seconde
		const WINNING_SCORE = 5;
		let gameOver = false;

		// Key handling
		let keysPressed = {};

		document.addEventListener("keydown", (event) => {
			// If in bot mode, only allow player 1 controls (w/s) and space
			if (state.mode === "bot") {
				if (event.key === w || event.key === s || event.key === " ") {
					keysPressed[event.key] = true;
				}
			} else {
				// In other modes, allow all controls
				keysPressed[event.key] = true;
			}
		});

		document.addEventListener("keyup", (event) => {
			// Always allow key releases to prevent stuck keys
			delete keysPressed[event.key];
		});

		function drawParticles() {
			for (let i = particles.length - 1; i >= 0; i--) {
				particles[i].update();
				particles[i].draw(ctx);

				if (particles[i].life <= 0) {
					particles.splice(i, 1);
				}
			}
		}

		function drawHalo() {
			if (haloOpacity > 0) {
				ctx.beginPath();
				const gradient = ctx.createRadialGradient(collisionPoint.x, collisionPoint.y, 0, collisionPoint.x, collisionPoint.y, ballSize * 4);
				gradient.addColorStop(0, `rgba(255, 255, 255, ${haloOpacity})`);
				gradient.addColorStop(1, "rgba(255, 255, 255, 0)");
				ctx.fillStyle = gradient;
				ctx.arc(collisionPoint.x, collisionPoint.y, ballSize * 4, 0, Math.PI * 2);
				ctx.fill();
				haloOpacity -= 0.05;
			}

			if (paddleHaloOpacity > 0) {
				ctx.beginPath();
				const paddleGradient = ctx.createRadialGradient(paddleCollisionPoint.x, paddleCollisionPoint.y, 0, paddleCollisionPoint.x, paddleCollisionPoint.y, ballSize * 6);
				paddleGradient.addColorStop(0, `rgba(20, 20, 20, ${paddleHaloOpacity})`);
				paddleGradient.addColorStop(1, "rgba(8, 29, 44, 0)");
				ctx.fillStyle = paddleGradient;
				ctx.arc(paddleCollisionPoint.x, paddleCollisionPoint.y, ballSize * 4, 0, Math.PI * 2);
				ctx.fill();
				paddleHaloOpacity -= 0.05;
			}
		}

		function updateBallSpeed() {
			const currentTime = Date.now();
			if (currentTime - lastSpeedIncrease >= ACCELERATION_INTERVAL) {
				ballSpeedX *= SPEED_INCREMENT;
				ballSpeedY *= SPEED_INCREMENT;
				lastSpeedIncrease = currentTime;
			}
		}

		function updateBallAI() {
			const currentTime = Date.now();
			if (currentTime - lastAIUpdate < AI_UPDATE_INTERVAL) {
				return;
			}
			lastAIUpdate = currentTime;
			ballAIX = ballX;
			ballAIY = ballY;
			ballSpeedAIY = ballSpeedY;
		}

		function updateAI() {
			const humanReaction = Date.now();
			if (humanReaction - lastAIReaction < 400) {
				return;
			}
			lastAIReaction = humanReaction;
			if (ballSpeedX < 0 || ballX < canvas.width / 2) {
				delete keysPressed[up];
				delete keysPressed[down];
				return;
			}

			let predictX = ballAIX;
			let predictY = ballAIY;
			let predictSpeedY = ballSpeedAIY;

			// Add some randomness to the prediction
			const randomError = (Math.random() - 0.5) * canvas.height * 0.15; // 15% random error

			// Calculate if the ball is close to the AI paddle
			const isClose = canvas.width - paddleWidth - predictX < canvas.width * 0.3; // within 30% of canvas width

			// Predict trajectory
			while (predictX < canvas.width - paddleWidth - 20) {
				predictX += ballSpeedX;
				predictY += predictSpeedY;

				if (predictY <= ballSize || predictY >= canvas.height - ballSize) {
					predictSpeedY = -predictSpeedY;
				}
			}

			// Apply error to prediction if ball is far, be more precise when close
			const targetY = isClose ? predictY : predictY + randomError;

			// Add deadzone to prevent shaking, smaller when ball is close
			const deadzone = isClose ? paddleHeight / 8 : paddleHeight / 3;
			const currentCenter = player2Y + paddleHeight / 2;
			const distanceToTarget = targetY - currentCenter;

			if (Math.abs(distanceToTarget) > deadzone) {
				if (distanceToTarget > 0) {
					keysPressed[down] = true;
					delete keysPressed[up];
				} else {
					keysPressed[up] = true;
					delete keysPressed[down];
				}
			} else {
				delete keysPressed[up];
				delete keysPressed[down];
			}
		}

		function gameLoop() {
			if (!gameOver) {
				requestAnimationFrame(gameLoop);
				update();
				if (state.mode === "bot") {
					updateBallAI();
					updateAI();
				}
				draw();
			}
		}

		function update() {
			if (state.options.spacewars) {
				if (keysPressed[" "]) {
					if (reversed) {
						reversed = false;
						w = "w";
						s = "s";
						up = "ArrowUp";
						down = "ArrowDown";
					} else {
						w = "s";
						s = "w";
						up = "ArrowDown";
						down = "ArrowUp";
						reversed = true;
					}
				}
			}

			if (keysPressed[w]) player1Y -= paddleSpeed;
			if (keysPressed[s]) player1Y += paddleSpeed;
			if (state.mode === "bot") {
				// Only use AI-set keys
				if (keysPressed[up]) player2Y -= paddleSpeed;
				if (keysPressed[down]) player2Y += paddleSpeed;
				// Clear any human keyboard input for player 2
				document.addEventListener("keydown", (event) => {
					if (event.key === "ArrowUp" || event.key === "ArrowDown") {
						event.preventDefault();
					}
				});
			} else {
				// Normal player 2 controls
				if (keysPressed[up]) player2Y -= paddleSpeed;
				if (keysPressed[down]) player2Y += paddleSpeed;
			}

			player1Y = Math.max(0, Math.min(player1Y, canvas.height - paddleHeight));
			player2Y = Math.max(0, Math.min(player2Y, canvas.height - paddleHeight));

			updateBallSpeed();

			// Move the ball
			ballX += ballSpeedX;
			ballY += ballSpeedY;

			// Ball collision with walls
			if (ballY < ballSize || ballY > canvas.height - ballSize) {
				ballSpeedY = -ballSpeedY;
				isColliding = true;
				collisionPoint = { x: ballX, y: ballY };
				haloOpacity = 1;
			}

			// Ball collision with paddles
			if (ballX - ballSize < 20 + paddleWidth && ballY > player1Y && ballY < player1Y + paddleHeight) {
				ballX = 20 + paddleWidth + ballSize;
				ballSpeedX = -ballSpeedX;
			}

			if (ballX + ballSize > canvas.width - 20 - paddleWidth && ballY > player2Y && ballY < player2Y + paddleHeight) {
				ballX = canvas.width - 20 - paddleWidth - ballSize;
				ballSpeedX = -ballSpeedX;
			}
			// update scores
			if (ballX < paddleWidth + 10 || ballX > canvas.width - paddleWidth - 10) {
				ballX < paddleWidth + 10 ? player2Score++ : player1Score++;
				ballX < paddleWidth + 10 ? (scoreRight.innerHTML = player2Score) : (scoreLeft.innerHTML = player1Score);

				for (let i = 0; i < 100; i++) {
					particles.push(new Particle(ballX, ballY));
				}

				resetBall();
			}

			if (player1Score >= WINNING_SCORE || player2Score >= WINNING_SCORE) {
				gameOver = true;
				if (state.mode === "tourn") {
					if (state.game == 0) {
						state.game = 1;
						player1Score >= WINNING_SCORE ? state.score++ : state.score2++;
						state.winner = player1Score >= WINNING_SCORE ? state.user.login : state.user2;
						localStorage.setItem("pongAppState", JSON.stringify(state));
						p1.textContent = `${state?.user?.login.slice(0, 3).toUpperCase()} : 0000${state?.score}`;
						p2.textContent = `${state?.user2.slice(0, 3).toUpperCase()} : 0000${state?.score2}`;
						p3.textContent = `${state?.user3.slice(0, 3).toUpperCase()} : 0000${state?.score3}`;
						versus.innerHTML = `${state?.user?.login || "Player1"} VS ${state?.user3 || "Player3"}`;
						winner.textContent = `Winner is ${state.winner}`;
						winner.style.display = "block";
						winner.classList.add("text");
					} else if (state.game == 1) {
						state.game = 2;
						player1Score >= WINNING_SCORE ? state.score++ : state.score3++;
						state.winner = player1Score >= WINNING_SCORE ? state.user.login : state.user3;
						localStorage.setItem("pongAppState", JSON.stringify(state));
						p1.textContent = `${state?.user?.login.slice(0, 3).toUpperCase()} : 0000${state?.score}`;
						p2.textContent = `${state?.user2.slice(0, 3).toUpperCase()} : 0000${state?.score2}`;
						p3.textContent = `${state?.user3.slice(0, 3).toUpperCase()} : 0000${state?.score3}`;
						versus.innerHTML = `${state?.user2 || "Player2"} VS ${state?.user3 || "Player3"}`;
						winner.textContent = `Winner is ${state.winner}`;
						winner.style.display = "block";
						winner.classList.add("text");
					} else if (state.game == 2) {
						scoreLeft.textContent = "";
						scoreRight.textContent = "";
						canvas.style.zIndex = -1;
						player1Score >= WINNING_SCORE ? state.score2++ : state.score3++;
						state.winner = sortWinner(state);
						if (state.winner[0].score == 1) {
							start.removeAttribute("onclick");
							winner.textContent = `😣 No Winners 🥺`;
							winner.style.display = "block";
							winner.classList.add("text");
						} else {
							start.removeAttribute("onclick");
							p1.textContent = "";
							p2.textContent = "";
							p3.textContent = "";

							tournWin1.textContent = `🥇 ${state.winner[0].player.slice(0, 3).toUpperCase()} : 0000${state.winner[0].score} ${state.winner[0].player} 🎉🎊🏆`;
							tournWin2.textContent = `🥈 ${state.winner[1].player.slice(0, 3).toUpperCase()} : 0000${state.winner[1].score} ${state.winner[1].player}`;
							tournWin3.textContent = `🥉 ${state.winner[2].player.slice(0, 3).toUpperCase()} : 0000${state.winner[2].score} ${state.winner[2].player}`;

							setTimeout(() => {
								scoreLeft.textContent = ">>>> HIGH";
								scoreRight.textContent = "SCORES <<<<";
								scoreLeft.style.paddingRight = "0px";
								scoreRight.style.paddingLeft = "0px";
								tournWin1.style.display = "block";
								tournWin1.classList.add("text");
							}, 500);

							setTimeout(() => {
								tournWin2.style.display = "block";
								tournWin2.classList.add("text");
							}, 1500);

							setTimeout(() => {
								tournWin3.style.display = "block";
								tournWin3.classList.add("text");
							}, 2000);
						}
						versus.textContent = "Game Over";
						try {
							// First record to backend
							fetch("/api/dash/", {
								method: "POST",
								credentials: 'include',
								headers: {
									"Content-Type": "application/json",
									"X-CSRFToken": getCookie("csrftoken"),
								},
								body: JSON.stringify({
									stats: {
										user: state.user.login,
										score: state.score,
										user2: state.user2,
										score2: state.score2,
										user3: state.user3,
										score3: state.score3,
										mode: state.mode,
										options: state.options,
									},
								}),
							});
							try {
								blockchainManager.recordTournamentScore(
									state.winner[0].player,
									state.winner[0].score,
									state.winner[1].player,
									state.winner[1].score,
									state.winner[2].player,
									state.winner[2].score
								);
								const tournaments = blockchainManager.getAllTournaments();
							} catch (error) {
								console.error("Failed to record tournament:", error);
							}
						} catch (error) {
							console.error("Error recording tournament results:", error);
						}
						state.game = 0;
						state.score = 0;
						state.score2 = 0;
						state.score3 = 0;
						localStorage.setItem("pongAppState", JSON.stringify(state));
					}
				} else if (state.mode === "human") {
					state.winner = player1Score >= WINNING_SCORE ? state.user.login : state.user2;
					state.score = player1Score;
					state.score2 = player2Score;
					fetch("/api/dash/", {
						method: "POST",
						credentials: 'include',
						headers: {
							"Content-Type": "application/json",
							"X-CSRFToken": getCookie("csrftoken"),
						},
						body: JSON.stringify({
							stats: {
								user: state.user.login,
								score: player1Score,
								user2: state.user2,
								score2: player2Score,
								user3: "none",
								score3: 0,
								mode: state.mode,
								options: state.options,
							},
						}),
					});
					state.score = 0;
					state.score2 = 0;
					localStorage.setItem("pongAppState", JSON.stringify(state));
					winner.textContent = `Winner is ${state.winner}`;
					winner.style.display = "block";
					winner.classList.add("text");
				} else {
					state.winner = player1Score >= WINNING_SCORE ? state.user.login : "Bot";
					fetch("/api/dash/", {
						method: "POST",
						credentials: 'include',
						headers: {
							"Content-Type": "application/json",
							"X-CSRFToken": getCookie("csrftoken"),
						},
						body: JSON.stringify({
							stats: {
								user: state.user.login,
								score: player1Score,
								user2: "none",
								score2: player2Score,
								user3: "none",
								score3: 0,
								mode: state.mode,
								options: state.options,
							},
						}),
					});
					localStorage.setItem("pongAppState", JSON.stringify(state));
					winner.textContent = `Winner is ${state.winner}`;
					winner.style.display = "block";
					winner.classList.add("text");
				}
			}
		}

		// Draw objects on canvas
		function draw() {
			ctx.clearRect(0, 0, canvas.width, canvas.height);

			drawHalo();
			drawParticles();
			// Draw ball
			ctx.fillStyle = "#fff";
			ctx.beginPath();
			ctx.arc(ballX, ballY, ballSize, 0, Math.PI * 2);
			ctx.fill();

			// Draw paddles
			ctx.fillRect(20, player1Y, paddleWidth, paddleHeight);
			ctx.fillRect(canvas.width - 20 - paddleWidth, player2Y, paddleWidth, paddleHeight);
		}

		// Reset ball position and speed
		function resetBall() {
			ballX = canvas.width / 2;
			ballY = canvas.height / 2;
			goingRight = !goingRight;
			ballSpeedX = goingRight ? initialBallSpeed : -initialBallSpeed;
			ballSpeedY = initialBallSpeed;
			lastSpeedIncrease = Date.now();
		}

		// Start the game
		gameLoop();
	}
}
