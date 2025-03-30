FROM node:18

WORKDIR /app/blockchain

COPY blockchain/package*.json ./

RUN npm install --yes && npm install --save-dev --yes hardhat

COPY blockchain/. .

RUN chmod +x ./scripts/entrypoint.sh

EXPOSE 8545

CMD ["sh", "-c", "echo 'Blockchain container started' && ./scripts/entrypoint.sh"]