require("@nomicfoundation/hardhat-toolbox");

/** @type import('hardhat/config').HardhatUserConfig */
module.exports = {
  solidity: "0.8.28",
  networks: {
    hardhat: {
      chainId: 1337, // This chainId works with MetaMask
      mining: {
        auto: true,
        interval: 0 // Mine blocks instantly (0) or set a specific interval in milliseconds
      },
	  gas: 2100000,
	  gasPrice: 8000000000
    },
    localhost: {
      url: "http://127.0.0.1:8545",
      chainId: 1337,
	  gas: 2100000,
	  gasPrice: 8000000000
      // Accounts are automatically provided by Hardhat
    }
  },
  paths: {
    artifacts: "./artifacts",
    cache: "./cache",
    sources: "./contracts",
    tests: "./test"
  }
};

/* This configuration:

Keeps your Solidity version at 0.8.28
Sets up two networks:

hardhat: An in-memory blockchain with chainId 1337 (compatible with MetaMask)
localhost: Points to your locally running node, also with chainId 1337

Configures mining behavior to automatically mine transactions
Specifies the standard paths for your project files

With this configuration, you can:

Run npx hardhat node to start a local blockchain
Connect MetaMask to it using:

Network Name: Hardhat Local
RPC URL: http://127.0.0.1:8545
Chain ID: 1337
Currency Symbol: ETH
 */