var express = require("express");
var bodyParser = require("body-parser");
var formatBufferAsJson = require("./helpers/format_buffer_as_json");

var app = express();

var options = {
  inflate: true,
  limit: "100kb",
  type: "application/octet-stream"
};
app.use(bodyParser.raw(options));

//Define request response in root URL (/)
app.get("/", function(req, res) {
  res.send("Esse é um retorno de uma chamada GET");
});

app.put("/", function(req, res) {
  let jsonmsg = formatBufferAsJson(req.body);
  res.send(jsonmsg);
});

app.post("/", function(req, res) {
  let jsonmsg = formatBufferAsJson(req.body);
  console.log(jsonmsg);
  res.send(jsonmsg);
});

app.head("/", function(req, res) {
  res.send("Esse é um retorno de uma chamada HEAD");
});

//Launch listening server on port 3000
app.listen(3000, function() {
  console.log("app listening on port 3000!");
});
