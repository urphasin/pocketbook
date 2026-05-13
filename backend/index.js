const express = require("express");

const app = express();

app.use(express.json());

app.post("/webhook", (req, res) => {
  console.log("Webhook Received");
  
  console.log(req.body);

  res.sendStatus(200);
});

app.listen(3000, () => {
  console.log("Server running on port 3000");
})