var express = require("express");
var app = express();

//Define request response in root URL (/)
app.get("/", function(req, res) {
  res.send("Esse é um retorno de uma chamada GET");
});

app.put("/", function(req, res) {
  res.send("Esse é um retorno de uma chamada PUT");
});

app.post("/", function(req, res) {
  res.send("Esse é um retorno de uma chamada POST");
});

app.head("/", function(req, res) {
  res.send("Esse é um retorno de uma chamada HEAD");
});

//Launch listening server on port 8081
app.listen(8081, function() {
  console.log("app listening on port 8081!");
});
