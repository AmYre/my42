#!/bin/bash
set -e

echo "Starting blockchain services..."

# Ne pas installer hardhat globalement, utiliser l'installation locale
echo "Checking Hardhat installation..."
npm list hardhat || npm install --save-dev hardhat

# Compilation des contrats
echo "Compiling contracts..."
npx --yes hardhat compile

# Démarrage du nœud Hardhat
echo "Starting Hardhat node..."
npx --yes hardhat node &
NODE_PID=$!

# Attendre que le nœud démarre
echo "Waiting for Hardhat node to start..."
sleep 5

# Déployer les contrats
echo "Deploying contracts..."
npx --yes hardhat run --network localhost scripts/deploy.js

echo "Blockchain setup complete"
tail -f /dev/null