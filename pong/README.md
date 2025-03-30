# ft_TRANSCENDENCE

## Prérequis

-   Docker
-   Docker Compose


## Start the app :
```bash
make
```

## To have a look to the DB :
```bash
make admin
```

## To stop without clearing DB :
```bash
make stop
```

## To quit :
```bash
make fclean
```

## What is expected from the app :
- Single Page Application
- Keep the navigation working (state/url#/pushState/ReplaceState)
- Docker containerized
- Protect against SQLinjections & XSS
- Protect routes

## What is expected from the game :
- Same rules and speed for both players
- Same keyboard for both players
- Host a Tournament - At least 3 players
- Original pong design
- Display winner, tournament score and user stats

## Our major modules :
- Use DJANGO to build the backend.
- Introduce an AI Opponent.
- Store the score of a tournament in the Blockchain.
- OAuth  42Auth.

## Our minor modules :
- Game Customization Options
- Multilang
- Server Side Rendering | SSR
- User and Game Stats Dashboards
- Expanding Browser Compatibility
- Use a database for the backend - and more