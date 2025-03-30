document.addEventListener("DOMContentLoaded", function () {
	// ################### PIE CHART ###################
	var ctxPie = document.getElementById("pieChart").getContext("2d");

	let statsBot = document.getElementById("statsBot").value;
	let statsHuman = document.getElementById("statsHuman").value;
	let statsTourn = document.getElementById("statsTourn").value;

	var pieChart = new Chart(ctxPie, {
		type: "pie",
		data: {
			labels: ["Bot", "Human", "Tournament"],
			datasets: [
				{
					backgroundColor: ["white", "grey", "black"],
					data: [statsBot, statsHuman, statsTourn],
				},
			],
		},
		options: {
			plugins: {
				legend: {
					labels: {
						font: {
							size: 58,
							family: "'Press Start 2P', cursive",
							weight: "bold",
						},
						color: "white",
						boxWidth: 40,
						boxHeight: 40,
					},
				},
			},
		},
	});
	// ################### BAR CHART ###################

	setTimeout(function start() {
		$(".bar").each(function (i) {
			var $bar = $(this);
			$(this).append('<span class="count"></span>');
			setTimeout(function () {
				$bar.css("min-width", 140);
				$bar.css("width", $bar.attr("data-percent"));
			}, i * 100);
		});

		$(".count").each(function () {
			$(this)
				.prop("Counter", 0)
				.animate(
					{
						Counter: $(this).parent(".bar").attr("data-percent"),
					},
					{
						duration: 2000,
						easing: "swing",
						step: function (now) {
							$(this).text(Math.ceil(now) + "%");
						},
					}
				);
		});
	}, 500);

	// ################### BALLS PHYSICS ###################
	let statsTotal = document.getElementById("statsTotal").value;
	class PhysicsBallContainer {
		constructor(containerId, numGames) {
			// Matter.js module aliases
			this.Engine = Matter.Engine;
			this.Runner = Matter.Runner;
			this.Render = Matter.Render;
			this.World = Matter.World;
			this.Bodies = Matter.Bodies;

			// Create engine and world
			this.engine = this.Engine.create();
			this.world = this.engine.world;
			this.runner = this.Runner.create();

			// Container dimensions
			this.width = 100;
			this.height = 200;
			this.wallThickness = 8;

			// Ball properties
			this.ballRadius = 10;
			this.ballSpawnDelay = 500; // ms between ball spawns
			this.totalBalls = numGames;
			this.spawnedBalls = 0;

			// Setup renderer
			this.render = this.Render.create({
				element: document.getElementById(containerId),
				engine: this.engine,
				options: {
					width: this.width,
					height: this.height,
					wireframes: false,
					background: "transparent",
					pixelRatio: window.devicePixelRatio,
				},
			});

			// Create container walls
			this.createWalls();

			// Start physics engine and renderer
			this.Runner.run(this.runner, this.engine);
			this.Render.run(this.render);

			// Start spawning balls
			this.spawnInterval = setInterval(() => this.spawnBall(), this.ballSpawnDelay);
		}

		createWalls() {
			const walls = [
				// Bottom
				this.Bodies.rectangle(this.width / 2, this.height - this.wallThickness / 2, this.width, this.wallThickness, { isStatic: true }),
				// Left
				this.Bodies.rectangle(this.wallThickness / 2, this.height / 2, this.wallThickness, this.height, { isStatic: true }),
				// Right
				this.Bodies.rectangle(this.width - this.wallThickness / 2, this.height / 2, this.wallThickness, this.height, { isStatic: true }),
			];

			// Set wall appearance
			walls.forEach((wall) => {
				wall.render.fillStyle = "#808080";
				wall.friction = 0.2;
				wall.restitution = 0.4;
			});

			this.World.add(this.world, walls);
		}

		spawnBall() {
			if (this.spawnedBalls >= this.totalBalls) {
				clearInterval(this.spawnInterval);
				return;
			}

			// Create ball with physics properties
			const ball = this.Bodies.circle(this.width / 2, this.ballRadius * 2, this.ballRadius, {
				restitution: 0.4, // Bounciness
				friction: 0.1, // Surface friction
				density: 0.001, // Mass/weight
				render: {
					fillStyle: "#fff",
				},
			});

			// Add small random horizontal velocity for more interesting motion
			const randomVelocity = (Math.random() - 0.5) * 2;
			Matter.Body.setVelocity(ball, { x: randomVelocity, y: 0 });

			this.World.add(this.world, ball);
			this.spawnedBalls++;
		}

		cleanup() {
			// Stop the physics engine and renderer
			this.Runner.stop(this.runner);
			this.Engine.clear(this.engine);
			this.Render.stop(this.render);
			clearInterval(this.spawnInterval);
		}
	}

	// Usage:
	function initPhysicsBallAnimation(containerId, numGames) {
		// Create a div container for the canvas
		const container = document.getElementById(containerId);
		container.innerHTML = ""; // Clear any existing content

		// Create and return the physics simulation
		return new PhysicsBallContainer(containerId, numGames);
	}

	initPhysicsBallAnimation("balls", statsTotal);

	// ################### RADAR OPTIONS ###################
	const ctxRadar = document.getElementById("radarChart").getContext("2d");

	const statSpeed = document.getElementById("statsSpeed").value;
	const statAttack = document.getElementById("statsAttack").value;
	const statDefense = document.getElementById("statsDefense").value;
	const statWar = document.getElementById("statsWar").value;
	const statAccuracy = document.getElementById("statsAccuracy").value;
	const statMadness = document.getElementById("statsMadness").value;

	// Create the radar chart
	new Chart(ctxRadar, {
		type: "radar",
		data: {
			labels: ["Speed", "Attack", "Defense", "War", "Accuracy", "Madness"],
			datasets: [
				{
					data: [statSpeed, statAttack, statDefense, statWar, statAccuracy, statMadness],
					fill: true,
					backgroundColor: "rgba(255, 255, 255, 0.2)",
					borderColor: "rgb(255, 255, 255)",
					pointBackgroundColor: "rgb(255, 255, 255)",
					pointBorderColor: "#fff",
					pointHoverBackgroundColor: "#fff",
					pointHoverBorderColor: "rgb(255, 255, 255)",
				},
			],
		},
		options: {
			plugins: {
				legend: {
					display: false,
				},
			},
			elements: {
				line: {
					borderWidth: 6,
				},
			},
			scales: {
				r: {
					angleLines: {
						display: true,
						color: "rgb(255, 255, 255)",
					},
					suggestedMin: 0,
					suggestedMax: 100,
					ticks: {
						font: {
							size: 0,
						},
						stepSize: 20,
					},
					grid: {
						display: true,
						color: "rgba(255, 255, 255, 0.3)",
						circular: false,
					},
					pointLabels: {
						font: {
							size: 20,
							family: "'Press Start 2P', cursive",
							color: "rgb(255, 255, 255)",
							weight: "bold",
						},
						color: "rgb(255, 255, 255)",
					},
				},
			},
		},
	});
});
