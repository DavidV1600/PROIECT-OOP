# Sports Competition Creation Application

## What it does?
The project allows the user to create different types of tournaments with teams consisting of either chess or tennis players.

After the tournament is created it simulates the rounds based on the match results that the user inputed, and after finishing all the rounds it displays the final standings. 

After every match based on the difference in skill of the players and the results between them their ELO (chess standard pointing system) or ATP rankings (tennis standard positioning system) is updated


## Principal Classes:
### -Player, ChessPlayer, TennisPlayer, ChessTennisPlayer:
These classes represent a person, a team member, and store their personal data (CNP, name, surname, etc.).

They are capable of reading and displaying the player's data.

### -Team:
Represents a team, formed by multiple players, and has member variables (team name, players, team's ELO, number of players).

It is capable of reading a team and its members, calculating the average ELO of its players (which becomes the team's ELO), and displaying them.

### -Match, ChessMatch, TennisMatch:
Represents a match played between two teams, with a score and a final result that decides the winner.

It is capable of displaying the score of both teams and the match winner.


### -Round:
It is a round of the tournament, formed by a list of matches, keeping track of the current round number and the number of matches played.

It is capable of displaying a list of all played matches and their results.


### -Tournament, ChessTournament, TennisTournament:
This is the main class with its subclasses, formed by a list of participating teams, a list of rounds, the number of rounds, an entry fee per team, the tournament's name, and the prize fund.

It is capable of reading all the participating teams in the tournament and the rest of the class member data, and displaying them.


### -PlayerHistory, ChessPlayerHistory, TennisPlayerHistory:
It is capable of keeping track of a player's ELO history or ATP rankings, depending on the player's type, and recording their opponents.


### -Prize, ChessPrize, TennisPrize:
This is an interface responsible for prizes, with its subclasses, which keep track of the number of prizes awarded at the tournament, how many people have received prizes, and a list of all given prizes.
