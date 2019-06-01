FROM debian:stretch 

EXPOSE 8000

WORKDIR /opt/app


RUN apt-get update \
  && apt-get -y install curl build-essential git \
  && curl -sL https://deb.nodesource.com/setup_12.x | bash - \
  && apt-get install -y nodejs

RUN npm install -g yarn --unsafe-perm --verbose

RUN yarn global add reason-cli@latest-linux bs-platform rtop --verbose

COPY package.json .
COPY yarn.lock .

RUN yarn

COPY bsconfig.json .
COPY src ./src
COPY webpack.config.js .


RUN yarn build

CMD ["yarn", "server:webpack"]
