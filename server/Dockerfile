FROM mhart/alpine-node:12

WORKDIR /app
COPY . .

# If you have native dependencies, you'll need extra tools
# RUN apk add --no-cache make gcc g++ python

RUN npm install

EXPOSE 3000
CMD ["node", "index.js"]