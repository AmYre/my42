const hre = require("hardhat");
const fs = require('fs');
const path = require('path');

async function main() {
  const TournamentScore = await hre.ethers.getContractFactory("TournamentScore");
  const tournamentScore = await TournamentScore.deploy();
  await tournamentScore.waitForDeployment();
  
  const address = await tournamentScore.getAddress();
  console.log("TournamentScore deployed to:", address);

  // Save contract address to a JSON file
  const contractData = {
    address: address,
    timestamp: new Date().toISOString()
  };

  // Save in both blockchain directory and pong static directory
  const blockchainPath = path.join(__dirname, '../contractAddress.json');
  const staticPath = path.join(__dirname, '../../pong/static/contractAddress.json');
  
  fs.writeFileSync(blockchainPath, JSON.stringify(contractData, null, 2));
  fs.writeFileSync(staticPath, JSON.stringify(contractData, null, 2));
}

main()
  .then(() => process.exit(0))
  .catch((error) => {
    console.error(error);
    process.exit(1);
  });