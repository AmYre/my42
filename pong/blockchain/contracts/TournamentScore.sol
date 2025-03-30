// SPDX-License-Identifier: MIT
pragma solidity ^0.8.28;

contract TournamentScore {
    struct Tournament {
        string winner;
        string winnerScore;  // Changed to string to match function parameters
        string secondPlace;
        string secondScore;  // Changed to string
        string thirdPlace;
        string thirdScore;   // Changed to string
        uint256 timestamp;
    }

    Tournament[] public tournaments;
    
    function recordTournament(
        string memory _winner,
        string memory _winnerScore,  // Changed to string memory
        string memory _secondPlace,
        string memory _secondScore,   // Changed to string memory
        string memory _thirdPlace,
        string memory _thirdScore     // Changed to string memory
    ) public {
        tournaments.push(Tournament(
            _winner,
            _winnerScore,
            _secondPlace,
            _secondScore,
            _thirdPlace,
            _thirdScore,
            block.timestamp
        ));
    }

    function getTournamentCount() public view returns (uint256) {
        return tournaments.length;
    }

    function getTournament(uint256 index) public view returns (
        string memory,
        string memory,  // Changed return type to string
        string memory,
        string memory,  // Changed return type to string
        string memory,
        string memory,  // Changed return type to string
        uint256
    ) {
        Tournament memory t = tournaments[index];
        return (
            t.winner,
            t.winnerScore,
            t.secondPlace,
            t.secondScore,
            t.thirdPlace,
            t.thirdScore,
            t.timestamp
        );
    }
}